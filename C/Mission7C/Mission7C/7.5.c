#pragma once

#include "DrorGeneral.h"

void main5(void)
{
	unsigned short nihush;
	int places[LENGTH_OF_VECTOR]; //25
	unsigned short startingPlace;
	unsigned short counter;
	unsigned int newPlace;
	printf("Give the numbers\n");
	for (counter = ZERO; counter < LENGTH_OF_VECTOR; counter++)
	{
		scanf("%d", &places[counter]);
	}

	printf("Give the place of you\n");
	scanf("%d", &startingPlace);
	startingPlace--;

	for (counter = SIX; counter; counter--)
	{
		newPlace = (places[startingPlace + counter] <= counter) ? (startingPlace + counter + ONE) : startingPlace - counter + ONE;
		printf("If you can get %hu, you will go to: %hu\n", counter, newPlace);
	}

	scanf("%hu", &counter);
}