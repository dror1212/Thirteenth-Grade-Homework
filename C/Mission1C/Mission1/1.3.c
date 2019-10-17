// 1.3.c

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define DAYS_PER_YEAR 365
#define DAYS_PER_MONTH 30
#define DAYS_PER_WEEK 7
#define CALCULATE_YEARS (usNumOfDays / DAYS_PER_YEAR)
#define CALCULATE_MONTHS ((usNumOfDays % DAYS_PER_YEAR) / DAYS_PER_MONTH)
#define CALCULATE_WEEKS (((usNumOfDays % DAYS_PER_YEAR) % DAYS_PER_MONTH) / DAYS_PER_WEEK)

//-----------------------------------------------------------------------------------------------------
//										   Days to Time
//										  --------------
//
// General : The program calculate the years, months and weeks that passed in a given nomber of days.
//
// Input   : Number of days.
//
// Process : The program calculate the years, months and weeks that passed in a given nomber of days.
//
// Output  : Prints the amount of years, months, weeks.
//
//-----------------------------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 4.9.2019
//-----------------------------------------------------------------------------------------------------
void main(void)
{
	unsigned short usNumOfDays;
	scanf("%hu", &usNumOfDays);

	// First Count the years, then count the months from the remaining days, then count the weeks
	printf("years: %hu  months: %hu  weeks: %hu",
			CALCULATE_YEARS, CALCULATE_MONTHS, CALCULATE_WEEKS);
	scanf("%hu", &usNumOfDays);
}