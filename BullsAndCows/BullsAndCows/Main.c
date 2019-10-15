#pragma once

#include "DrorGeneral.h"

void main(void)
{
	unsigned short players[TWO] = { 1234, 5679 };
	unsigned short turn = ONE;
	unsigned short guess;
	unsigned short turnsToWin = ZERO;
	unsigned short hits[FOUR] = { ZERO };
	unsigned short amountOfHits = ZERO;
	unsigned short amountOfKliaa;

	while (amountOfHits < FOUR)
	{
		EmptyAVector(hits, FOUR);

		turn = !turn;

		printf("Player %hu give a guess\n", turn + ONE);
		scanf("%hu", &guess);

		turnsToWin += (!turn);

		CheckHits(players[!turn], guess, hits);
		CheckKliaa(players[!turn], guess, hits);

		amountOfHits = SumOfDigits(hits, FOUR, ONE);
		amountOfKliaa = SumOfDigits(hits, FOUR, TEN);
		printf("Player %hu hit %hu times and kala %hu times\n", turn + ONE, amountOfHits, amountOfKliaa);
	}

	printf("Player %hu won, it took him %hu turns\n", turn + ONE, turnsToWin);
	scanf("%hu", &guess);
}

void CheckHits(unsigned short playerNumber, unsigned short guess, unsigned short hits[])
{
	unsigned short counter = ZERO;
	for (; playerNumber + guess; playerNumber /= TEN, guess /= TEN, counter++)
	{
		hits[counter] = (playerNumber % TEN == guess % TEN) ? ONE : ZERO;
	}
}

void CheckKliaa(unsigned short playerNumber, unsigned short guess, unsigned short hits[])
{
	unsigned short counter;
	unsigned short secondCounter;
	unsigned short numberHolder;

	for (counter = ZERO; guess; counter++, guess /= TEN)
	{
		for (numberHolder = playerNumber, secondCounter = ZERO; numberHolder; secondCounter++, numberHolder /= TEN)
		{
			hits[counter] += ((numberHolder % TEN == guess % TEN) * (!hits[secondCounter])) ? TEN : ZERO;
		}
	}
}