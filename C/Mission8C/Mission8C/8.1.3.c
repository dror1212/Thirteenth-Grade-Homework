#pragma once

#include "General.h"

//-----------------------------------------------------------------------------------------------------------
//											Matrix #3
//											---------		
//
//  General : The Program fills numbers in a matrix with an hour glass pattern
//
//	Input : None
//	
//	Process : Checks the limit of number too write and then lowers it 
//
//	Output : Nothing
//
//-----------------------------------------------------------------------------------------------------------
//	Programmer : Dror Tal
//	Student No : 322534793
//	Date: 29.10.2019
//-----------------------------------------------------------------------------------------------------------
void main3(void)
{
	// Variable definition
	unsigned short mat[SEVEN][SEVEN] = { ZERO };
	unsigned short counter = ZERO;
	unsigned short secondCounter = ZERO;

	// Go on all the matrix
	for (counter = ZERO; counter < SEVEN*SEVEN; counter++)
	{
		// Checks the limit and update it
		mat[counter / SEVEN][counter % SEVEN] = (((counter % SEVEN >= counter / SEVEN) * (SEVEN - (counter % SEVEN) > counter / SEVEN)) || 
			((counter % SEVEN >= SIX - counter / SEVEN) * (SIX - counter % SEVEN >= SIX - counter / SEVEN)))? ++secondCounter : ZERO;
	}

	printMatrix(mat, SEVEN);

	scanf("%hu", counter);
}