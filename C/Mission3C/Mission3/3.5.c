#pragma once
// 3.5.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ONE_HUNDRED_AND_SIXTY 160
#define ONE_HUNDRED_AND_SEVENTY_FIVE 175
#define SIX 6
#define THREE 3
#define FIFTEEN 15
#define ZERO 0
#define TEN_PRECENT 0.1
#define TEN 10

//--------------------------------------------------------------------------------------------
//											Salary Calculator
//										   -------------------
//
// General : The program calculates the salary of the worker.
//
// Input   : The info about the job status of the worker.
//
// Process : The program calculates the salary of the worker depends on the info it gets.
//
// Output  : Prionts the full salary of the worker.
//
//--------------------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 11.9.2019
//--------------------------------------------------------------------------------------------
void salaryCalculator(void)
{
	// Variable definition
	unsigned short numOfKids;
	unsigned short numOfHours;
	unsigned short seniority;
	float basicSalary;
	float TY;
	float TB;
	float T160;
	float T175;
	float fullSalary;
	printf("give the info: basic salary, seniority, number of kids, number of hours, T175, TY, TB, T160\n");
	scanf("%f %hu %hu %hu %f %f %f %f",
		&basicSalary, &seniority, &numOfKids, &numOfHours, &T175, &TY, &TB, &T160);

	// Calculate the salary
	fullSalary = basicSalary;
	// Add money for seniority
	fullSalary += (seniority > TEN) ? TEN_PRECENT * basicSalary : ZERO;
	//Add money for kids
	fullSalary += (numOfKids > THREE) ? ((numOfKids > SIX) ?
		THREE * TY + (numOfKids - SIX) * TB : (numOfKids - THREE) * TY) : ZERO;
	//Add money for extra time
	fullSalary += (numOfHours > ONE_HUNDRED_AND_SIXTY) ?
		((numOfHours > ONE_HUNDRED_AND_SEVENTY_FIVE) ?
			FIFTEEN * T160 + (numOfHours - ONE_HUNDRED_AND_SEVENTY_FIVE) * T175 :
				(ONE_HUNDRED_AND_SEVENTY_FIVE - numOfHours) * T160) : ZERO;

	printf("Salary: %f\n", fullSalary);
}