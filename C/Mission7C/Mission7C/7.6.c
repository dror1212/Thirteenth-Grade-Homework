#pragma once

#include "DrorGeneral.h"

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