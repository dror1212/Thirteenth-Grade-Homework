#pragma once

#include "General.h"

int SumOfDirectionInMatrix(int mat[M][N], int startingX, int startingY, int endingX, int endingY, int directionX,int directionY)
{
	int sum = ZERO;
	int counter;
	int col = startingX;
	int row = startingY;
	for (; (row < endingY) * (col < endingX) * (row + directionY >= -ONE) * (col + directionX >= -ONE); row += directionY, col += directionX)
	{
		sum += mat[row][col];
	}

	return sum;
}

int getRow(int counter, int size)
{
	return counter / size;
}

int getCol(int counter, int size)
{
	return counter % size;
}