#pragma once

#include "DrorGeneral.h"

void main4(void)
{
	unsigned short amount = ZERO;
	int chars[LENGTH_OF_VECTOR]; //20
	unsigned short counter;
	unsigned short minusOneLast = LENGTH_OF_VECTOR - TWO;
	unsigned short lastOne = LENGTH_OF_VECTOR - ONE;

	printf("Give the chars\n");
	for (counter = ZERO; counter < LENGTH_OF_VECTOR; counter++)
	{
		scanf("%d", &chars[counter]);
	}

	for (counter = ONE; counter < minusOneLast; counter++)
	{
		amount += ((chars[counter - ONE] == chars[minusOneLast]) * (chars[counter] == chars[lastOne])) ? (ONE) : (ZERO);
	}

	printf("Amount: %hu", &amount);
	scanf("%hu", &counter);
}