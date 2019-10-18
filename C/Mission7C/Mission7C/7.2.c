#pragma once

#include "DrorGeneral.h"

void main2(void)
{
	unsigned short nihush;
	int places[LENGTH_OF_VECTOR]; //30
	unsigned short startingPlace;
	unsigned short counter;
	unsigned int canGet = ZERO;
	printf("Give the numbers");
	for (counter = ZERO; counter < LENGTH_OF_VECTOR; counter++)
	{
		scanf("%d", &places[counter]);
	}

	printf("Give the place of you");
	scanf("%d", &startingPlace);
	startingPlace--;

	for (counter = SIX; counter; counter--)
	{
		canGet = (places[startingPlace + counter] == ZERO) ? (canGet * TEN + counter) : (canGet);
	}

	for (; canGet; canGet /= TEN)
	{
		printf("You can get: %hu\n", canGet % TEN);
	}
	scanf("%hu", &counter);
}