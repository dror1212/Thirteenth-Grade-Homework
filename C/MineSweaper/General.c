// General.c

#include "General.h"

//-------------------------------------------------------------------------------------------------
//                                    			 init
//                                    		  ----------
//
// General      : Create the basic boared of the game.
//
// Parameter    : mat - The address where the boared should be (hiddenShort **)
//
// Return Value : Nothing.
//          
//-------------------------------------------------------------------------------------------------
void init(hiddenShort **mat)
{
	// Variable definition
	(*mat) = (hiddenShort *)malloc(FULL_SIZE * sizeof(hiddenShort));
	hiddenShort * temp = *mat;
	hiddenShort * end = *mat + FULL_SIZE;

	// Go on all the boared
	while(temp < end)
	{
		(*temp).isHidden = TRUE;
		(*(temp++)).value = ZERO;
	}

	return;
}

//-------------------------------------------------------------------------------------------------
//                                    			 play
//                                    		  ----------
//
// General      : Rule all the game.
//
// Parameter    : None.
//
// Return Value : Nothing.
//          
//-------------------------------------------------------------------------------------------------
void play()
{
	// Variable definition
    BOOLEAN check = TRUE;
	BOOLEAN lose = FALSE;
    short value;
    hiddenShort *mat;
	string str;

	// Initial the boared
    init(&mat);

	// Get the bombs
	printf("Where do you want to place the bombs?");
	gets(str);

	// Set the bombs depends on the info from the user
    setBombs(mat, &str);

	// Go ontill there are no more bombs or the player hit a bomb
    while (check)
    {
		// Check if the game is over and print the boared
        check = printMatrixAndCheck(mat);

		// Let the user try to hit
		hit(mat, &check, &lose);
    }

	// Tell the player he lost if he lost
	(lose) ? printf("\nYou hit a bomb, you lost\n") : printf("\nYou won\n");
    printf("The Game Is Over");
	free(mat);

	return;
}

//-------------------------------------------------------------------------------------------------
//                                    			  hit
//                                    		   ---------
//
// General      : Let the player to try to hit.
//
// Parameter    : 
//			mat   - The address where the boared is (hiddenShort *)
//			check - The value that says if he should try hit at all and if the game shold stop (BOOLEAN *)
//			lose  - The value that says if the player lost (BOOLEAN *)
//
// Return Value : Nothing.
//          
//-------------------------------------------------------------------------------------------------
void hit(hiddenShort * mat, BOOLEAN * check, BOOLEAN * lose)
{
	// Check what the user hit
	if (*check * (tryHit(mat) == -ONE))
	{
		// If he hit a bomb
		*check = FALSE;
		*lose = TRUE;
	}

	return;
}

//-------------------------------------------------------------------------------------------------
//                                    			 setBombs
//                                    		   ------------
//
// General      : Set the bombs on the boared
//
// Parameter    : 
//			mat   - The address where the boared is (hiddenShort *)
//			c     - The string were the info of the bombs is (char *)
//
// Return Value : Nothing.
//          
//-------------------------------------------------------------------------------------------------
void setBombs(hiddenShort *mat, char * ptr)
{
	// Variable definition
	unsigned short y;
	unsigned short x;
	unsigned short temp = ZERO;
	BOOLEAN isRow = TRUE;

	// Go to the end of the string
	while ((*ptr) != '\0')
	{
		// If you are not on a space
		if (*ptr != ' ')
		{
			// Take row/col depends on isRow
			temp = TEN * temp + ((*ptr) - '0');
			(isRow) ? (y = temp) : (x = temp);
		}
		else
		{
			// If you are on a space, take the values
			temp = ZERO;
			isRow = !isRow;

			// On the second space, update the neighors of this bomb
			(isRow) ? (*(mat + y * UPPER + x)).value = -ONE, updateNeighors(mat, x + y * UPPER) : ZERO;
		}
		ptr++;
	}

	return;
}

//-------------------------------------------------------------------------------------------------
//                                    	printMatrixAndCheck
//                                    -----------------------
//
// General      : Print the boared and check the status of the boared.
//
// Parameter    : 
//			mat   - The address where the boared is (hiddenShort *)
//
// Return Value : The game should end? (BOOLEAN)
//          
//-------------------------------------------------------------------------------------------------
BOOLEAN printMatrixAndCheck(hiddenShort *mat)
{
	// Variable definition
    BOOLEAN check = FALSE;
	BOOLEAN help = FALSE;
	hiddenShort * end = mat + FULL_SIZE;

	// Go on all the boared
    while (mat < end)
    {
		// If you are in the end of the line go down a line
		(!((end - mat) % UPPER)) ? printf("\n") : printf("");

		// Check what you need to show and if the player lost
		((*mat).isHidden * (*mat).value != -ONE) ? (check = TRUE) : (help = TRUE);

		// Show the boared
		((*mat).isHidden)? printf(". ") : printf("%d ", (*mat).value);
		mat++;
	}

    return (check * help);
}

//-------------------------------------------------------------------------------------------------
//                                    			 getInfo
//                                    		   -----------
//
// General      : Get the info from the player to guess where to hit.
//
// Parameter    : 
//			mat   - The address where the boared is (hiddenShort *)
//			check - The value that checks if he needs to hit again (BOOLEAN *)
//
// Return Value : The place where the player hit (unsigned short)
//          
//-------------------------------------------------------------------------------------------------
unsigned short getInfo(hiddenShort * mat, BOOLEAN * check)
{
	// Variable definition
	unsigned short y;
	unsigned short x;
	unsigned short place;

	// Get the guess from the user
	printf("\nGive row\n");
	scanf("%hu", &y);
	printf("\nGive col\n");
	scanf("%hu", &x);

	// Calculate the place
	place = x + y * UPPER;

	// Check if the player already guessed it, if he is, let him try again
	((*(mat + place)).isHidden)? (*check = (*(mat + place)).isHidden = FALSE) :
								(printf("Try again, you already guessed it"));

	return (place);
}

//-------------------------------------------------------------------------------------------------
//                                    			 tryHit
//                                    		   ----------
//
// General      : Let the player to try to hit again if he hit something that is alreadt been hit.
//
// Parameter    : mat - The address where the boared is (hiddenShort *)
//
// Return Value : What did the player hit (short)
//          
//-------------------------------------------------------------------------------------------------
short tryHit(hiddenShort *mat)
{
	// Variable definition
    BOOLEAN check = TRUE;
	unsigned short place;

	// While the player didn't guess a new place
	while (check)
	{
		// Let the player guess
		place = getInfo(mat, &check);
	}

	// Return what the player hit
    return ((*(mat + place)).value);
}

//-------------------------------------------------------------------------------------------------
//                                    			 getRow
//                                    		   ----------
//
// General      : Calculates the row.
//
// Parameter    : y - The value that should transfer to the row (unsigned short)
//
// Return Value : The row (unsigned short)
//          
//-------------------------------------------------------------------------------------------------
unsigned short getRow(unsigned short y)
{
	//Get the row
    return (y / UPPER);
}

//-------------------------------------------------------------------------------------------------
//                                    			 getCol
//                                    		   ----------
//
// General      : Calculates the col.
//
// Parameter    : x - The value that should transfer to the row (unsigned short)
//
// Return Value : The col (unsigned short)
//          
//-------------------------------------------------------------------------------------------------
unsigned short getCol(unsigned short x)
{
	// Get the col
    return (x % UPPER);
}

//-------------------------------------------------------------------------------------------------
//                                    			 min
//                                    		    -----
//
// General      : Calculates what is the min value for the checking.
//
// Parameter    : c - The value that should be checked.
//
// Return Value : The minimum value (unsigned short)
//          
//-------------------------------------------------------------------------------------------------
unsigned short min(unsigned short c)
{
	// Check what is the min border
	return ((c - ONE < ZERO) ? ZERO : c - ONE);
}

//-------------------------------------------------------------------------------------------------
//                                    			 max
//                                    		    -----
//
// General      : Calculates what is the max value for the checking.
//
// Parameter    : c - The value that should be checked.
//
// Return Value : The maximum value (unsigned short)
//          
//-------------------------------------------------------------------------------------------------
unsigned short max(unsigned short c)
{
	// Check what is the max border
	return ((c + ONE > UPPER - ONE) ? c : c + ONE);
}

//-------------------------------------------------------------------------------------------------
//                                    		updateNeighors
//									      ------------------
//
// General      : Update the neighors of the bombs.
//
// Parameter    : 
//			mat     - The address where the boared is (hiddenShort *)
//			counter - The place where the bomb is (unsigned short)
//
// Return Value : Nothing.
//          
//-------------------------------------------------------------------------------------------------
void updateNeighors(hiddenShort *mat, unsigned short counter)
{
	// Variable definition - get the row and col borders
	unsigned short rowmin = min(getRow(counter));
	unsigned short rowmax = max(getRow(counter));
	unsigned short colmin = min(getCol(counter));
	unsigned short colmax = max(getCol(counter));
	unsigned short temp = colmin;

	// Go on three by three around the bomb to update their value
	for (; rowmin <= rowmax; rowmin++)
	{
		for (colmin = temp; colmin <= colmax; colmin++)
		{
			// Increase their value to show there is a bomb nearby
			((*(mat + rowmin * UPPER + colmin)).value != -ONE) ? (*(mat + rowmin * UPPER + colmin)).value++ : ZERO;
		}
	}

	return;
}