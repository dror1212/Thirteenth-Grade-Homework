#pragma once
#include "General.h"

void main(void)
{
	int sum = ZERO;
	int temp = ZERO;
	int mat[M][N] = { {-11,-7,-3,-4,-5},{-8,-7,-8,424,-10},{-11,-5,-13,-14,-15},{-16,-17,-18,-19,-20},{-21,-22,-23,-24,-25} ,{-5,-52,-13,-44,-15} };
	int helpX;
	int helpY;
	int temp2 = M - ONE;
	int temp3;

	while (temp < N)
	{
		helpY = ZERO;
		helpX = ZERO;
		while (helpY < M + ONE)
		{
			temp3 = SumOfDirectionInMatrix(mat, temp, (temp2 > ZERO) ? (temp2 - helpY) : (temp2 + helpY), N - helpX, M, ONE, ONE);
			sum = (temp3 > sum) ? temp3 : sum;

			if (helpX == N)
			{
				helpY++;
				helpX = ZERO;
			}
			helpX++;
		}
		(temp2) ? temp2-- : temp++;
	}
	printf("%d", sum);
	_getche();
}
