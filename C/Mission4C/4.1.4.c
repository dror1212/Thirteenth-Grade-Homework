#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define TEN_TOUSEND 10000
#define ONE_HUNDRED 100
#define THREE 3
#define ONE 1
#define ZERO 0
#define TWO 2

//--------------------------------------------------------------------------------------------
//											Check The Season
//										  --------------------
//
// General : The program get the date, take the month and check what season it is.
//
// Input   : The number that presents the date.
//
// Process : The program get the date, take the month and check what season it is using math.
//
// Output  : Prints what season is it.
//
//--------------------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 17.9.2019
//--------------------------------------------------------------------------------------------
void main4(void)
{
	// Variable definition
	unsigned int date;
	unsigned int temp;
	unsigned short month;
	unsigned short status;
	unsigned short season;

	printf("Give a date\n");
	scanf("%d", &date);

	// Gets the month
	temp = date;
	temp /= TEN_TOUSEND;
	month = temp % ONE_HUNDRED;
	
	// Check what season it is
	status = month / THREE;
	switch (status)
	{
	case 1:
		season = ZERO;
		break;
	case 2:
		season = ONE;
		break;
	case 3:
		season = TWO;
		break;
	case 4:
	case 0:
		season = THREE;
	}

	printf("If the reult is 0 the season is spring\n");
	printf("If the reult is 1 the season is summer\n");
	printf("If the reult is 2 the season is fall\n");
	printf("If the reult is 3 the season is winter\n");
	printf("Result: %hu", season);
	scanf("%d", &date);
}