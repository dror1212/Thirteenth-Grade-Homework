#pragma once
#include "General.h"

void main(void)
{
	int sum = ZERO;
	int temp;
	int mat[M][N] = { {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25},{-112,-115,111,112,113} };
	for (int i = ZERO;i < N; i++)
	{
		temp = SumOfDirectionInMatrix(mat, i, ZERO, 5, 6, -ONE, ONE);
		printf("%d\n", temp);
		sum = (temp > sum) ? temp : sum;
	}
	printf("%d", sum);
	_getche();
}