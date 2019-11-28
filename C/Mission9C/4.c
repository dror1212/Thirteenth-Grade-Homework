#pragma once
#include "General.h"

//---------------------------------------------------------------------------------------
//									New matrix in a matrix
//									----------------------
//
// General : The program checks where is the cube with the biggest number of zero in it.
//
// Input : None
//
// Process : The program checks where is the biggest sum of zero in the col and the row
//			  then return the starting point of x and y then it runs and on that matrix
//			  to sum up how many zero.
//
// Output : Starting point of the new matrix, how many zeros and the size of the matrix.
//
//---------------------------------------------------------------------------------------
// Programmer	 : Dror Tal
// Student No	 : 322987488
// Date			 : 1.11.2019
//---------------------------------------------------------------------------------------
void main(void)
{
	// Variable definition
	char mat[M][N] = { { '1','1','0','1','0' },{ '0','0','1','1','0' },{ '1','0','0','1','0' },{ '1','1','0','0','0' },{ '0','0','0','0','0' } };
	unsigned int L = 4;
	unsigned short row = ZERO;
	unsigned short col = ZERO;
	unsigned short smallestX = ZERO;
	unsigned short smallestY = ZERO;
	unsigned short sum = HIGH_NUMBER;
	unsigned short temp;

	// Go on all the matrix untill you go out of it
	while (row < M - L + ONE)
	{
		// Count the ammount of '1'
		temp = sumOfCharMatrix(mat, col, row, L);
		
		// Take the smallest ammount
		(temp < sum) ? (sum = temp),(smallestY = row), (smallestX = col) : sum;

		// Go on to the next offset in the matrix
		(col == (N - L)) ? (row++),(col = ZERO) : (col++);
	}

	printf("FROM [%hu][%hu], SIZE %d, %hu NULLS", smallestY, smallestX, L, L*L - sum);
	scanf("%hu", sum);
}