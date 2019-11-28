#include "General.h"

int * EvenSubArray(int vec[], int len, int *ptrEven)
{
	int counter;
	(*ptrEven) = ZERO;
	int * ptrStart;
	for (ptrStart = NULL,counter = ZERO; counter < len; counter++)
	{
		if (!(vec[counter] % TWO))
		{
			ptrStart = realloc(ptrStart,sizeof(int) *++(*ptrEven));
			*(ptrStart + (*ptrEven) - ONE) = vec[counter];
		}
	}
	
	return ptrStart;
}

int * OddSubArray(int vec[], int len, int *ptrEven)
{
	int counter;
	(*ptrEven) = ZERO;
	int * ptrStart;
	for (ptrStart = NULL, counter = ZERO; counter < len; counter++)
	{
		if ((vec[counter] % TWO))
		{
			ptrStart = realloc(ptrStart, sizeof(int) *++(*ptrEven));
			*(ptrStart + (*ptrEven) - ONE) = vec[counter];
		}
	}

	return ptrStart;
}

void SearchLongestWord(char S[], char ** L)
{
	char * ptrS = S;
	char * ptrEnd = ptrS + Length(ptrS, '\0');
	char * longest = ptrS;
	char * ptrMaxLen;
	char * ptrEndOfLongest;
	int help = ZERO;
	int longestLength = ZERO;

	while (ptrS < ptrEnd)
	{
		help = Length(ptrS, ' ');
		printf("%d\n", help);
		if (help > longestLength)
		{
			longestLength = help;
			longest = ptrS;
		}
		ptrS += help + ONE;
	}

	ptrMaxLen = malloc(sizeof(int)*(longestLength + ONE));
	(*L) = ptrMaxLen;
	ptrEndOfLongest = ptrMaxLen + longestLength;

	while (ptrMaxLen < ptrEndOfLongest)
	{
		*ptrMaxLen = *longest;
		ptrMaxLen++;
		longest++;
	}

	(*ptrMaxLen) = '\0';
}

int Length(char *strPtr, char whereToStop)
{
	int counter = ZERO;

	for (; ((*(strPtr)) != whereToStop) * (((*(strPtr)) != '\0')); counter++)
	{
		strPtr++;
	}
	return counter;
}

int Len(int number)
{
	int counter;

	for (counter = ZERO; number; number /= TEN, counter++);

	return counter;
}

int * createAMatrixFromAmountOfDigits(int howManyNums, int howManyDigits)
{
	int number;
	int * ptrStart = malloc(sizeof(int)*howManyDigits*howManyNums);
	int * ptr = ptrStart;
	int * ptrEnd = ptr + howManyNums * howManyDigits;
	int newNumber;

	while (ptr < ptrEnd)
	{
		printf("Give a number");
		scanf("%d", &number);
		if (Len(number) >= howManyDigits)
		{
			newNumber = createANumberFromNumber(number, howManyDigits);
			for (;newNumber; newNumber/=TEN)
			{
				(*ptr) = newNumber % TEN;
				ptr++;
			}
		}
		else
		{
			printf("The number is too short, please give a new number\n");
		}
	}

	return ptrStart;
}

int createANumberFromNumber(int number, int newLength)
{
	int newNumber = number;

	if (newLength <= Len(number))
	{
		newNumber = ZERO;
		for (; newLength; newLength--, newNumber = newNumber * TEN + (number % TEN), number/=TEN);
	}
	return newNumber;
}

void seperateEvenAndOddPointers(int vec[], int length, int * evenSize, int **even, int *oddSize, int **odd)
{
	(*even) = EvenSubArray(vec, length, evenSize);
	(*odd) = OddSubArray(vec, length, oddSize);
}

void alphabeticOrder(char * names[], int length)
{
	unsigned short check = FALSE;
	unsigned short toCheck = TRUE;
	char ** ptrHelp = names;
	char ** ptrStart = names;
	char ** ptrCheck = names;
	char ** ptrTemp;
	char ** ptrEnd = names + length;
	short counter;

	while (toCheck + check)
	{
		if (!toCheck)
		{
			check = FALSE;
			toCheck = TRUE;
		}
		counter = ZERO;
		printf("check\n");
		while (((**ptrHelp) != '\0') * ((**ptrCheck) != '\0') * (**ptrCheck) == (**ptrHelp))
		{
			(*ptrCheck)++;
			(*ptrHelp)++;
			counter++;
		}
		if (((**ptrHelp) != '\0') * ((**ptrCheck) != '\0') * ((**ptrCheck) < (**ptrHelp)))
		{
			ptrTemp = &(*ptrHelp);
			(*ptrHelp) = &(*ptrCheck);
			(*ptrCheck) = (*ptrTemp);
			check = TRUE;
		}

		(*ptrCheck) -= counter;
		(*ptrHelp) -= counter;

		ptrHelp++;
		if (ptrHelp == ptrEnd)
		{
			ptrCheck++;
			ptrHelp = ptrCheck;
			toCheck = FALSE;
		}
		if (ptrCheck >= ptrEnd)
		{
			ptrCheck = ptrStart;
			ptrHelp = ptrStart;
		}
	}
}