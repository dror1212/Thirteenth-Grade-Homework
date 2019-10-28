#pragma once

#include "General.h"

//-----------------------------------------------------------------------------------------------------------
//											Matrix #2
//											---------		
//
//  General : The Program fills numbers in a matrix each row as begins with a 1 till the row ends (each row
//			  adds the number of zeros)
//
//	Input : None
//	
//	Process : Checks the number row to see if you need too put a 0 or a number that is (col - row + 1)
//
//	Output : Nothing
//
//-----------------------------------------------------------------------------------------------------------
//	Programmer : Dror Tal
//	Student No : 322534793
//	Date: 29.10.2019
//-----------------------------------------------------------------------------------------------------------
void main2(void)
{
	// Variable definition
	unsigned short mat[SEVEN][SEVEN] = { ZERO };
	unsigned short counter = ZERO;
	unsigned short secondCounter = ZERO;

	// Go on all the offsets
	for (counter = ZERO; counter < SEVEN*SEVEN; counter++)
	{
		// build the matrix like stairs from down up
		mat[counter / SEVEN][counter % SEVEN] = (counter / SEVEN <= counter % SEVEN) ? ((counter % SEVEN + ONE) - counter / SEVEN) : (ZERO);
	}

	printMatrix(mat, SEVEN);

	scanf("%hu", counter);
}