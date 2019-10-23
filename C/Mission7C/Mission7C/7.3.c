#pragma once

#include "DrorGeneral.h"

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