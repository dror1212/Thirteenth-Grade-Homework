#pragma once

#include "DrorGeneral.h"

void main5(void)
{
	// Variable definition
	unsigned short nihush;
	int places[LENGTH_OF_VECTOR]; //25
	unsigned short startingPlace;
	unsigned short counter;
	unsigned int newPlace;

	printf("Give the numbers\n");

	// Get 25 place's values
	for (counter = ZERO; counter < LENGTH_OF_VECTOR; counter++)
	{
		scanf("%d", &places[counter]);
	}

	// Get the starting place
	printf("Give the place of you\n");
	scanf("%d", &startingPlace);

	// Offset = the place minus one
	startingPlace--;

	// Go on six places from the starting place
	for (counter = SIX; counter; counter--)
	{
		// Check where the player should move depends on what he gets in the cube
		newPlace = (places[startingPlace + counter] <= counter) ? (startingPlace + counter + ONE) : startingPlace - counter + ONE;
		printf("If you can get %hu, you will go to: %hu\n", counter, newPlace);
	}

	scanf("%hu", &counter);
}