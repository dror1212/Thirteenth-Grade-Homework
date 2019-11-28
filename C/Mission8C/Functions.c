#pragma once

#include "General.h"

void printMatrix(unsigned short mat[][SEVEN], unsigned short length)
{
	unsigned short counter;
	unsigned short secondCounter;
	printf("\n");
	for (counter = ZERO; length - counter; counter++)
	{
		for (secondCounter = ZERO; length - secondCounter; secondCounter++)
		{
			printf("%3hu", mat[counter][secondCounter]);
		}
		printf("\n");
	}
}