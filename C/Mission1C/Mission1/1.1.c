// 1.1.c

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SHEKELS_PER_FORM 6.3
#define MINUTES_PER_FORM 10
#define MINUTES_PER_HOUR 60

//----------------------------------------------------------------------------------------------
//										   Working Time
//										  --------------
//
// General : The program calculates how long the clerk worked and how much he should be paid.
//
// Input   : None
//
// Process : The program calculates how long the clerk worked and how much he should be paid.
//
// Output  : None
//
//----------------------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 4.9.2019
//----------------------------------------------------------------------------------------------
void main(void) 
{
	unsigned short num_of_forms = 652;

	// Calculate the time that passed in minutes.
	unsigned short usTime = num_of_forms * MINUTES_PER_FORM;
	printf("hours: %hu minutes: %hu salary: %f", usTime / MINUTES_PER_HOUR,
			usTime % MINUTES_PER_HOUR,
			num_of_forms * SHEKELS_PER_FORM);
}