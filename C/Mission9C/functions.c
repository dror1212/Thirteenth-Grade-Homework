#pragma once

#include "General.h"

//---------------------------------------------------------------------------------------
// 												In Diagonal
// 											---------------
//
// General 		: The function checks which numbers are in the diagonal and change 
//				  the array counter according to this.
//
// Parameters 	: array 		- the array that contain the numbers.
//				  size 			- the size of the array.
//				  array_counter - the array that beeing changed.
//				  incline		- the change in the counter.
//				  startingX		- where to start.
//
// Return Value : None
//
//---------------------------------------------------------------------------------------
// Programer 	: Dror Tal
// Student		: 322534793
// Date 		: 1.11.2019
//---------------------------------------------------------------------------------------
void InDiagonal(unsigned short mat[][THREE], unsigned short size, short incline, unsigned short array_counter[], unsigned short starting_x)
{
	unsigned short counter;
	for (counter = ZERO; size >= ABS(incline); size -= ABS(incline), starting_x += incline, counter++)
	{
		array_counter[mat[counter][starting_x]]++;
	}
}

//---------------------------------------------------------------------------------------
//                                          In Row
//                                          ------
//
// General      : The function checks which numbers are in this row and increase 
//                the array counter according to this.
//
// Parameters   : array         - the array that contain the numbers.
//                size          - the size of the array.
//                array_counter - the array that beeing changed.
//
// Return Value : None
//
//---------------------------------------------------------------------------------------
// Programer    : Dror Tal
// Student      : 322534793
// Date         : 1.11.2019
//---------------------------------------------------------------------------------------
void InRow(unsigned short array[], unsigned short size, unsigned short array_counter[])
{
	unsigned short counter;
	for (counter = ZERO; counter < size; counter++)
	{
		array_counter[array[counter]]++;
	}
}

//---------------------------------------------------------------------------------------
//                                          In Col
//                                          ------
//
// General      : The function checks which numbers are in this column and increase 
//                the array counter according to this.
//
// Parameters   : matrix        - the matrix that contain the numbers.
//                col           - the column that beeing checked on the matrix.
//                array_counter - the array that beeing changed.
//
// Return Value : None
//
//---------------------------------------------------------------------------------------
// Programer    : Dror Tal
// Student      : 322534793
// Date         : 1.11.2019
//---------------------------------------------------------------------------------------
void InCol(unsigned short mat[][THREE], unsigned short col, unsigned short size, unsigned short array_counter[])
{
	unsigned short counter;
	for (counter = 0; counter < size; counter++)
	{
		array_counter[mat[counter][col]]++;
	}
}

//---------------------------------------------------------------------------------------
// 										Clear Array
// 										-----------
//
// General 		: The function changing the value to 0, for few positions in the array.
//
// Parameters 	: array 			- the array that being changed.
//				  size_of_array 	- how many values change to zero.
//
// Return Value : None
//
//---------------------------------------------------------------------------------------
// Programer 	: Dror Tal
// Student		: 322534793
// Date 		: 1.11.2019
//---------------------------------------------------------------------------------------
void Clear_Array(unsigned short array[], unsigned short size_of_array)
{
	//definding variable.
	unsigned short counter;

	//run on the array values.
	for (counter = ZERO; counter < size_of_array; counter++)
	{
		//change the value in position counter to 0.
		array[counter] = ZERO;
	}

}

//---------------------------------------------------------------------------------------
// 										Digit In Array
// 										--------------
//
// General 		: The function checks if the digit is in the array.
//
// Parameters 	: Array 	- the array that being checked.
//				  digit 	- the digit that being checked.
//
// Return Value : 0 - the digit isn't in the array.
//				  1 - the digit is in the array.
//
//---------------------------------------------------------------------------------------
// Programer 	: Dror Tal
// Student		: 322534793
// Date 		: 1.11.2019
//---------------------------------------------------------------------------------------
unsigned short DigitInArray(unsigned short Array[], unsigned short digit, unsigned short size)
{
	//definding variables.
	unsigned short counter;
	unsigned short result;
	unsigned short end_of_array;

	result = ZERO;
	counter = ZERO;
	end_of_array = ZERO;
	//run in the loop until the counter is equal to 4 or if result is 1.
	for (counter = ZERO; counter < size; counter++)
	{
		//if the value in array in position counter is equal to the digit
		//increase the variable result. else do nothing.
		(Array[counter] >= digit) ? result++ : result;
	}

	return (result);
}

//---------------------------------------------------------------------------------------
// 											Sum
// 										   -----
//
// General 		: The function adding the values from the array to variable.
//
// Parameters 	: array_counter - the array that contain the numbers.
//				  size			- how many values needed to be add.
//
// Return Value : the result of the adding.
//
//---------------------------------------------------------------------------------------
// Programer 	: Dror Tal
// Student		: 322534793
// Date 		: 1.11.2019
//---------------------------------------------------------------------------------------
unsigned short SumOfVecCounter(unsigned short array_counter[], unsigned short size)
{
	unsigned short counter = ZERO;
	unsigned short sum = ZERO;
	for (; counter < size; counter++)
	{
		sum += (counter + ONE) * array_counter[counter];
	}

	return (sum);
}

//---------------------------------------------------------------------------------------
// 										Display Game
// 										------------
//
// General 		: The function prints the board of the game.
//
// Parameters 	: mat 	- the matrix that being printed.
//				  size 	- the size of the matrix.
//
// Return Value : None
//
//---------------------------------------------------------------------------------------
// Programer 	: Dror Tal
// Student		: 322534793
// Date 		: 1.11.2019
//---------------------------------------------------------------------------------------
void DisplayGame(unsigned short mat[][THREE], unsigned short size)
{
	unsigned short counter;
	char sign;
	unsigned short max = size * size;
	for (counter = ZERO; counter < max; counter++)
	{
		sign = (mat[counter / THREE][counter % THREE] == ONE) ? 'X' : ' ';
		sign = (mat[counter / THREE][counter % THREE] == TWO) ? 'O' : sign;

		printf(" %c |", sign);
		(counter % THREE == TWO) ? printf("\n") : ZERO;
	}
}


//---------------------------------------------------------------------------------------
// 											Win
// 										  -------
//
// General 		: The function checks if the player won.
//
// Parameters 	: array_counter		- the array that you check the info in.
//				  turn 				- where do you need to check.
//
// Return Value : whether he won or not.
//
//---------------------------------------------------------------------------------------
// Programer 	: Dror Tal
// Student		: 322534793
// Date 		: 1.11.2019
//---------------------------------------------------------------------------------------
unsigned short win(unsigned short array_counter[], unsigned short turn)
{
	return (array_counter[turn + ONE] >= THREE);
}

//---------------------------------------------------------------------------------------
// 											play
// 										  --------
//
// General 		: The function checks if the player won in any way.
//
// Parameters 	: mat	    - the matrix where you take the info from.
//				  turn 		- where do you need to check.
//
// Return Value : whether he won or not.
//
//---------------------------------------------------------------------------------------
// Programer 	: Dror Tal
// Student		: 322534793
// Date 		: 1.11.2019
//---------------------------------------------------------------------------------------
unsigned short play(unsigned short turn, unsigned short mat[][THREE])
{
	// Variable definition
	unsigned short counter = ZERO;
	unsigned short array_counter[THREE] = { ZERO };
	unsigned short result = ZERO;

	// Go on all the cols and rows
	for (; counter < THREE; counter++)
	{

		// Check if there are three that are the same in a row
		InRow(mat[counter], THREE, array_counter);
		result = win(array_counter, turn) ? ONE : result;
		Clear_Array(array_counter, THREE);

		// Check if there are three that are the same in a col
		InCol(mat, counter, THREE, array_counter);
		result = win(array_counter, turn) ? ONE : result;
		Clear_Array(array_counter, THREE);
	}

	// Check if there are three that are the same in a diagonal
	InDiagonal(mat, THREE, ONE, array_counter, ZERO);
	result = win(array_counter, turn) ? ONE : result;
	Clear_Array(array_counter, THREE);

	// Check if there are three that are the same in the other diagonal
	InDiagonal(mat, THREE, -ONE, array_counter, TWO);
	result = win(array_counter, turn) ? ONE : result;
	Clear_Array(array_counter, THREE);

	return (result);
}

//---------------------------------------------------------------------------------------
// 										Print Matrix
// 										------------
//
// General 		: The function prints the matrix.
//
// Parameters 	: mat 	- the matrix that being printed.
//				  size 	- the size of the matrix.
//
// Return Value : None
//
//---------------------------------------------------------------------------------------
// Programer 	: Dror Tal
// Student		: 322534793
// Date 		: 1.11.2019
//---------------------------------------------------------------------------------------
void PrintMatrix(char mat[][N], unsigned short size)
{
	unsigned short counter;
	for (counter = ZERO; counter < size * size; counter++)
	{
		printf("%3c", mat[counter / size][counter % size]);
		(counter % size == size - ONE) ? printf("\n") : ZERO;
	}
}


//---------------------------------------------------------------------------------------
// 											Sum Of Char Matrix
// 										   --------------------
//
// General 		: The function adding the values from the matrix to variable.
//
// Parameters 	: mat	- the matrix that contain the numbers.
//				  size	- how many values needed to be add.
//				  startingX - what col to start from.
//				  startingY - what row to start from.
//
// Return Value : the result of the adding.
//
//---------------------------------------------------------------------------------------
// Programer 	: Dror Tal
// Student		: 322534793
// Date 		: 1.11.2019
//---------------------------------------------------------------------------------------
unsigned short sumOfCharMatrix(char mat[][N], unsigned short startingX, unsigned short startingY, unsigned short size)
{
	// Variable definition
	unsigned short counter = ZERO;
	unsigned short max = size * size;
	unsigned short sum = ZERO;
	unsigned short x = ZERO;
	unsigned short y = ZERO;

	// Go on how many times needed
	for (;counter < max; counter++)
	{
		// Check what the value is and take it to the sum
		sum += (mat[y + startingY][x + startingX] == '1') ? ONE : ZERO;

		// Calculate the next offset
		(x == (size - ONE)) ? (y++), (x = ZERO) : (x++);
	}

	return (sum);
}
