#pragma once

#include "DrorGeneral.h"

//--------------------------------------------------------------------------------------------
//											Empty Vector
//										  ----------------
//
// General		: The function gets a vector and empty it.
//
// Parameters   :
//			vec - The vector
//			length - The length of the vector
//
// Return Value : None.
//
//--------------------------------------------------------------------------------------------
void EmptyAVector(unsigned short vec[], int length)
{
	// Go on all the values in the vector
	for (--length; length > - ONE; vec[length--] = ZERO) {}
}

//--------------------------------------------------------------------------------------------
//											Check Accurate Hits
//										---------------------------
//
// General		: The function gets the guess and the numbers, check if there are any hits.
//
// Parameters   :
//			playerNumber - The number of the other player
//			guess - The guess of the player
//			hits - The vector where the info is saved
//
// Return Value : The amount of accurate hits.
//
//--------------------------------------------------------------------------------------------
unsigned short CheckAccurateHits(unsigned short playerNumber, unsigned short guess, unsigned short hits[])
{
	// Variable definition
	unsigned short counter = ZERO;
	unsigned short amountOfHits = ZERO;
	// Check if there is a hit
	for (; playerNumber + guess; playerNumber /= TEN, guess /= TEN, counter++)
	{
		if (playerNumber % TEN == guess % TEN)
		{
			amountOfHits += ONE;
			hits[guess % TEN] = ZERO;
		}
	}
	return (amountOfHits);
}

//--------------------------------------------------------------------------------------------
//									Count how mant time a digit exist
//								-----------------------------------------
//
// General		: The function gets a number and count how many times it exist.
//
// Parameters   :
//			number - The number
//			hits - The vector where the info is saved
//
// Return Value : None.
//
//--------------------------------------------------------------------------------------------
void CountAmmountOfNumbers(unsigned short number, unsigned short hits[])
{
	// Go on all the values in the vector
	for (number; number; number /= TEN)
	{
		hits[number % TEN]++;
	}
}

//--------------------------------------------------------------------------------------------
//											Check Hits
//										------------------
//
// General		: The function gets the vector and check if there are hitss.
//
// Parameters   :
//			hits - The vector where to count from
//
// Return Value : The amount of hits.
//
//--------------------------------------------------------------------------------------------
unsigned short CheckHits(unsigned short hits[])
{
	// Variable definition
	unsigned short counter;
	unsigned short amountOfHits = ZERO;

	// Check if there is a hits
	for (counter = ZERO; TEN - counter; counter++)
	{
		amountOfHits += (hits[counter] >= TWO) ? ONE : ZERO;
	}

	return (amountOfHits);
}