#pragma once

#include "DrorGeneral.h"

void main6A(void)
{
	unsigned short precent[LENGTH_OF_VECTOR]; //40
	unsigned short counter;
	unsigned short sum = ZERO;
	float memuza;
	unsigned short moreThanMemuza = ZERO;
	printf("Give the numbers\n");
	for (counter = ZERO; counter < LENGTH_OF_VECTOR; counter++)
	{
		scanf("%hu", &precent[counter]);
	}

	for (counter = LENGTH_OF_VECTOR - ONE; counter; counter--)
	{
		sum += precent[counter];
	}
	printf("%hu\n", sum);

	memuza = (float)sum / LENGTH_OF_VECTOR;

	printf("%f\n", memuza);

	for (counter = LENGTH_OF_VECTOR - ONE; counter; counter--)
	{
		moreThanMemuza += (precent[counter] > memuza) ? ONE : ZERO;
	}

	printf("Result: %hu", moreThanMemuza);

	scanf("%hu", &counter);
}

void main6B(void)
{
	unsigned short precent[LENGTH_OF_VECTOR]; //40
	unsigned short counter;
	unsigned short sum = ZERO;
	printf("Give the numbers\n");
	for (counter = ZERO; counter < LENGTH_OF_VECTOR; counter++)
	{
		scanf("%hu", &precent[counter]);
	}

	for (counter = ZERO; LENGTH_OF_VECTOR - ONE - counter; counter++){}

	printf("Result: %hu", counter);

	scanf("%hu", &counter);
}