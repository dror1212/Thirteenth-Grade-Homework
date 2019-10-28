#pragma once

#include "General.h"

void main4(void)
{
	unsigned short mat[SEVEN][SEVEN] = { ZERO };
	unsigned short counter = ZERO;
	unsigned short secondCounter = ZERO;
	BOOLEAN check = FALSE;
	for (counter = ZERO; counter < SEVEN*SEVEN; counter++)
	{
		check = ((counter % SEVEN) + (counter == ZERO)) ? check : !check;
		mat[counter / SEVEN][counter % SEVEN] = counter + ONE + check * (SIX - (counter % SEVEN) * TWO);
	}

	printMatrix(mat, SEVEN);

	scanf("%hu", counter);
}