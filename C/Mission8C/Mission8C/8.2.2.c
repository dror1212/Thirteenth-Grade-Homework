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
void main(void)
{
	// Variable definition
	unsigned short mat[SEVEN][SEVEN] = { ZERO };
	unsigned short counter = SEVEN;
	unsigned short secondCounter = ZERO;
	unsigned short x = ZERO;
	unsigned short y = ZERO;
	unsigned short mode = ZERO;
	unsigned short help = ZERO;

	// Go on untull the last offset
	while (secondCounter < SEVEN * SEVEN)
	{
		// Put the number in the matrix
		mat[y][x] = (mat[y][x] == ZERO) ? secondCounter + ONE : mat[y][x];

		// Check what the mode is and pute the number in
		switch (mode)
		{
		case(0):
			((x < SEVEN - ONE) * (mat[y][x + ONE] == ZERO || secondCounter == SEVEN * SEVEN - ONE)) ? x++, secondCounter++ : mode++;
			break;
		case(1):
			((y < SEVEN - ONE) * (mat[y + ONE][x] == ZERO)) ? y++, secondCounter++ : mode++;
			break;
		case(2):
			((x > ZERO) * (mat[y][x - ONE] == ZERO)) ? x--, secondCounter++ : mode++;
			break;
		case(3):
			((y > ZERO) * (mat[y - ONE][x] == ZERO)) ? y--, secondCounter++ : (mode = !mode);
			break;
		}
	}

	printMatrix(mat, SEVEN);

	scanf("%hu", counter);
}