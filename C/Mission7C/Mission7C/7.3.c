#pragma once

#include "DrorGeneral.h"

void main3(void)
{
	unsigned short nihush;
	int nums[LENGTH_OF_VECTOR] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }; //20
	unsigned short counter = ONE;
	unsigned short equals = ZERO;
	for (; counter < LENGTH_OF_VECTOR; counter++)
	{
		equals += (nums[counter - ONE] == nums[counter]) ? ONE : ZERO;
	}

	printf("result: %hu", equals);
	scanf("%hu", &equals);
}