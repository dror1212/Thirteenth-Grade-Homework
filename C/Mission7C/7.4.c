#pragma once

#include "DrorGeneral.h"

//-----------------------------------------------------------------------------------------------
//											Like The Last Neighords
//										 -----------------------------
//
// General : The program checks if there are any neighords that have the same value as the last.
//
// Input   : 20 numbers.
//
// Process : The program checks if there are any neighords that have the same value as the last.
//
// Output  : Prints the ammount of neighords that are the same as the last.
//
//-----------------------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 17.10.2019
//-----------------------------------------------------------------------------------------------
void main4(void)
{
	// Variable definition
	unsigned short amount = ZERO;
	int chars[LENGTH_OF_VECTOR]; //20
	unsigned short counter;
	unsigned short lastOne = LENGTH_OF_VECTOR - ONE; // The last offset
	unsigned short minusOneLast = lastOne - ONE; // One before the last
	char holder;

	printf("Give the chars\n");

	// Get 20 chars
	for (counter = ZERO; counter < LENGTH_OF_VECTOR; counter++)
	{
		scanf("%c", &holder);
		chars[counter] = holder;
	}

	// Go untill you get to the one before the last one
	for (counter = ONE; counter < minusOneLast; counter++)
	{
		// Check if the neighors chars are equals to the last and one before chars
		amount += ((chars[counter - ONE] == chars[minusOneLast]) * (chars[counter] == chars[lastOne])) ? (ONE) : (ZERO);
	}

	printf("Amount: %hu", &amount);
	scanf("%hu", &counter);
}