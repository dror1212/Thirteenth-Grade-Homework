#pragma once

#include "DrorGeneral.h"

//--------------------------------------------------------------------------------------------
//											Are Neighords The Same
//										 ----------------------------
//
// General : The program checks if there are any neighords that have the same value.
//
// Input   : 20 numbers.
//
// Process : The program checks if there are any neighords that have the same value.
//
// Output  : Prints the ammount of neighords that are the same.
//
//--------------------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 17.10.2019
//--------------------------------------------------------------------------------------------
void main3(void)
{
	// Variable definition
	unsigned short nihush;
	int nums[LENGTH_OF_VECTOR]; //20
	unsigned short counter = ONE;
	unsigned short equals = ZERO;

	//Get the thirty numbers
	for (counter = ZERO; counter < LENGTH_OF_VECTOR; counter++)
	{
		scanf("%d", &nums[counter]);
	}

	// Go on all the vector
	for (counter =	ZERO; counter < LENGTH_OF_VECTOR; counter++)
	{
		//	Count the numbers are equals and one next to another
		equals += (nums[counter - ONE] == nums[counter]) ? ONE : ZERO;
	}

	printf("result: %hu", equals);
	scanf("%hu", &equals);
}