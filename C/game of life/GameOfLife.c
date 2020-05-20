#pragma once
#include "General.h"

//-------------------------------------------------------------------------------------------------
//                                    Function CountNeighbors
//                                    -----------------------
//
// General    : The function simply counts the "neighbors" of the row and col given.
//              neighbor means the eight surrounding the row and col given for an example:
//              - - -
//              - + -
//              - - - the "-" are the neighbors.
//
// Parameter  : A pointer for the sparce matrix A pointer for the temp matrix that counts neighbors
//              in every place. An int for the row and for the col and a the width of the matrix.
//
// Return     : The amount of neighbors.
//          
//-------------------------------------------------------------------------------------------------
int CountNeighbors(sparceMatNodePtr manager,int*neighborsMat, int row, int col,int width)
{
	// Variable definition
	sparceMatNodePtr above;
	sparceMatNodePtr before;
	int i;
	int j;
	unsigned short counter = ZERO;

	// Go on around the creature to find neigbors for him
	for (i = -ONE; TWO - i; i++)
	{
		for (j = -ONE; TWO - j; j++)
		{
			above=findAbove(&manager, row + i, col + j);
			before=findBefore(&manager, row + i, col + j);
			// If he has neibors count them
			counter = ((above->bottom == before->next) * !((!i) * (!j)) * (above->bottom->col != -ONE) * (above->bottom->row != -ONE)) ? ++counter : counter;
		}
	}
	*(neighborsMat + (row * width) + col) = counter;
	return counter;
}

//-------------------------------------------------------------------------------------------------
//                                    Function checkNeighbors
//                                    -----------------------
//
// General    : The function take cares of the regular game of life. she checks if the place given
//              is alive, if it is "dead" it checks if he has less than two neighbors. if he do it
//              "revives" him. if the place given is "alive" then it checks 2 things: if his neighbors
//              are more than 3 it kills him, if they are less than 2 it kills him aswell.
//              while adding or removing a place it changes the pointer of the "living creatures".
//
// Parameter  : A pointer for the sparce matrix an int for the neighbors,
//              An int for the row and for the col and a the pointer for the living creatures.
//
// Return     : Nothing.
//          
//-------------------------------------------------------------------------------------------------
void checkNeighbors(sparceMatNodePtr manager,int neighbors,int row,int col,int*livingCreatures)
{
	// Variable definition
	sparceMatNodePtr above;
	sparceMatNodePtr before;
	above=findAbove(&manager, row, col);
	before=findBefore(&manager, row, col);
	int temp = ONE;

	// Check if a creature does not exist and has more then two neighbors
	if ((above->bottom != before->next) * (neighbors>TWO))
	{
		AddItem(manager, row, col);
		(*livingCreatures)++;
	}

	// Check if a creature exist and has more then three or less then two neigbors
	if ((above->bottom == before->next) * ((neighbors < TWO) + (neighbors > THREE)))
	{
		RemoveItem(manager, row, col);
		(*livingCreatures)--;
	}
}

//-------------------------------------------------------------------------------------------------
//                                    Function ChangeWorld
//                                    --------------------
//
// General    : The function take cares of both of the functions "checkNeighbors" and "CountNeighbors".
//              it runs for the whole board and calls the function to count first of all the neighbors
//              and after that it runs the whole board again and checks if to kill or revive them.
//
// Parameter  : A pointer for the sparce matrix A pointer for the temp matrix that counts neighbors
//              in every place. An int for the height and for the width and a the pointer for the living
//              creatures.
//
// Return     : Nothing.
//          
//-------------------------------------------------------------------------------------------------
void ChangeWorld(sparceMatNodePtr manager,int*neighborsMat,int h,int w,int*livingCreatues)
{
	// Variable definition
	unsigned short i;
	int loopLength = h * w;
	int neighbors;

	// Count the neigbors of all the places
	for(i = ZERO; i < loopLength; i++)
	{
		CountNeighbors(manager, neighborsMat, i / w, i % w,w);
	}

	// Upade the living creatures depends on the neigbors
	for (i = ZERO; i < loopLength; i++)
	{
		checkNeighbors(manager, *(neighborsMat + ((i / w) * w) + (i % w)),i/w,i%w, livingCreatues);
	}
}

//-------------------------------------------------------------------------------------------------
//                                    Function Earthquake
//                                    -------------------
//
// General    : The function deletes 10% of the rows and cols while killing every single place in there.
//
// Parameter  : A pointer for the sparce matrix A pointer for the temp matrix that counts neighbors
//              in every place. A pointer for the height and for the width a the pointer for the living
//              creatures and a pointer for the total possible creatures.
//
// Return     : Nothing.
//          
//-------------------------------------------------------------------------------------------------
void Earthquake(sparceMatNodePtr* manager, int* neighborsMat, int* h, int* w, int* livingCreatures,int*totalPossibleCreatures)
{
	// Variable definition
	int totalDeleted=ZERO;
	int lengthLoop = (*h) / TEN;
	int i;

	// Delete the amount that is needed
	for (i = ZERO; i < lengthLoop; i++)
	{
		totalDeleted+=DeleteRow(manager, (*h)-ONE, h);
		totalDeleted+=DeleteCol(manager, (*w)-ONE, w);
	}

	// Change to the new size, including the total creatures
	neighborsMat = (int*)(realloc(neighborsMat,sizeof(int)*(*(h) * (*w))));
	*totalPossibleCreatures = (*h) * (*w);
	*livingCreatures -= totalDeleted;
}

//-------------------------------------------------------------------------------------------------
//                                    Function OceanRetreat
//                                    ---------------------
//
// General    : The function adds 5% to the rows and cols.
//
// Parameter  : A pointer for the sparce matrix A pointer for the temp matrix that counts neighbors
//              in every place. A pointer for the height and for the width and a pointer for the 
//              total possible creatures.
//
// Return     : Nothing.
//          
//-------------------------------------------------------------------------------------------------
void OceanRetreat(sparceMatNodePtr* manager, int* neighborsMat, int* h, int* w, int* totalPossibleCreatures)
{
	// Variable definition
	int lengthLoop = (*h) / (TEN*TWO);
	int i;

	// Add the amount that is needed
	for (i = ZERO; i < lengthLoop; i++)
	{
		AddRowSparce(manager, h);
		AddColSparce(manager, w);

	}

	// Change to the new size, including the total creatures
	neighborsMat = (int*)(realloc(neighborsMat, sizeof(int) * (*(h) * (*w))));
	*totalPossibleCreatures = (*h) * (*w);
}

//-------------------------------------------------------------------------------------------------
//                                    Function Epidemic
//                                    -----------------
//
// General    : The function deletes 15% of the rows while killing every single place in there.
//
// Parameter  : A pointer for the sparce matrix A pointer for the temp matrix that counts neighbors
//              in every place. A pointer for the height and for the width a the pointer for the living
//              creatures and a pointer for the total possible creatures.
//
// Return     : Nothing.
//          
//-------------------------------------------------------------------------------------------------
void Epidemic(sparceMatNodePtr* manager, int* neighborsMat, int* h, int* w, int* livingCreatures, int* totalPossibleCreatures)
{
	// Variable definition
	int totalDeleted = ZERO;
	int lengthLoop = (*h) * FIVETEEN / ONE_HUNDRED;
	int i;

	// Delete the amount that is needed
	for (i = ZERO; i < lengthLoop; i++)
	{
		totalDeleted += DeleteRow(manager, (*h) - ONE, h);
	}

	// Change to the new size, including the total creatures
	neighborsMat = (int*)(realloc(neighborsMat, sizeof(int) * (*(h) * (*w))));
	*totalPossibleCreatures = (*h) * (*w);
	*livingCreatures -= totalDeleted;
}

//-------------------------------------------------------------------------------------------------
//                                    Function LakeDrying
//                                    -------------------
//
// General    : The function adds 15% to the cols.
//
// Parameter  : A pointer for the sparce matrix A pointer for the temp matrix that counts neighbors
//              in every place. A pointer for the height and for the width and a pointer for the 
//              total possible creatures.
//
// Return     : Nothing.
//          
//-------------------------------------------------------------------------------------------------
void LakeDrying(sparceMatNodePtr* manager, int* neighborsMat, int* h, int* w, int* totalPossibleCreatures)
{
	// Variable definition
	int lengthLoop = (*h) * FIVETEEN / ONE_HUNDRED;
	int i;

	// Add the amount that is needed
	for (i = ZERO; lengthLoop - i; i++)
	{
		AddColSparce(manager, w);
	}

	// Change to the new size, including the total creatures
	neighborsMat = (int*)(realloc(neighborsMat, sizeof(int) * (*(h) * (*w))));
	*totalPossibleCreatures = (*h) * (*w);
}

//-------------------------------------------------------------------------------------------------
//                                        Game Of Life
//                                        ------------
//
// General : Take cares of a program like Game Of Life with a little changes. game of life is a game
//           where the game starts for some amount of generations given and it runs and change 
//           some places to dead and some to alive depends on their neighbors amount. the changes are :
//           that you have 4 things that may happen : earthquake(that deletes 10% of rows and cols)
//           ,OceanRetreat (adds 5% to the rows and cols), Epidemic (deletes 15% of rows)
//           and lake drying (adds 15% of cols). earthquake will happen when there are more than 50%
//           of living pepole, ocean retreat when there are less than 20 lake drying when exactly 40%
//           and epidemic when exactly 30%.
//           
// Input   : how many generations. 
//
// Process : The program creates a matrix inits her in order to reset her.  it makes a constant
//           start that can be changed just for the checking. then it takes input from the user "how
//           many generations" and it makes a loop for the generation long given. than it checks if theres
//           any of the scenerios if there is it calls the function needed (depends on the amount of
//           living pepole),than it calls the function change world that changes the world through some
//           parameters that are being told in the functions "CheckWorld" and "CountNeighbors".
//           at last it prints the Matrix of the pepole and than go back to the loop as long as it needs.
//           (depends on the generation times).
//           "GetBombs" in order to put the bombs, After that we start a while that if a BOOL type
//            variable called "stop" will be false the while will stop. (if youve lost or win the while
//            will stop) and a currect print will be on the screen. and in the while we call a function
//            called getGuess that take cares to the inputs and outputs.
//          
// Output  : the matrixes changes. for each generation it prints the generation.
//
//-------------------------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 27.12.2019
//-------------------------------------------------------------------------------------------------
void main(void)
{
	// Variable definition
	int LivingCreatures=ZERO;
	int totalPossibleCreatures;
	sparceMatNode* manager;
	int* neighborsMatrix = NULL;
	int height = ZERO;
	int width = ZERO;
	unsigned short i;
	int generationLength;

	// Init the sparce matrix
	initSparce(&manager);

	// Add the rows and colums for the initial boared size
	for (i = ZERO; i < BOARED_SIZE; i++)
	{
		AddRowSparce(&manager, &height);
		AddColSparce(&manager, &width);
	}

	totalPossibleCreatures = height * width;
	neighborsMatrix = (int*)malloc(sizeof(int)*(height * width));

	// Just a constant start matrix that can be changed.
	for (i = ZERO; i < totalPossibleCreatures; i+=TWO)
	{
		AddItem(manager, i/width, i%width);
		LivingCreatures++;
	}
	AddItem(manager, ZERO, ONE);
	LivingCreatures++;
	PrintSparce(manager, height, width);

	printf("enter an amount of times for the generations to keep going \n");
	scanf("%d", &generationLength);

	// Going the amount of time that was given
	for (i = ZERO; i < generationLength; i++)
	{
		// Check changes in the map depends on the amount
		if (TWO * (LivingCreatures) > (totalPossibleCreatures))
		{
			Earthquake(&manager, neighborsMatrix, &height, &width, &LivingCreatures, &totalPossibleCreatures);
		}
		if (LivingCreatures < totalPossibleCreatures / FIVE)
		{
			OceanRetreat(&manager, neighborsMatrix, &height, &width, &totalPossibleCreatures);
		}
		if (LivingCreatures == totalPossibleCreatures * THREE / TEN)
		{
			Epidemic(&manager, neighborsMatrix, &height, &width, &LivingCreatures, &totalPossibleCreatures);
		}
		if (LivingCreatures == totalPossibleCreatures * FOUR / TEN)
		{
			LakeDrying(&manager, neighborsMatrix, &height, &width, &totalPossibleCreatures);
		}

		// Change the living creatures
		ChangeWorld(manager, neighborsMatrix, height, width,&LivingCreatures);
		PrintSparce(manager, height, width);
		printf("\n \n \n");
	}
}