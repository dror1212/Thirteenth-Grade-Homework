#pragma once
// 3.2.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define TWO 2
#define FOUR 4
#define ZERO 0

//--------------------------------------------------------------------------------------------
//											Quadratic Equation
//										   --------------------
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
// Date       : 11.9.2019
//--------------------------------------------------------------------------------------------
void solve(void)
{
	// Variable definition
	float a;
	float b;
	float c;
	float delta;
	float x;
	printf("three numbers\n");
	scanf("%f %f %f",&a, &b, &c);
	delta = b * b - FOUR * a * c;
	printf("%f\n",delta);
	// Sqrt cant be negative
	if (delta < 0) 
	{
		printf("there are no answers\n");
	}
	else
	{
		// One answer
		if (delta == ZERO)
		{
			x = -b / (TWO*a);
			printf("the answer is: %f\n",x);
		}
		// Two answers
		else
		{
			printf("there are two answers\n");
		}
	}
	scanf("%f %f %f", &a, &b, &c);
}