#pragma once

#include "DrorGeneral.h"

//--------------------------------------------------------------------------------------------
//											Is The Sum Exist
//										 ----------------------
//
// General : The program checks if the given sum can be created with the numbers in the vec.
//
// Input   : N numbers and the number S that you need to find.
//
// Process : The program checks if the given sum can be created with the numbers in the vec.
//
// Output  : Prints the result.
//
//--------------------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 17.10.2019
//--------------------------------------------------------------------------------------------
void main1(void)
{
	// Variable definition
	unsigned short nihush;
	int x[LENGTH_OF_VECTOR]; // 4
	int S;
	int temp;
	int counter;
	int secondCounter;
	enum  BOOLEAN exist = FALSE;

	printf("Give the sum and the array");
	scanf("%d", &S);

	// Get N ammount of numbers
	for (counter = ZERO; counter < LENGTH_OF_VECTOR; counter++)
	{
		scanf("%d", &x[counter]);
	}

	// Go on all the vector and look for pairs that their sum is S
	for (counter = ZERO; counter < LENGTH_OF_VECTOR; counter++)
	{
		for (secondCounter = counter + ONE; secondCounter < LENGTH_OF_VECTOR; secondCounter++)
		{
			// Check if the sum is equals to S
			exist = (x[counter] + x[secondCounter] == S) ? TRUE : exist;
		}
	}

	printf("result: %d", exist);
	scanf("%d", &S);
}