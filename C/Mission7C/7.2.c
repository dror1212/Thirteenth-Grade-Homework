#pragma once

#include "DrorGeneral.h"

//--------------------------------------------------------------------------------------------
//											Where can I move
//										 ----------------------
//
// General : The program checks where the player can move and tells him.
//
// Input   : The boared status, the place of the player.
//
// Process : The program checks where the player can move and tells him.
//
// Output  : Prints where the player can go.
//
//--------------------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 17.10.2019
//--------------------------------------------------------------------------------------------
void main2(void)
{
	// Variable definition
	unsigned short nihush;
	int places[LENGTH_OF_VECTOR]; //30
	unsigned short startingPlace;
	unsigned short counter;
	unsigned int canGet = ZERO;
	printf("Give the numbers");

	// Get thirty numbers that represent the boared
	for (counter = ZERO; counter < LENGTH_OF_VECTOR; counter++)
	{
		scanf("%d", &places[counter]);
	}

	printf("Give ypur place");
	scanf("%d", &startingPlace);

	// Offset = the place minus one
	startingPlace--;

	// Check all the options that you can get from the cube
	for (counter = SIX; counter; counter--)
	{
		// Check whether you can go there or not
		canGet = (places[startingPlace + counter] == ZERO) ? (canGet * TEN + counter) : (canGet);
	}

	// Print every place you can go
	for (; canGet; canGet /= TEN)
	{
		printf("You can get: %hu\n", canGet % TEN);
	}
	scanf("%hu", &counter);
}