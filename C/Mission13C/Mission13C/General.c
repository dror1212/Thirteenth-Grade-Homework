#pragma once

#include "general.h"

unsigned int MaxStreak(char *ptrStr)
{
	int counter = ONE;
	int max = counter;
	while(((*(++ptrStr)) !='\0'))
	{
		counter = ((*ptrStr) == (*(ptrStr - ONE))) ? ++counter : ZERO;
		printf("%d\n", counter);
		max = (counter > max) ? counter : max;
	}

	return max;
}

unsigned int MaxStreakInVec(char **ptrStr, int numOfRows)
{
	int max = ZERO;
	int strNum = ZERO;
	int temp;
	char ** ptrStart = ptrStr;
	char ** ptrEnd = ptrStr + numOfRows;
	while (ptrStr != ptrEnd)
	{
		temp = MaxStreak((*(ptrStr)));
		if (temp > max)
		{
			max = temp;
			strNum = ptrStr - ptrStart;
		}
		ptrStr++;
	}
	printf("max :%d\n", max);

	return strNum;
}

