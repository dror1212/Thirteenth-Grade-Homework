#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ONE 1
#define THREE 3
//--------------------------------------------------------------------------------------------
//											Three Multiplayer
//										   --------------------
//
// General : The program calculates the min exponent of three that is bigger than the given number.
//
// Input   : A number.
//
// Process : Multiply the number by three untill it's bigger than the given number.
//
// Output  : PPrints the number.
//
//--------------------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 22.9.2019
//--------------------------------------------------------------------------------------------
void main3(void)
{
	// Variable definition
	unsigned int num;
	unsigned short counter;
	printf("Give a number\n");
	scanf("%d", &num);

	// Multiply the number by three untill it's bigger than the given number
	for (counter = ONE; counter < num; counter = counter * THREE) {};

	printf("\n%hu", counter);
	scanf("%d", &num);
}