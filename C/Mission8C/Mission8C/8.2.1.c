#pragma once

#include "General.h"

//-----------------------------------------------------------------------------------------------------------
//											Matrix #4
//											---------		
//
//  General : The Program fills numbers in a matrix in a zig zag pattern
//
//	Input : None
//	
//	Process : Checks if the row is an even number or uneven too see how it needs too write them
//
//	Output : Nothing
//
//-----------------------------------------------------------------------------------------------------------
//	Programmer : Dror Tal
//	Student No : 322534793
//	Date: 29.10.2019
//-----------------------------------------------------------------------------------------------------------
void main4(void)
{
	// Variable definition
	unsigned short mat[SEVEN][SEVEN] = { ZERO };
	unsigned short counter = ZERO;
	BOOLEAN check = FALSE;

	// Go on all the matrix
	for (counter = ZERO; counter < SEVEN*SEVEN; counter++)
	{
		// Check what way should it go
		check = ((counter % SEVEN) + (counter == ZERO)) ? check : !check;
		mat[counter / SEVEN][counter % SEVEN] = counter + ONE + check * (SIX - (counter % SEVEN) * TWO);
	}

	printMatrix(mat, SEVEN);

	scanf("%hu", counter);
}