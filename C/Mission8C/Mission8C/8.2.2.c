#pragma once

#include "General.h"

//-----------------------------------------------------------------------------------------------------------
//											Matrix #5
//											---------		
//
//  General : The Program fills numbers in a matrix in a black hole pattern
//
//	Input : None
//	
//	Process : Checks when too turn and then how (Left, Right, Up, Down)
//
//	Output : Nothing
//
//-----------------------------------------------------------------------------------------------------------
//	Programmer : Dror Tal
//	Student No : 322534793
//	Date: 29.10.2019
//-----------------------------------------------------------------------------------------------------------
void main9(void)
{
	// Variable definition
	unsigned short mat[SEVEN][SEVEN] = { ZERO };
	unsigned short counter = ZERO;
	unsigned short x = ZERO;
	unsigned short y = ZERO;
	unsigned short mode = ZERO;
	unsigned short help = ZERO;

	// Go on untull the last offset
	while (counter < SEVEN * SEVEN)
	{
		// Put the number in the matrix
		mat[y][x] = counter + ONE;

		// Check what the mode is and pute the number in
		switch (mode)
		{
		case(0):
			((x < SEVEN - ONE) * (mat[y][x + ONE] == ZERO || counter == SEVEN * SEVEN - ONE)) ? x++, counter++ : mode++;
			break;
		case(1):
			((y < SEVEN - ONE) * (mat[y + ONE][x] == ZERO)) ? y++, counter++ : mode++;
			break;
		case(2):
			((x > ZERO) * (mat[y][x - ONE] == ZERO)) ? x--, counter++ : mode++;
			break;
		case(3):
			((y > ZERO) * (mat[y - ONE][x] == ZERO)) ? y--, counter++ : (mode = !mode);
			break;
		}
	}

	printMatrix(mat, SEVEN);

	scanf("%hu", counter);
}