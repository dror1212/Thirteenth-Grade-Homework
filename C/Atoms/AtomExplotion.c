#include "General.h"

//---------------------------------------------------------------------------------------
//                                    Function isExist
//                                    ----------------
//
// General    : Checks if theres an item in the row and col given.
//
// Parameter  : manager (sparceMatNodePtr)
//				row (int) 
//				col (int)
//
// Return     : TRUE if theres an item in that place and FALSE otherwise.
//          
//---------------------------------------------------------------------------------------
BOOLEAN isExist(sparceMatNodePtr manager, int row, int col)
{
	// Variable definition
	sparceMatNodePtr above = findAbove(manager, row, col);
	sparceMatNodePtr before = findBefore(manager, row, col);

	return (above->bottom == before->next);
}

//---------------------------------------------------------------------------------------
//                                    Function exploadAtom
//                                    --------------------
//
// General    : Exploads a given atom given.
//
// Parameter  : manager (sparceMatNodePtr)
//				runner (sparceMatNodePtr)
//				neutronsAlive (int *)
//				exploadedAtoms (int *)
//
// Return     : Nothing but changes the neutronsAlive and exploadedAtoms.
//          
//---------------------------------------------------------------------------------------
void explodeAtom(sparceMatNodePtr manager, sparceMatNodePtr runner, int* neutronsAlive,int* expoldedAtoms)
{
	// Variable definition
	item data;
	data.lastUpdateTurn = runner->data.lastUpdateTurn + ONE;

	// Update the new neutrons
	data.status = UP;
	(*neutronsAlive) += (runner->row > ZERO) ? AddItem(manager, runner->row - ONE, runner->col, data) : ZERO;
	data.status = DOWN;
	(*neutronsAlive) += (runner->row < ROWSIZE) ? AddItem(manager, runner->row + ONE, runner->col, data) : ZERO;
	data.status = RIGHT;
	(*neutronsAlive) += (runner->col < COLSIZE) ? AddItem(manager, runner->row, runner->col + ONE, data) : ZERO;
	data.status = LEFT;
	(*neutronsAlive) += (runner->col > ZERO) ? AddItem(manager, runner->row, runner->col - ONE, data) : ZERO;
	(*expoldedAtoms)++;
}

//---------------------------------------------------------------------------------------
//                                    Function wrapCheckAtom
//                                    ----------------------
//
// General    : Checks if the next node status is ATOM if it is it explodes the ATOM
//              if not it take cares of the neutrons.
//              
//
// Parameter  : temp (sparceMatNodePtr) 
//				turn (int) 
//				neutronsAlive (int *)
//              shouldUseQ (BOOLEAN) 
//              runner (sparceMatNodePtr)
//
// Return     : Nothing.
//          
//---------------------------------------------------------------------------------------
void wrapCheckAtom(sparceMatNodePtr temp, int turn, int* neutronsAlive,dyn_queuePtr q,sparceMatNodePtr runner)
{
	// If temp is a neutron
	if (temp->data.status < ATOM)
	{
		// Hnadle neutrons logics
		(temp->data.lastUpdateTurn < turn) ? insertDynQueue(q, runner) : (void)(temp->data.status = DEATHNEUTRON);
	}
	else
	{
		// Chnage to DeathAtom in case he is not a neutron
		(temp->data.status = DEATHATOM);
	}

	// Update the turn and the amount
	temp->data.lastUpdateTurn = turn;
	(*neutronsAlive)--;
}

//---------------------------------------------------------------------------------------
//                                    Function ActIfSomeoneIsNear
//                                    ---------------------------
//
// General    : Checks if there is someone near in his direction if so it checks 
//              the function wrapCheckAtom if not it just moves the neutron.
//              
//
// Parameter  : manager type sparceMatNodePtr and a runner type sparceMatNodePtr which 
//              is the current node in the sparce matrix. 
//              a pointer for "neutronsAlive" the current turn the queue a temp type
//              sparceMatNodePtr int row and col and BOOLEAN shouldQ that tells if 
//              if to use the queue or not.
//
// Return     : Nothing.
//          
//---------------------------------------------------------------------------------------
void ActIfSomeoneIsNear(sparceMatNodePtr manager, sparceMatNodePtr runner,dyn_queuePtr q,int turn, int *neutronsAlive,sparceMatNodePtr temp)
{
	// Variable definition
	int rowDirection = getRowDirection(runner->data.status);
	int colDirection = getColDirection(runner->data.status);

	// If someont is where runner should move
	if (isExist(manager, runner->row + rowDirection, runner->col + colDirection))
	{
		// Handle his logics
		wrapCheckAtom(temp, turn, neutronsAlive, q, runner);
	}
	else
	{
		// Move the runner
		runner->data.lastUpdateTurn = turn;
		AddItem(manager, runner->row + rowDirection, runner->col + colDirection, runner->data);
	}
}

int getRowDirection(Status status)
{
	// Calculates the row direction by the enum
	return (!(status % TWO)) ? status - ONE : ZERO;
}

int getColDirection(Status status)
{
	// Calculates the col direction by the enum
	return (status % TWO) ? status - TWO : ZERO;
}

//---------------------------------------------------------------------------------------
//                                    Function ActIfSomeoneIsNear
//                                    ---------------------------
//
// General    : Checks if the runner should do something this turn
//              
//
// Parameter  : manager type sparceMatNodePtr and a runner type sparceMatNodePtr which 
//              is the current node in the sparce matrix. 
//              a pointer for "neutronsAlive" the current turn the queue a temp type
//              sparceMatNodePtr int row and col and BOOLEAN shouldQ that tells if 
//              if to use the queue or not.
//
// Return     : Nothing.
//          
//---------------------------------------------------------------------------------------
BOOLEAN checkRunner(sparceMatNodePtr manager, sparceMatNodePtr runner, dyn_queuePtr q, int turn, int* neutronsAlive,sparceMatNodePtr temp)
{
	// Variable definition
	int identifier = (runner->data.status % TWO) ? runner->col : runner->row;
	int border = (runner->data.status % TWO) ? (COLSIZE - ONE) * !(!(runner->data.status - ONE)) : (ROWSIZE - ONE) * !(!(runner->data.status));
	BOOLEAN turnCheck = runner->data.lastUpdateTurn < turn;
	BOOLEAN shouldDelete = (identifier == border);

	(*neutronsAlive) -= shouldDelete * turnCheck;
	(!shouldDelete * turnCheck) ? ActIfSomeoneIsNear(manager, runner, q, turn, neutronsAlive, temp) : (void)NULL;

	return turnCheck;
}

//---------------------------------------------------------------------------------------
//                                    Function handleNext
//                                    --------------------
//
// General    : Activates the logics of the RIGHT going neutron.
//              
//
// Parameter  : manager (sparceMatNodePtr)
//				runner (sparceMatNodePtr)
//				q (dyn_queuePtr)
//				turn (int)
//				neutronsAlive (int *)
//				explodedAtoms (int *)
//
// Return     : Nothing.
//          
//---------------------------------------------------------------------------------------
BOOLEAN handleNext(sparceMatNodePtr manager, sparceMatNodePtr runner, dyn_queuePtr q, int turn, int * neutronsAlive, int * explodedAtoms)
{
	return checkRunner(manager, runner, q, turn, neutronsAlive, runner->next);
}

//---------------------------------------------------------------------------------------
//                                    Function handleBottom
//                                    --------------------
//
// General    : Activates the logics of the BOTTOM going neutron.
//              
//
// Parameter  : manager (sparceMatNodePtr)
//				runner (sparceMatNodePtr)
//				q (dyn_queuePtr)
//				turn (int)
//				neutronsAlive (int *)
//				explodedAtoms (int *)
//
// Return     : Nothing.
//          
//---------------------------------------------------------------------------------------
BOOLEAN handleBottom(sparceMatNodePtr manager, sparceMatNodePtr runner, dyn_queuePtr q, int turn, int* neutronsAlive, int* explodedAtoms)
{
	return checkRunner(manager, runner, q, turn, neutronsAlive, runner->bottom);
}

//---------------------------------------------------------------------------------------
//                                    Function handleBefore
//                                    --------------------
//
// General    : Activates the logics of the LEFT going neutron.
//              
//
// Parameter  : manager (sparceMatNodePtr)
//				runner (sparceMatNodePtr)
//				q (dyn_queuePtr)
//				turn (int)
//				neutronsAlive (int *)
//				explodedAtoms (int *)
//
// Return     : Nothing.
//          
//---------------------------------------------------------------------------------------
BOOLEAN handleBefore(sparceMatNodePtr manager, sparceMatNodePtr runner, dyn_queuePtr q, int turn, int* neutronsAlive, int* explodedAtoms)
{
	return checkRunner(manager, runner, q, turn, neutronsAlive, findBefore(manager, runner->row, runner->col));
}

//---------------------------------------------------------------------------------------
//                                    Function handleAbove
//                                    --------------------
//
// General    : Activates the logics of the ABOVE going neutron.
//              
//
// Parameter  : manager (sparceMatNodePtr)
//				runner (sparceMatNodePtr)
//				q (dyn_queuePtr)
//				turn (int)
//				neutronsAlive (int *)
//				explodedAtoms (int *)
//
// Return     : Nothing.
//          
//---------------------------------------------------------------------------------------
BOOLEAN handleAbove(sparceMatNodePtr manager, sparceMatNodePtr runner, dyn_queuePtr q, int turn, int* neutronsAlive, int* explodedAtoms)
{
	return checkRunner(manager, runner, q, turn, neutronsAlive, findAbove(manager, runner->row, runner->col));
}

//---------------------------------------------------------------------------------------
//                                    Function handleNext
//                                    --------------------
//
// General    : Activates the logics of the ATOM (do nothing)
//              
//
// Parameter  : manager (sparceMatNodePtr)
//				runner (sparceMatNodePtr)
//				q (dyn_queuePtr)
//				turn (int)
//				neutronsAlive (int *)
//				explodedAtoms (int *)
//
// Return     : Nothing.
//          
//---------------------------------------------------------------------------------------
BOOLEAN handleAtom(sparceMatNodePtr manager, sparceMatNodePtr runner, dyn_queuePtr q, int turn, int* neutronsAlive, int* explodedAtoms)
{
	return FALSE;
}

//---------------------------------------------------------------------------------------
//                                    Function handleDeathAtom
//                                    -------------------------
//
// General    : Activates the logics of the DEATHATOM.
//              
//
// Parameter  : manager (sparceMatNodePtr)
//				runner (sparceMatNodePtr)
//				q (dyn_queuePtr)
//				turn (int)
//				neutronsAlive (int *)
//				explodedAtoms (int *)
//
// Return     : Nothing.
//          
//---------------------------------------------------------------------------------------
BOOLEAN handleDeathAtom(sparceMatNodePtr manager, sparceMatNodePtr runner, dyn_queuePtr q, int turn, int* neutronsAlive, int* explodedAtoms)
{
	// If it's his tur to exploade, explode him.
	(runner->data.lastUpdateTurn < turn) ? explodeAtom(manager, runner, neutronsAlive, explodedAtoms) : (void)NULL;
	return (runner->data.lastUpdateTurn < turn);
}

//---------------------------------------------------------------------------------------
//                                 Function handleDeathNeutron
//                                    --------------------
//
// General    : Activates the logics of the DEATHNEUTRON.
//              
//
// Parameter  : manager (sparceMatNodePtr)
//				runner (sparceMatNodePtr)
//				q (dyn_queuePtr)
//				turn (int)
//				neutronsAlive (int *)
//				explodedAtoms (int *)
//
// Return     : Nothing.
//          
//---------------------------------------------------------------------------------------
BOOLEAN handleDeathNeutron(sparceMatNodePtr manager, sparceMatNodePtr runner, dyn_queuePtr q, int turn, int* neutronsAlive, int* explodedAtoms)
{
	(*neutronsAlive) -= runner->data.lastUpdateTurn < turn;

	// Shoud delete only if updated
	return runner->data.lastUpdateTurn < turn;
}

//---------------------------------------------------------------------------------------
//                                    Function CheckStep
//                                    ------------------
//
// General    : Makes the changes needed for each status (neutron UP, ATOM and more..)
//              plus returns the next item.
//
// Parameter  : manager type sparceMatNodePtr and a runner type sparceMatNodePtr that you
//              you will check his status and for each status you will go to another case
//
// Return     : The next existing item.
//          
//---------------------------------------------------------------------------------------
sparceMatNodePtr CheckStep(sparceMatNodePtr manager,sparceMatNodePtr runner, dyn_queuePtr q,int turn,int*neutronsAlive,int*explodedAtoms, BOOLEAN(*functions[])())
{
	// Variable definition
	sparceMatNodePtr help = runner->next;
	BOOLEAN shouldDelete;

	printf("\n");
	PrintSparce(manager, ROWSIZE, COLSIZE);
	printf("\n%d\n", *neutronsAlive);

	// Active the function depends on the enum
	shouldDelete = functions[runner->data.status](manager, runner, q, turn, neutronsAlive, explodedAtoms);

	// Remove him if should
	(shouldDelete) ? (void)(RemoveItem(manager, runner->row, runner->col)) : (void)(NULL);
	return help;
}

//---------------------------------------------------------------------------------------
//                                    Function handleQ
//                                    ----------------
//
// General    : If the item does notexists in the place runner->row + row and 
//              runner->col + col it adds him to the place he needs to be in after the turn.
//
// Parameter  : manager type sparceMatNodePtr and a runner type sparceMatNodePtr that is 
//              the current place of the nodes. row , col and the pointers for neutronsAlive.
//              
//
// Return     : Nothing.
//          
//---------------------------------------------------------------------------------------
void handleQ(sparceMatNodePtr manager, sparceMatNodePtr runner, int row, int col, int* neuronsAlive)
{
	// If no one is there, add him
	if (!isExist(manager, runner->row + row, runner->col + col))
	{
		AddItem(manager, runner->row + row, runner->col + col, runner->data);
		(*neuronsAlive)++;
	}
}

//---------------------------------------------------------------------------------------
//                                    Function checkAfterQueue
//                                    ------------------------
//
// General    : Calls the function handleQ for each case (status of runner) with different
//              values.
//
// Parameter  : manager type sparceMatNodePtr and a runner type sparceMatNodePtr that is 
//              the current place of the nodes. and the pointers for the explodedAtoms and
//              neutronsAlive.
//
// Return     : Nothing.
//          
//---------------------------------------------------------------------------------------
void checkAfterQueue(sparceMatNodePtr manager, sparceMatNodePtr runner, int* explodedAtoms, int* neuronsAlive)
{
	// Variable definition
	int rowDirection = getRowDirection(runner->data.status);
	int colDirection = getColDirection(runner->data.status);

	// If no one is there, add him
	if (!isExist(manager, runner->row + rowDirection, runner->col + colDirection))
	{
		(*neuronsAlive) += AddItem(manager, runner->row + rowDirection, runner->col + colDirection, runner->data);
	}
}

//---------------------------------------------------------------------------------------
//                                    Function updateMap
//                                    ------------------
//
// General    : Runs on all items alive and calls the function CheckStep on each existing
//              item.
//
// Parameter  : manager type sparceMatNodePtr and a last type sparceMatNodePtr that tells
//              you the last rows manager and the pointers for the turn explodedAtoms and
//              neutronsAlive.
//
// Return     : Nothing.
//          
//---------------------------------------------------------------------------------------
void updateMap(sparceMatNodePtr manager, int* explodedAtoms,int*neuronsAlive, int *turn, BOOLEAN(*functions[]))
{
	// Variable definition
	dyn_queue q;
	sparceMatNodePtr start = manager->bottom;
	sparceMatNodePtr runner = manager->bottom->next;
	sparceMatNodePtr last = goToManagerRow(&manager, ROWSIZE);

	// Create the managers
	initDynQueue(&q);

	// Go untill the end and activate the logic
	while (runner != last)
	{
		runner = (runner->col == -ONE)? runner->bottom->next : CheckStep(manager, runner, &q, *turn, neuronsAlive, explodedAtoms, functions);
	}

	// Go on all of those who entered the queue
	while (!isEmptyDynQueue(&q))
	{
		runner = removeDynQueue(&q);
		checkAfterQueue(manager, runner, explodedAtoms, neuronsAlive);
	}

	(*turn)++;
}

//---------------------------------------------------------------------------------------
//                                  Function AttachAtomsToMatrix
//                                  ----------------------------
//
// General    : takes a string that is written like that : "6,5,3,2,6,7," and every comma
//              seperates between row and col so in my example for the string there will 
//              be 3 new added items to the sparce matrix : (row)6,(col)4 3,2 6,7.
//
// Parameter  : manager type sparceMatNodePtr and a string for the atom places.
//
// Return     : Nothing.
//          
//---------------------------------------------------------------------------------------
void AttachAtomsToMatrix(sparceMatNodePtr manager, char* atoms)
{
	// Variable definition
	char* start = atoms;
	BOOLEAN Row = TRUE;
	unsigned short row = ZERO;
	unsigned short col = ZERO;
	int numTemp = ZERO;
	item data;
	data.status = ATOM;
	data.lastUpdateTurn = ZERO;

	// Read all the places fro the string I took from the file
	while ((*atoms) != '\0')
	{
		// Check if it's a new place
		if (*atoms != ',')
		{
			// Take the numbers from the string
			numTemp = TEN * numTemp + ((*atoms) - '0');
			(Row) ? (row = numTemp) : (col = numTemp);
		}
		else
		{
			Row = !Row;
			numTemp = ZERO;

			// Add the item if there are 2 numbers
			if (Row)
			{
				AddItem(manager, row, col, data);
			}
		}
		atoms++;
	}
	free(start);
}

//---------------------------------------------------------------------------------------
//                             Function ReadAndMakeAtomsFromFile
//                             ---------------------------------
//
// General    : Gets a file name and a manager for the sparce matrix and if the file 
//              exists it opens it and start reading the whole file into a string
//              at the end after the whole file is in a string it calls the function
//              AttachAtomsToMatrix
//
// Parameter  : manager (sparceMatNodePtr)
//
// Return     : Nothing.
//          
//---------------------------------------------------------------------------------------
void ReadAndMakeAtomsFromFile(sparceMatNodePtr manager)
{
	// Variable definition
	char fileName[] = "atoms.txt\0";
	FILE* fileAtoms = fopen(fileName, "r");
	int size;
	char* atoms;

	// Read the file nd save the info
	fseek(fileAtoms, 0, SEEK_END);
	size = ftell(fileAtoms);
	atoms = (char*)malloc(size*sizeof(char)+TWO);

	fseek(fileAtoms, 0, SEEK_SET);
	fgets(atoms,size+1, fileAtoms);
	*(atoms + size+1 )= '\0';

	// free the file
	free(fileAtoms);

	// Change the string to the places
	AttachAtomsToMatrix(manager, atoms);
	
}

//---------------------------------------------------------------------------------------
//									 Function createBored
//                             ---------------------------------
//
// General    : Init the managers of the sparce matrix.
// Parameter  : manager (sparceMatNodePtr)
//				height (int *)
//				width (int *)
//
// Return     : Nothing.
//          
//---------------------------------------------------------------------------------------
void createBored(sparceMatNodePtr manager, int * height, int * width)
{
	// Variable definition
	int i;
	int leftovers = COLSIZE - ROWSIZE;

	//init for the size of the starting matrix, create the managers
	for (i = ZERO; i < ROWSIZE; i++)
	{
		AddRowSparce(&manager, height);
		AddColSparce(&manager, width);
	}
	for (i = ZERO; i < leftovers; i++)
	{
		AddColSparce(&manager, width);
	}
}

//---------------------------------------------------------------------------------------
//								   	  Function play
//                                --------------------
//
// General    : Activates the game logics untill there are no more neutrons.
// Parameter  : manager (sparceMatNodePtr)
//				neutronsAlive (int *)
//				exploadedAtoms (int *)
//
// Return     : Nothing.
//          
//---------------------------------------------------------------------------------------
void play(sparceMatNodePtr manager, int * neutronsAlive, int * exploadedAtoms)
{
	// Variable definition
	int turn = ONE;
	BOOLEAN(*functions[DEATHATOM + ONE])();

	// Give each one his function
	functions[UP] = handleAbove;
	functions[LEFT] = handleBefore;
	functions[DOWN] = handleBottom;
	functions[RIGHT] = handleNext;
	functions[ATOM] = handleAtom;
	functions[DEATHNEUTRON] = handleDeathNeutron;
	functions[DEATHATOM] = handleDeathAtom;

	// Activate the logics untill the game is over
	while (*neutronsAlive)
	{
		updateMap(manager, exploadedAtoms, neutronsAlive, &turn, functions);
	}
}

void firstExploade(sparceMatNodePtr manager,int * neutronsAlive, int * expoldedAtoms)
{
	// Variable definition
	sparceMatNode firstAtom;
	sparceMatNodePtr firstAtomPtr = &firstAtom;
	int atomExplodeRow;
	int atomExplodeCol;

	// I/O where to place the atoms
	printf("where do you want to explode the atom \n");
	scanf("%d %d", &atomExplodeRow, &atomExplodeCol);

	// Create an info for the first exploade
	firstAtomPtr->row = atomExplodeRow;
	firstAtomPtr->col = atomExplodeCol;
	firstAtomPtr->data.lastUpdateTurn = -ONE;
	firstAtomPtr->data.status = ATOM;

	// Exploade the atom and remove this Atom
	explodeAtom(manager, firstAtomPtr, neutronsAlive, expoldedAtoms);
	RemoveItem(manager, atomExplodeRow, atomExplodeCol);
}

//-------------------------------------------------------------------------------------------------
//                                        Atom Explosion
//                                        --------------
//
// General : Take cares of a program that has a sparce matrix structure who has atoms at the 
//           beggining and you explode one of them. the explosion makes 4 neutrons around the atom
//           that if they his another atoms they explode him aswell and if they hit another neutron
//           at the same "turn" (time) so they dissapear. and it runs till there are no more neutrons
//           at the end it prints out the energy that the explosion made.
//           
// Input   : Where to explode the atom. 
//
// Process : The program creates a sparce matrix and calls the function ReadAndMakeAtomsFromFile that
//           reads a file and puts the atoms in this file in their place at the sparce matrix and then
//           it requests which atom you wish to explode and start working. at the end tells you the
//           amount of energy made (which is the amount of atoms exploded). all that with the function
//           updateWorld that calls some other functions inside as you can see in the dec of that func.
//          
// Output  : How much energy the explosion made.
//
//-------------------------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 27.01.2019
//-------------------------------------------------------------------------------------------------
void main(void)
{
	// Variable definition
	int neutronsAlive = ZERO;
	int expoldedAtoms= ZERO;
	sparceMatNodePtr manager;
	int height = ZERO;
	int width = ZERO;

	// Create the sparce matrix
	initSparce(&manager);
	createBored(manager, &height, &width);

	// Place the atoms from the file
	ReadAndMakeAtomsFromFile(manager);

	// Update the expload the user chose
	firstExploade(manager, &neutronsAlive, &expoldedAtoms);

	// Activate the game logics
	play(manager,&neutronsAlive,&expoldedAtoms);

	printf("Energy that the explosion made :  %d", expoldedAtoms);
	scanf("%d", &height);
}