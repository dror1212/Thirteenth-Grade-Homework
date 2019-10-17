#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ZERO 0
#define TWO 2.0
#define ABSOLUTE(x) ((x > ZERO)? x : -x)
#define MAX(a,b) ((a + b) / TWO + ABSOLUTE((a - b) / TWO))
#define MIN(a,b) ((a + b) / TWO - ABSOLUTE((a - b) / TWO))
#define LOW_NUMBER -99999

//--------------------------------------------------------------------------------------------
//											Max Min and Sum
//										   ------------------
//
// General : The program calculates the biggest, smallest and the sum out of some numbers.
//
// Input   : The amount of numbers and the numbers.
//
// Process : The program calculates the biggest, smallest and the sum out of some numbers.
//
// Output  : Print the biggest, smallest and the sum.
//
//--------------------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 21.9.2019
//--------------------------------------------------------------------------------------------
void main5(void)
{
	// Variable definition
	unsigned short counter;
	double sum;
	double number;
	double max;
	double min;

	printf("What is the length?\n");
	scanf("%hu", &counter);

	// Check all the numbers
	for(sum = ZERO, max = LOW_NUMBER, min = -LOW_NUMBER; counter; counter--)
	{
		printf("Give a nmuber\n");
		scanf("%lf", &number);

		//Take the max and min numbers
		max = MAX(number, max);
		min = MIN(number, min);

		sum += number;
	}

	printf("sum: %lf\n",sum);
	printf("max: %lf\n", max);
	printf("min: %lf\n", min);
	scanf("%lf", &number);
}