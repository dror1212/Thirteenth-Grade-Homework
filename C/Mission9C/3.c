#pragma once

#include "General.h"

//---------------------------------------------------------------------------------------
// 											Magic Cube
// 											----------
//
// General 	: the program checks if the cube is a magic cube.
//
// Input 	: 9 numbers for the values of the matrix.
//
// Process 	: the program checks if there are similar numbers on the same row or column 
//			  or diagonals.
//
// Output 	: 0 - the cube isn't a magic cube.
//			  1 - the cube is a magic cube.
//
//---------------------------------------------------------------------------------------
// Programer 	: Dror Tal
// Student No 	: 322534793
// Date 		: 1.11.2019
//---------------------------------------------------------------------------------------
void main3(void)
{
	// Variable definition
	unsigned short mat[THREE][THREE] = { { 1,1,1 },{ 1,1,1 },{ 1,1,1 } };
	unsigned short counter;
	unsigned short array_counter[TEN] = { ZERO };
	unsigned short result;
	unsigned short sum;

	// Calculate the sum of the diagonals
	InDiagonal(mat, THREE, ONE, array_counter, ZERO);
	sum = SumOfVecCounter(array_counter, TEN);
	Clear_Array(array_counter, THREE);

	InDiagonal(mat, THREE, -ONE, array_counter, TWO);
	result = (sum == SumOfVecCounter(array_counter, TEN));
	Clear_Array(array_counter, THREE);

	// Go on all the rows and cols
	for (counter = ZERO; counter < THREE; counter++)
	{
		// Calculate the sum in a row
		Clear_Array(array_counter, TEN);
		InRow(mat[counter], THREE, array_counter);

		// Check if the sum is different or not
		result = (sum == SumOfVecCounter(array_counter, TEN));

		//Calcukate the sum in a col
		Clear_Array(array_counter, TEN);
		InCol(mat, counter, THREE, array_counter);

		// Check if the sum is different or not
		result = (sum == SumOfVecCounter(array_counter, TEN));
		Clear_Array(array_counter, THREE);
	}
	printf("%hu\n", result);
	scanf("%hu", &counter);
}