#pragma once
// 3.2.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define TWO 2
#define FOUR 4
#define ZERO 0

#define NEWTON(x,a)(x / 2 + a /(2 * x))

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
// Date       : 17.9.2019
//--------------------------------------------------------------------------------------------
void main12(void)
{
	// Variable definition
	float a;
	float b;
	float c;
	float delta;
	float x;
	float x2;

	printf("three numbers\n");
	scanf("%f %f %f", &a, &b, &c);
	delta = b * b - FOUR * a * c;
	
	// Sqrt cant be negative
	if (delta < 0)
	{
		printf("there are no answers\n");
	}
	// One answer
	if (delta == ZERO)
	{
		x = -b / (TWO * a);
		printf("the answer is: %f\n", x);
	}
	// Two answers
	if (delta > 0)
	{
		// Calculate the sqrt of the delta
		x = delta;
		// Add more to be more accurate		
		x = NEWTON(x, delta);
		x = NEWTON(x, delta);
		x = NEWTON(x, delta);
		x = NEWTON(x, delta);
		x = NEWTON(x, delta);
		x = NEWTON(x, delta);
		x = NEWTON(x, delta);
		x = NEWTON(x, delta);
		x = NEWTON(x, delta);
		x = NEWTON(x, delta);
		x = NEWTON(x, delta);
		x = NEWTON(x, delta);

		// Calculate the two answers
		x2 = (-b + x) / (TWO * a);
		x = (-b - x) / (TWO * a);

		printf("the answeres are: %f, %f\n", x,x2);
	}
	scanf("%f %f %f", &a, &b, &c);	
}