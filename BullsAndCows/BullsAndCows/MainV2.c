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
		CountAmmountOfNumbers(players[!turn], guess);

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
//			playerNumber - The offset of the other player
//			guess - The guess of the player
//			hits - The vector where the info is saved
//
// Return Value : None.
//
//--------------------------------------------------------------------------------------------
void CheckHits(unsigned short playerNumber, unsigned short guess, unsigned short hits[])
{
	// Variable definition
	unsigned short counter = ZERO;

	// Check if there is a hit
	for (; playerNumber + guess; playerNumber /= TEN, guess /= TEN, counter++)
	{
		hits[counter] = (playerNumber % TEN == guess % TEN) ? ONE : ZERO;
	}
}