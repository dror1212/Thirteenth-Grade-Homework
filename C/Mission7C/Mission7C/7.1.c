#pragma once

#include "DrorGeneral.h"

void main1(void)
{
	unsigned short nihush;
	int x[LENGTH_OF_VECTOR]; //4
	int S;
	int temp;
	int counter;
	int secondCounter;
	enum  BOOLEAN exist = FALSE;

	printf("Give the sum and the array");
	scanf("%d", &S);

	for (counter = ZERO; counter < LENGTH_OF_VECTOR; counter++)
	{
		scanf("%d", &x[counter]);
	}

	for (counter = ZERO; counter < LENGTH_OF_VECTOR; counter++)
	{
		for (secondCounter = counter + ONE; secondCounter < LENGTH_OF_VECTOR; secondCounter++)
		{
			exist = (x[counter] + x[secondCounter] == S) ? TRUE : exist;
		}
	}

	printf("result: %d", exist);
	scanf("%d", &S);
}