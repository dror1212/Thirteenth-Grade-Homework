#pragma once

#include "DrorGeneral.h"

//--------------------------------------------------------------------------------------------
//											Bulls And Cows
//										  ----------------
//
// General : The program is the game Bulls And Cows.
//
// Input   : None
//
// Process : The program get guesses from the players, let them know how close were they to
//			 the answer and they keep going untill it's done.
//
// Output  : The proccess of the game, who is the winner.
//
//--------------------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 15.10.2019
//--------------------------------------------------------------------------------------------
void main(void)
{
	// Variable definition
	unsigned short players[TWO] = { 1234, 5679 };
	unsigned short turn = ONE;
	unsigned short guess;
	unsigned short turnsToWin = ZERO;
	unsigned short hits[TEN] = { ZERO };
	unsigned short amountOfHits = ZERO;
	unsigned short amountOfKliaa;
	enum BOOLEAN goOn = TRUE;

	// Go until someone guess correctly
	while (amountOfHits < FOUR)
	{
		// Empty the vector
		EmptyAVector(hits, TEN);

		// Change to the other player turn
		turn = !turn;

		// Go untill the number is valid
		while (goOn)
		{
			printf("Player %hu give a guess\n", turn + ONE);
			scanf("%hu", &guess);

			// Check if the number is valid (four digits long)
			(NumOfDigits(guess) == FOUR) ? (goOn = FALSE) : (goOn = TRUE);
		}
		goOn = TRUE;

		// Count what turn is it
		turnsToWin += (!turn);

		// Calculate the hits and kliaas
		CountAmmountOfNumbers(players[!turn], hits);
		CountAmmountOfNumbers(guess, hits);

		// Count the hits
		amountOfHits = CheckHit(players[!turn], guess, hits);

		// Count the kliaas
		amountOfKliaa = CheckKliaas(hits);

		printf("Player %hu hit %hu times and kala %hu times\n", turn + ONE, amountOfHits, amountOfKliaa);
	}

	printf("Player %hu won, it took him %hu turns\n", turn + ONE, turnsToWin);
	scanf("%hu", &guess);
}

//--------------------------------------------------------------------------------------------
//											Check Hits
//										------------------
//
// General		: The function gets the guess and the numbers, check if there are any hits.
//
// Parameters   :
//			playerNumber - The number of the other player
//			guess - The guess of the player
//			hits - The vector where the info is saved
//
// Return Value : The amount of hits.
//
//--------------------------------------------------------------------------------------------
unsigned short CheckHit(unsigned short playerNumber, unsigned short guess, unsigned short hits[])
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
//											Check Kliaa
//										------------------
//
// General		: The function gets the vector and check if there are kliaas.
//
// Parameters   :
//			hits - The vector where to count from
//
// Return Value : The amount of kliaas.
//
//--------------------------------------------------------------------------------------------
unsigned short CheckKliaas(unsigned short hits[])
{
	// Variable definition
	unsigned short counter;
	unsigned short amountOfKliaa = ZERO;

	// Check if there is a kliaa
	for (counter = ZERO; TEN - counter; counter++)
	{
		amountOfKliaa += (hits[counter] >= TWO) ? ONE : ZERO;
	}

	return (amountOfKliaa);
}

//--------------------------------------------------------------------------------------------
//											Num Of Digits
//										  -----------------
//
// General		: The function gets a number and checks what is his length.
//
// Parameters   :
//			number - The number
//
// Return Value : None.
//
//--------------------------------------------------------------------------------------------
unsigned int NumOfDigits(unsigned int number)
{
	// Variable definition
	unsigned int counter = ZERO;

	// Go on all the values in the vector
	for (; number; number /= TEN + counter++ * ZERO) {}

	return (counter);
}

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
void EmptyAVector(int vec[], int length)
{
	// Go on all the values in the vector
	for (length--; length > -ONE; length--)
	{
		vec[length] = ZERO;
	}
}