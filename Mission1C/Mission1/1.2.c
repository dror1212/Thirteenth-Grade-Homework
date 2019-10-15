// 1.2.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//------------------------------------------------------------------------------------------------
//										   Left People
//										  --------------
//
// General : The program calculates how many taxis can get full and how many people need to wait.
//
// Input   : Number of people and number of seats per taxi.
//
// Process : The program calculates how many taxis can get full and how many people need to wait.
//
// Output  : None
//
//------------------------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 4.9.2019
//------------------------------------------------------------------------------------------------
void main(void)
{
	unsigned short usNumOfPeople;
	unsigned short usNumOfSeats;
	printf("How many people are waiting? and how many seats are in one taxi? \n");
	scanf("%hu %hu", &usNumOfPeople, &usNumOfSeats);
	// Calculate how many taxis can get full and how many people are left
	printf("%hu %hu", usNumOfPeople / usNumOfSeats, usNumOfPeople % usNumOfSeats);
}
