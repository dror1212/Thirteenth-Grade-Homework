#pragma once

#include "General.h"

void main1(void)
{
	unsigned short mat[SEVEN][SEVEN] = {ZERO};
	unsigned short counter = ZERO;
	unsigned short secondCounter = ZERO;

	for (; SEVEN - counter; secondCounter++)
	{
		mat[counter][secondCounter] = counter + ONE;
		secondCounter = (secondCounter - (SEVEN - ONE)) ? (secondCounter) : (++counter - ONE);
	}

	printMatrix(mat, SEVEN);
	
	for (counter = ZERO; counter < SEVEN*SEVEN; counter++)
	{
		mat[counter / SEVEN][counter%SEVEN] = (counter%SEVEN >= counter / SEVEN) ? counter / SEVEN + ONE : ZERO;
	}

	printMatrix(mat, SEVEN);

	scanf("%hu", counter);
}