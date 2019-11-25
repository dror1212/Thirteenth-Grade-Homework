#pragma once
#include "General.h"

BOOLEAN isEven(int num)
{
	return (!(num & ONE));
}

int calculateBitsInInt(BOOLEAN isSigned)
{
	return (sizeof(int) * BITS_IN_BYTE - isSigned);
}

double power(double number, int numberOfTimes)
{
	double answer = ONE;

	for (; numberOfTimes; numberOfTimes--)
	{
		answer *= number;
	}

	return (answer);
}

unsigned int rotationLeft(int num, int times)
{
	unsigned int help = (unsigned int)(power(TWO, calculateBitsInInt(ONE)));
	unsigned int temp;
	for (; times; times--)
	{
		temp = ((help & num) > ZERO);
		num = num << ONE;
		num += temp;
	}
	return num;
}

void RemoveBits(byte* row, unsigned short count, int*counter)
{
	*row >>= count;
	*counter -= count;
}

unsigned short CountBits(byte b)
{
	unsigned short counter = ZERO;
	unsigned short loop_lenght = sizeof(b) * BITS_IN_BYTE;
	while (loop_lenght--)
	{
		counter += !EvenNumber(b);
		b >>= ONE;
	}

	return (counter);
}

void PrintGetRow()
{
	printf("Enter row number (1-4): ");
}

void PrintGetRemoveCount()
{
	printf("Enter many bits: ");
}

unsigned short InputRow()
{
	unsigned short row;
	scanf("%hu", &row);

	return (row);
}

unsigned short SumBits(byte* vec, unsigned short lenght)
{
	unsigned short sum = ZERO;
	while (lenght--)
	{
		sum += CountBits(*(vec++));
	}

	return (sum);
}

void PrintBits(byte b)
{
	unsigned short lenght = sizeof(b) * BITS_IN_BYTE;
	while (lenght--)
	{
		printf("%hu,", !EvenNumber(b));
		b >>= ONE;
	}
}

void PrintRows(byte* rows, unsigned short lenght)
{
	while (lenght--)
	{
		PrintBits(*(rows++));
		printf("\n");
	}

}

byte* MaxBitsRow(byte* rows, unsigned short lenght)
{
	unsigned short max_count = ZERO;
	byte* max_row = rows;
	unsigned short temp_count;
	while (lenght--)
	{
		temp_count = CountBits(*rows);
		if (temp_count > max_count)
		{
			max_count = temp_count;
			max_row = rows;
		}
		rows++;
	}
	return (max_row);
}

void Bot(byte* rows, unsigned short lenght, int * counter)
{
	byte* max_row = MaxBitsRow(rows, lenght);

	RemoveBits(max_row, MAX(CountBits(*max_row) / TWO * TWO, ONE), counter); // - ONE
}
void Bot5(byte* rows, unsigned short lenght, int* counter)
{
	byte* max_row = MaxBitsRow(rows, lenght);

	RemoveBits(max_row, MAX(CountBits(*max_row) / TWO * TWO - ONE, ONE), counter); // - ONE
}