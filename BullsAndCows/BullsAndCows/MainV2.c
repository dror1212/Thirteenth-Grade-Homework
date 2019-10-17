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
	unsigned short temp;
	unsigned short temp2;
	unsigned short counter;
	enum BOOLEAN goOn = TRUE;

	// Go until someone guess correctly
	while (amountOfHits < FOUR)
	{
		amountOfHits = ZERO;
		amountOfKliaa = ZERO;
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

		for (temp = players[!turn], temp2 = guess; temp + temp2; temp /= TEN, temp2 /= TEN)
		{
			if (temp % TEN == temp2 % TEN)
			{
				amountOfHits += ONE;
				hits[temp % TEN] -= TWO;
			}
		}

		for (counter = ZERO; counter < TEN; counter++)
		{
			amountOfKliaa += (hits[counter] >= TWO) ? ONE : ZERO;
		}

		printf("Player %hu hit %hu times and kala %hu times\n", turn + ONE, amountOfHits, amountOfKliaa);
	}

	printf("Player %hu won, it took him %hu turns\n", turn + ONE, turnsToWin);
	scanf("%hu", &guess);
}

void CountAmmountOfNumbers(unsigned short number, unsigned short hits[])
{
	for (number; number; number /= TEN)
	{
		hits[number % TEN]++;
	}
}