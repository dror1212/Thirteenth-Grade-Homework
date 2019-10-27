#pragma once

#include "General.h"

void main2(void)
{
	unsigned short mat[SEVEN][SEVEN] = { ZERO };
	unsigned short counter = ZERO;
	unsigned short secondCounter = ZERO;

	for (counter = ZERO; counter < SEVEN*SEVEN; counter++)
	{
		mat[counter / SEVEN][counter % SEVEN] = (counter / SEVEN <= counter % SEVEN) ? ((counter % SEVEN + ONE) - counter / SEVEN) : (ZERO);
	}

	printMatrix(mat, SEVEN);

	scanf("%hu", counter);
}