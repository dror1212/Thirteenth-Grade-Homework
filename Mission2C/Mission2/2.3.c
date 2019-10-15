// 2.5.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MINUTES_PER_HOUR 60
#define SECONDS_PER_MINUTE 60
#define ZERO 0
#define TWO 2

//---------------------------------------------------------------------------------------------
//										   Difference in Time
//										  --------------------
//
// General : The program gets two different times and calculates the difference between them.
//
// Input   : HH:MM:SS each one of them is a number.
//
// Process : The program gets two different times and calculates the difference between them.
//
// Output  : Prints the difference in time like HH:MM:SS
//
//---------------------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 7.9.2019
//---------------------------------------------------------------------------------------------
void difInTime(void)
{
	// Variable definition
	unsigned short firstHours;
	unsigned short firstMinutes;
	unsigned short firstSeconds;
	unsigned short secondHours;
	unsigned short secondMinutes;
	unsigned short secondSeconds;
	unsigned short difHours;
	unsigned short difMinutes;
	unsigned short difSeconds;
	int timeInSeconds;

	printf("Give an hour\n");
	scanf("%hd:%hd:%hd", &firstHours, &firstMinutes, &firstSeconds);
	printf("Give an hour\n");
	scanf("%hd:%hd:%hd", &secondHours, &secondMinutes, &secondSeconds);

	// Calculate all the seconds
	timeInSeconds = firstHours * MINUTES_PER_HOUR * SECONDS_PER_MINUTE +
		firstMinutes * SECONDS_PER_MINUTE + firstSeconds;
	timeInSeconds -= (int)((int)secondHours * MINUTES_PER_HOUR * SECONDS_PER_MINUTE +
		(int)secondMinutes * SECONDS_PER_MINUTE + secondSeconds);	
	timeInSeconds -= (timeInSeconds < ZERO) * TWO * timeInSeconds;

	// Calculate the difference in time
	difHours = timeInSeconds / SECONDS_PER_MINUTE / MINUTES_PER_HOUR;
	timeInSeconds -= difHours * SECONDS_PER_MINUTE * MINUTES_PER_HOUR;
	difMinutes = timeInSeconds / SECONDS_PER_MINUTE;
	timeInSeconds -= difMinutes * SECONDS_PER_MINUTE;
	difSeconds = timeInSeconds;
	printf("%02hd:%02hd:%02d", difHours, difMinutes, difSeconds);
	scanf("%hd:%hd:%hd", &secondHours, &secondMinutes, &secondSeconds);
}