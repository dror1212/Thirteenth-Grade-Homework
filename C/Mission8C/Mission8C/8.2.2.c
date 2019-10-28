#pragma once

#include "General.h"

void main(void)
{
	unsigned short mat[SEVEN][SEVEN] = { ZERO };
	unsigned short counter = SEVEN;
	unsigned short secondCounter = ZERO;
	unsigned short x = ZERO;
	unsigned short y = ZERO;
	unsigned short mode = ZERO;
	unsigned short help = ZERO;
	while (secondCounter < SEVEN * SEVEN)
	{
		if (mat[y][x] == ZERO)
		{
			mat[y][x] = secondCounter + ONE;
		}
		switch (mode)
		{
		case(0):
			((x < SIX) * (mat[y][x + ONE] == ZERO || secondCounter == SEVEN * SEVEN - ONE)) ? x++, secondCounter++ : mode++;
			break;
		case(1):
			((y < SIX) * (mat[y + ONE][x] == ZERO)) ? y++, secondCounter++ : mode++;
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