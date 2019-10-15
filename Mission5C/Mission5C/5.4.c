#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define TWO 2.0
#define ZERO 0
#define TEN 10
#define ABSOLUTE(x) ((x > ZERO)? x : -x)
#define MAX(a,b) ((a + b) / TWO + ABSOLUTE((a - b) / TWO))
#define LOW_NUMBER -99999

//--------------------------------------------------------------------------------------------
//											Max and Lower Max
//										   -------------------
//
// General : The program checks if the enswer and prints it.
//
// Input   : The a, b, c of the equation.
//
// Process : The program checks if the enswer and prints it.
//
// Output  : Prints the answer of the equation.
//
//--------------------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 22.9.2019
//--------------------------------------------------------------------------------------------
void main4(void)
{
	// Variable definition
	int number;
	int max = LOW_NUMBER;
	int lowerMax = LOW_NUMBER;
	unsigned short counter = TEN;

	// Go ten times
	for (; counter; counter--)
	{
		scanf("%d", &number);

		// Check if the number is bigger then the max anf if not, bigger then the lower max
		(max > number) ? (lowerMax = (int)MAX(number, lowerMax)) : (lowerMax = max, max = number);
	}

	printf("max: %d", max);
	printf("lower max: %d", lowerMax);
	scanf("%d", &number);
}