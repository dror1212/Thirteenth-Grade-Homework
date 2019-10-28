#pragma once

#include "General.h"

void main6(void)
{
	int mat_og[SEVEN][SEVEN] = { {1,2,3,4,5,6,7},{8,9,10,11,12,13,14},{15,16,17,18,19,20,21},{22,23,24,25,26,27,28},{29,30,31,32,33,34,35},{36,37,38,39,40,41,42},{43,44,45,46,47,48,49} };
	int mat_new[SIX][SIX];

	unsigned int m = FIVE;
	unsigned int n = THREE;

	unsigned short counter_og = ZERO;
	unsigned short counter_new = ZERO;

	for (; counter_og < SEVEN * SEVEN; ++counter_og)
	{
		mat_new[counter_new / SIX][counter_new % SIX] = mat_og[counter_og / SEVEN][counter_og % SEVEN];
		(counter_og / SEVEN == m || counter_og % SEVEN == n) ? counter_new : counter_new++;
	}

	printMatrix(mat_new, SIX);

	scanf("%hu", &counter_og);
}