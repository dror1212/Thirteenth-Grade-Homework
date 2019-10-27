#pragma once

#include "General.h"

void main(void)
{
	unsigned short mat[SEVEN][SEVEN] = { ZERO };
	unsigned short counter = ZERO;
	unsigned short secondCounter = ZERO;
	BOOLEAN check = FALSE;
	for (counter = ZERO; counter < SEVEN*SEVEN; counter++)
	{
		mat[counter / SEVEN][counter % SEVEN] = counter + ONE + check * (SIX - counter % SEVEN);
		check = (counter % SEVEN) ? check : !check;
	}

	printMatrix(mat, SEVEN);

	scanf("%hu", counter);
}