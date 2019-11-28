#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//--------------------------------------------------------------------------------------------
//											Calculator
//										 -----------------
//
// General : The program calculates the result depends on the sign.
//
// Input   : The program gets two numbers and a sign.
//
// Process : The program calculates the result depends on the sign.
//
// Output  : Prints the result.
//
//--------------------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 11.9.2019
//--------------------------------------------------------------------------------------------
void main1(void)
{
	// Variable definition
	double firstNumber;
	double secondNumber;
	double answer;
	char charOperator;

	printf("Give two numbers and an operator\n");
	scanf("%lf %c %lf", &firstNumber, &charOperator, &secondNumber);

	// Check what is the sign between the numbers and calculate the result.
	switch (charOperator)
	{
		case '+':
			answer = firstNumber + secondNumber;
			break;
		case '-':
			answer = firstNumber - secondNumber;
			break;
		case '*':
			answer = firstNumber * secondNumber;
			break;
		case '/':
			answer = (double)firstNumber / secondNumber;
			break;
		case '%':
			answer = (int)firstNumber % (int)secondNumber;
	}
	printf("The answer is %lf", answer);
	scanf("%d %d %c", &firstNumber, &secondNumber, &charOperator);
}