#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define TWO 2
#define ONE 1
#define ZERO 0
#define TEN 10
#define EOD 6666

#define POWER(base,power)\
answer = ONE;\
lastBase = base;\
while (power)\
{\
answer *= (power % TWO) ? lastBase : ONE;\
lastBase *= lastBase;\
power /= TWO;\
}\

//--------------------------------------------------------------------------------------------
//											Bigger Than The Memuza
//										  --------------------------
//
// General : The programs get numbers and checks how many of them bigger than the memuza.
//
// Input   : Numbers.
//
// Process : The programs get numbers and checks how many of them bigger than the memuza.
//
// Output  : Prints how many nombers are bigger than the memuza.
//
//--------------------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 22.9.2019
//--------------------------------------------------------------------------------------------
void main(void)
{
	// Variable definition
	unsigned long long numbersHolder = ZERO;
	unsigned short counter = ZERO;
	unsigned long long lengthHolder = ZERO;
	unsigned int number = ZERO;
	unsigned int sum = ZERO;
	double memuza = ZERO;
	unsigned short temp;
	unsigned int temp2;
	unsigned short moreThenTheMemuza = ZERO;
	unsigned short length;
	unsigned long long answer;
	unsigned int lastBase;
	unsigned int tempNumber;

	printf("Give a number\n");
	scanf("%u", &number);

	//Go untill you get the EOD
	while (number != EOD)
	{
		sum += number;
		counter++;
		tempNumber = number;

		for (length = ZERO; tempNumber; tempNumber /= TEN + length++ * ZERO) {};

		lengthHolder = lengthHolder * TEN + length;

		POWER(TEN, length);

		numbersHolder = numbersHolder * answer + number;

		printf("Give a number\n");
		scanf("%u", &number);
	}

	// Calculate the memuza
	memuza = (double)sum / counter;

	// Check all the numbers if they are more than the memuza
	for (; lengthHolder; lengthHolder /= TEN)
	{
		temp = lengthHolder % TEN;

		POWER(TEN, temp);

		temp2 = numbersHolder % answer;
		numbersHolder /= answer;
		moreThenTheMemuza += (memuza < temp2) ? ONE :	ZERO;
	}

	printf("memuza: %lf\n", memuza);
	printf("more: %hu", moreThenTheMemuza);
	scanf("%u", &number);
}