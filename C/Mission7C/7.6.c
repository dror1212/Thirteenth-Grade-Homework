#pragma once

#include "DrorGeneral.h"

//-----------------------------------------------------------------------------------------------
//											More than the avarege
//										 ---------------------------
//
// General : The program checks how many numbers are bigger than the avarege.
//
// Input   : 40 numbers.
//
// Process : The program checks how many numbers are bigger than the avarege.
//
// Output  : The amount of numbers that are bigger than the avarege.
//
//-----------------------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 18.10.2019
//-----------------------------------------------------------------------------------------------
void main6A(void)
{
	// Variable definition
	unsigned short precent[LENGTH_OF_VECTOR]; //40
	unsigned short counter;
	unsigned short sum = ZERO;
	float average;
	unsigned short moreThanAverage = ZERO;

	printf("Give the numbers\n");

	// Get fourty numbers
	for (counter = ZERO; counter < LENGTH_OF_VECTOR; counter++)
	{
		scanf("%hu", &precent[counter]);
	}

	// Calculate the average of the numbers
	average = Average(precent);

	printf("%f\n", average);

	// Count how many there are that are bigger than the average
	moreThanAverage = CountBigger(precent, average);

	printf("Result: %hu", moreThanAverage);

	scanf("%hu", &counter);
}

//-----------------------------------------------------------------------------------------------
//											More than the 20
//										 ----------------------
//
// General : The program checks how many numbers are bigger than 20.
//
// Input   : 40 numbers.
//
// Process : The program checks how many numbers are bigger than 20.
//
// Output  : The amount of numbers that are bigger than 20.
//
//-----------------------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 18.10.2019
//-----------------------------------------------------------------------------------------------
void main6B(void)
{
	// Variable definition
	unsigned short precent[LENGTH_OF_VECTOR]; //40
	unsigned short counter;
	unsigned short sum = ZERO;
	unsigned short moreThanTwenty = ZERO;

	printf("Give the numbers\n");

	// Get fourty numbers
	for (counter = ZERO; counter < LENGTH_OF_VECTOR; counter++)
	{
		scanf("%hu", &precent[counter]);
	}

	// Count how many are bigger than twenty
	moreThanTwenty = CountBigger(precent, TWENTY);

	printf("Result: %hu", moreThanTwenty);

	scanf("%hu", &counter);
}

//--------------------------------------------------------------------------------------------
//											Average
//										 --------------
//
// General		: The function calculates the average.
//
// Parameters   :
//			vec  - The vector where the numbers are.
//
// Return Value : The average.
//
//--------------------------------------------------------------------------------------------
float Average(int vec[])
{
	int ave = ZERO;
	int counter;
	int sum;
	for (counter = LENGTH_OF_VECTOR - ONE; counter; counter--)
	{
		sum += vec[counter];
	}

	return ((float)sum / LENGTH_OF_VECTOR);
}

//--------------------------------------------------------------------------------------------
//											Count Bigger
//										 -----------------
//
// General		: The function count how many numbers are bigger than the given one in the vec.
//
// Parameters   :
//			vec  - The vector where the numbers are.
//			num  - The number.
//
// Return Value : How many numbers are bigger than num.
//
//--------------------------------------------------------------------------------------------
unsigned short CountBigger(int vec[], int num)
{
	int counter;
	int bigger = ZERO;
	for (counter = LENGTH_OF_VECTOR - ONE; counter; counter--)
	{
		bigger += (vec[counter] > num) ? ONE : ZERO;
	}

	return (bigger);
}