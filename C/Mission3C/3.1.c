#pragma once
// 3.2.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX(x,y) ((x > y) ? x : y)
#define	MIN(x,y) ((x < y) ? x : y)
#define SWITCH_NUMBERS(x,y)\
x = x + y;\
y = x - y;\
x = x - y;

//--------------------------------------------------------------------------------------------
//											 Max to Min
//										   --------------
//
// General : The program orgenizes the numbers from big to small or small to big.
//
// Input   : Three numbers and a sign.
//
// Process : The program gets three numbers, oreders them depends on the sign.
//
// Output  : Prints the numbers in the asked way.
//
//--------------------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 11.9.2019
//--------------------------------------------------------------------------------------------
void order(void)
{
	// Variable definition
	float firstNumber;
	float secondNumber;
	float thirdNumber;
	float first;
	float second;
	float third;
	char status;
	printf("give a sign and three numbers\n");
	scanf("%c %f %f %f", &status, &firstNumber, &secondNumber, &thirdNumber);

	// Order the numbers from big to small
	first = firstNumber;
	first = MAX(MAX(first, secondNumber), thirdNumber);
	third = MIN(MIN(firstNumber, secondNumber), thirdNumber);
	second = firstNumber + secondNumber + thirdNumber;
	second -= first + third;

	// Check the mode that was asked
	if (status == 'U')
	{
		SWITCH_NUMBERS(first, third);
		printf("%f %f %f", first, second, third);
	}
	// Check the mode that was asked
	else
	{
		// Check the mode that was asked
		if (status == 'D')
		{
			printf("%f %f %f", first, second, third);
		}
	}
	scanf("%c %f %f %f", &status, &firstNumber, &secondNumber, &thirdNumber);
}