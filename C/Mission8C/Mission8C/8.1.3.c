#pragma once

#include "General.h"

void main3(void)
{
	unsigned short mat[SEVEN][SEVEN] = { ZERO };
	unsigned short counter = ZERO;
	unsigned short secondCounter = ZERO;
	for (counter = ZERO; counter < SEVEN*SEVEN; counter++)
	{
		mat[counter / SEVEN][counter % SEVEN] = (((counter % SEVEN >= counter / SEVEN) * (SEVEN - (counter % SEVEN) > counter / SEVEN)) || 
			((counter % SEVEN >= SIX - counter / SEVEN) * (SIX - counter % SEVEN >= SIX - counter / SEVEN)))? ++secondCounter : ZERO;
	}

	printMatrix(mat, SEVEN);

	scanf("%hu", counter);
}