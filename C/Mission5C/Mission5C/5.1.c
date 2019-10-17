#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define TEN 10
#define BOOLEAN unsigned short
#define FALSE 0
#define TRUE 1

//--------------------------------------------------------------------------------------------
//											The Same Digits
//										  --------------------
//
// General : The program checks if there are equals digits in two numbers.
//
// Input   : Two numbers.
//
// Process : The program checks if there are equals digits in two numbers.
//
// Output  : Prints whether there are equal digits.
//
//--------------------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 22.9.2019
//--------------------------------------------------------------------------------------------
void main1(void)
{
	// Variable definition
	int firstNumber;
	int secondNumber;
	int firstCounter;
	int secondCounter;
	short firstTemp;
	short secondTemp;
	BOOLEAN check = FALSE;

	printf("Give two numbers\n");
	scanf("%d %d", &firstNumber, &secondNumber);

	// Check all the numbers in the number
	for (firstCounter = firstNumber; firstCounter; firstCounter = firstCounter / TEN)
	{
		firstTemp = firstCounter % TEN;

		// Check all the numbers in the other number
		for (secondCounter = secondNumber; secondCounter; secondCounter = secondCounter / TEN)
		{
			secondTemp = secondCounter % TEN;

			// If the numbers are equal
			check = (secondTemp == firstTemp) ? TRUE : check;
		}
	}
	printf("%hu",check);
	scanf("%d %d", &firstNumber, &secondNumber);
}