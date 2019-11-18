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

void copyMatrix(unsigned short * ptr, unsigned short *ptrHelp, int size)
{
	int counter;
	for (counter = ZERO; counter < size; counter++)
	{
		(*ptrHelp) = (*ptr);
		ptr++;
		ptrHelp++;
	}
}

BOOLEAN findSubInStr(char * strPtr, char * substringPtr)
{
	string help;
	unsigned short counter;
	unsigned short answer = FALSE;
	int len = Len(substringPtr);
	while ((!answer)*((*strPtr) != '\0'))
	{
		for (counter = ZERO;counter < len;counter++)
		{
			help[counter] = (*(strPtr++));
		}
		help[counter] = '\0';
		strPtr -= (len - ONE);
		answer += (equal(&help, substringPtr));
	}

	return answer;
}

int Len(char * strPtr)
{
	char * helpPtr = strPtr;
	while ((*(strPtr++)) != '\0');
	return (int)(strPtr - helpPtr) - ONE;
}

BOOLEAN equal(char * firstStrPtr, char * secondStrPtr)
{
	BOOLEAN check = (Len(firstStrPtr) == Len(secondStrPtr));
	while (((*firstStrPtr) != '\0') * (check))
	{
		check = ((*(firstStrPtr++)) == (*(secondStrPtr++))) ? check : FALSE;
	}
	return check;
}

BOOLEAN findStrInVecStr(char **ptrStr,int numOfRows)
{
	BOOLEAN check = FALSE;
	char ** ptrStart = ptrStr;
	char ** ptrEnd = ptrStr + numOfRows;
	char ** ptrHelp = ptrStr;
	while ((!check)*((ptrStr++) != ptrEnd));
	{
		while ((!check)*((ptrHelp++) != ptrEnd))
		{
			check = (ptrHelp != ptrStr) ? (findSubInStr((*(ptrHelp)), (*(ptrStr)))) : check;
		}
		ptrHelp = ptrStart;
	}
	return check;
}

BOOLEAN findStrInMatStr(char ***ptrStr, int numOfRows)
{
	BOOLEAN check = FALSE;
	char *** ptrStart = ptrStr;
	char *** ptrEnd = ptrStr + numOfRows;
	char *** ptrHelp = ptrStr;
	while ((!check)*((ptrStr++) != ptrEnd));
	{
		while ((!check)*((ptrHelp) != ptrEnd))
		{
			check = (ptrHelp != ptrStr) ? (findSubInStr((**ptrHelp), (**ptrStr))) : check;
			(*ptrHelp)++;
		}
		ptrHelp = ptrStart;
	}
	return check;
}