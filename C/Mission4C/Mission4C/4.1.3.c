#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define TEN_TOUSEND 10000
#define ONE_HUNDRED 100

//--------------------------------------------------------------------------------------------
//											Numbers to Date
//										  -------------------
//
// General : The program gets time in numbers and change it to date.
//
// Input   : The number that presents the date.
//
// Process : The program gets time in numbers and change it to date.
//
// Output  : Prints the date.
//
//--------------------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 17.9.2019
//--------------------------------------------------------------------------------------------
void main3(void)
{
	// Variable definition
	unsigned int date;
	unsigned int temp;
	unsigned short day;
	unsigned short month;
	unsigned short year;

	printf("Give a date\n");
	scanf("%d", &date);

	// Seperate the time
	temp = date;
	year = temp % TEN_TOUSEND;
	temp /= TEN_TOUSEND;
	month = temp % ONE_HUNDRED;
	temp /= ONE_HUNDRED;
	day = temp;

	printf("The year is %hu, the month is %hu, and the day is %hu", year, month, day);
	scanf("%d", &date);
}