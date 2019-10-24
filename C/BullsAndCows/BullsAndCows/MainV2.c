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
	unsigned short players[TWO] = {ZERO};
	unsigned short turn;
	unsigned short guess;
	unsigned short turnsToWin = ZERO;
	unsigned short amountOfAccurateHits = ZERO;
	unsigned short amountOfHits;
	unsigned short hits[TEN] = { ZERO };
	BOOLEAN goOn = TRUE;

	// Get the two numbers of the users
	for (turn = ZERO; TWO - turn; turn++)
	{
		while (goOn)
		{
			// Make sure the vector is empty
			EmptyAVector(hits, TEN);

			printf("Player %hu what is your number?\n", turn + ONE);
			scanf("%hu", &players[turn]);

			// Check if the numbers are 4 digits length
			goOn = (IS_VALID(players[turn])) ? FALSE : TRUE;

			// Check if no digits are repeating
			CountAmmountOfNumbers(players[turn], hits);
			goOn += (CheckHits(hits)) ? TRUE : FALSE;
		}
		goOn = TRUE;
	}
	goOn = TRUE;

	// Go until someone guess correctly
	while (amountOfAccurateHits < FOUR)
	{
		// Empty the vector
		EmptyAVector(hits, TEN);

		// Change to the other player turn
		turn = !turn;

		// Count what turn is it
		turnsToWin += !turn;
		printf("turn : %hu\n", turnsToWin);
		// Go untill the number is valid
		while (goOn)
		{
			printf("Player %hu give a guess\n", turn + ONE);
			scanf("%hu", &guess);

			// Check if the number is valid (four digits long)
			goOn = (IS_VALID(guess)) ? FALSE : goOn;
		}
		goOn = TRUE;

		// Calculate the accurate hits and hits
		CountAmmountOfNumbers(players[!turn], hits);
		CountAmmountOfNumbers(guess, hits);

		// Count the accurate hits
		amountOfAccurateHits = CheckAccurateHits(players[!turn], guess, hits);

		// Count the hits
		amountOfHits = CheckHits(hits);

		printf("Player %hu accurate hit %hu times and hit %hu times\n", turn + ONE, amountOfAccurateHits, amountOfHits);
	}

	printf("Player %hu won, it took him %hu turns\n", turn + ONE, turnsToWin);
	scanf("%hu", &guess);
}