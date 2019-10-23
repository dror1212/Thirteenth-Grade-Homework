#pragma once

#include "DrorGeneral.h"

//--------------------------------------------------------------------------------------------
//											Num Of Digits
//										  -----------------
//
// General		: The function gets a number and checks what is his length.
//
// Parameters   :
//			number - The number
//
// Return Value : None.
//
//--------------------------------------------------------------------------------------------
unsigned int NumOfDigits(unsigned int number)
{
	// Variable definition
	unsigned int counter = ZERO;

	// Go on all the values in the vector
	for (; number; number /= TEN + counter++ * ZERO) {}

	return (counter);
}

//--------------------------------------------------------------------------------------------
//											Sum Of Digits
//										  -----------------
//
// General		: The function gets a vector and a place to take the digits from.
//
// Parameters   :
//			vec - The vector
//			length - The length of the vector
//			digits - What digit to take (first, second, third and more)
//
// Return Value : None.
//
//--------------------------------------------------------------------------------------------
unsigned short SumOfDigits(unsigned short check[], unsigned short length, unsigned int digits)
{
	// Variable definition
	unsigned short counter = ZERO;
	unsigned int temp;

	// Go on all the values in the vector
	for (int i = ZERO; i < length; i++)
	{
		// Take the sum of a specific digits
		temp = check[i] % (digits * TEN) / digits;
		counter += temp;
	}
	return (counter);
}

//--------------------------------------------------------------------------------------------
//											Empty Vector
//										  ----------------
//
// General		: The function gets a vector and empty it.
//
// Parameters   :
//			vec - The vector
//			length - The length of the vector
//
// Return Value : None.
//
//--------------------------------------------------------------------------------------------
void EmptyAVector(int vec[], int length)
{
	// Go on all the values in the vector
	for (length--; length > - ONE; length--)
	{
		vec[length] = ZERO;
	}
}