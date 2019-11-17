#pragma once

#include "general.h"

void main(void)
{
	char * arr[5];
	string arr2 [5];
	int i;
	for (i = 0; i < 5; i++)
	{
		arr[i] = arr2[i];
	}

	for (i = 0; i < 5; i++)
	{
		gets(arr[i]);
	}

	printf("%d\n", MaxStreakInVec(arr, 5));
	scanf("%d", &i);
}