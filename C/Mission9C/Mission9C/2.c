#pragma once

#include "General.h"

//---------------------------------------------------------------------------------------
// 											Latin Cube
// 											----------
//
// General 	: the program checks if the cube is a latin cube.
//
// Input 	: a matrix.
//
// Process 	: the program checks if there are similar numbers on the same row or column,
//			  for every row and column in the cube.
//
// Output 	: 0 - the cube isn't latin cube.
//			  1 - the cube is latin cube.
//
//---------------------------------------------------------------------------------------
// Programer 	: Dror Tal
// Student No 	: 322534796
// Date 		: 1.11.2019
//---------------------------------------------------------------------------------------
void main2(void)
{
	// Variable definition
	unsigned short mat[THREE][THREE] = { { 1,2,3 },{ 3,3,3 },{ 4,6,5 } };
	unsigned short counter;
	unsigned short array_counter[TEN] = { ZERO };
	unsigned short result = ONE;

	// Go on all the cube
	for (counter = ZERO; counter < THREE; counter++)
	{
		// Clear the array
		Clear_Array(array_counter, TEN);

		// Check the row
		InRow(mat[counter], THREE, array_counter);
		result = (DigitInArray(array_counter, TWO, TEN)) ? ZERO : result;

		// Clear the array
		Clear_Array(array_counter, TEN);

		// Check the col
		InCol(mat, counter, THREE, array_counter);
		result = (DigitInArray(array_counter, TWO, TEN)) ? ZERO : result;

		// Clear the array
		Clear_Array(array_counter, THREE);
	}
	printf("%hu\n", result);
	scanf("%hu", &counter);
}