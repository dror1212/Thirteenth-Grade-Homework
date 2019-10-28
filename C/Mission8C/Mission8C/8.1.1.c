#pragma once

#include "General.h"

//-----------------------------------------------------------------------------------------------------------
//											Matrix #1
//											---------		
//
//  General : The Program fills numbers in a matrix each row as its own number with 0 as the row number
//
//	Input : None
//	
//	Process : Checks the number row to see if you need too put a 0 or a number
//
//	Output : Nothing
//
//-----------------------------------------------------------------------------------------------------------
//	Programmer : Dror Tal
//	Student No : 322534793
//	Date: 28.10.2019
//-----------------------------------------------------------------------------------------------------------
void main1(void)
{
	// Variable definition
	unsigned short mat[SEVEN][SEVEN] = {ZERO};
	unsigned short counter = ZERO;
	unsigned short secondCounter = ZERO;

	// First way
	for (; SEVEN - counter; secondCounter++)
	{
		// Put the numbers in the location, two counters
		mat[counter][secondCounter] = counter + ONE;
		secondCounter = (secondCounter - (SEVEN - ONE)) ? (secondCounter) : (++counter - ONE);
	}

	// Second way
	for (counter = ZERO; counter < SEVEN*SEVEN; counter++)
	{
		// Put the numbers in the location, one counter
		mat[counter / SEVEN][counter%SEVEN] = (counter%SEVEN >= counter / SEVEN) ? counter / SEVEN + ONE : ZERO;
	}

	printMatrix(mat, SEVEN);

	scanf("%hu", counter);
}