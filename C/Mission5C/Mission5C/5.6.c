#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define TWO 2.0
#define THOUSAND 1000
#define ZERO 0
#define ABSOLUTE(x) ((x > ZERO)? x : -x)
#define MIN(a,b) ((a + b) / TWO - ABSOLUTE((a - b) / TWO))

//--------------------------------------------------------------------------------------------
//											Same Dividers
//										 -------------------
//
// General : The program checks what are the same dividers of two numbers up to 1000.
//
// Input   : Two numbers.
//
// Process : go on all the dividers and check if some are the same.
//
// Output  : The dividers of the two numbers that are the same.
//
//--------------------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 21.9.2019
//--------------------------------------------------------------------------------------------
void main6(void)
{
	// Variable definition
	unsigned int firstNumber;
	unsigned int secondNumber;
	int counter;

	printf("Give two numbers\n");
	scanf("%u %u", &firstNumber, &secondNumber);

	// Check what is the max numbers to go to
	counter = (unsigned int)MIN((firstNumber/TWO), (secondNumber/TWO));
	counter = (unsigned int)MIN(counter, THOUSAND);

	for (; counter; counter--)
	{
		// If the two numbers can be divided by the counter, print it
		((!(firstNumber % counter)) * (!(secondNumber % counter))) ? printf("%u\n", counter) : printf("");
	}

	scanf("%u %u", &firstNumber, &secondNumber);
}