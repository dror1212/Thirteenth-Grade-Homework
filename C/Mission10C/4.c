#pragma once

#include "General.h"

//---------------------------------------------------------------------------------------
// 												Exc4
// 												----
//
// General 	: The program gets 10 strings and calculate in witch one there is the biggest
//			  streak of simillar chars in a row.
//
// Input 	: 10 strings.
//
// Process 	: Inside of every string calculate the biggest streak and compare it to 
//			  the biggest streak in other string until there is only one biggest streak.
//
// Output 	: the string with the biggest streak of simillar chars in a row and 
//			  the position inside the 10 strings.
//
//---------------------------------------------------------------------------------------
// Programer 	: Dror Tal
// Student No 	: 322534793
// Date 		: 5.11.2019
//---------------------------------------------------------------------------------------
void main4(void)
{
	//definding variables.
	unsigned short counter;
	unsigned short max;
	unsigned short offset;
	string str_arr;

	//input from the user.
	for (counter = ZERO;counter < TEN;counter++)
	{
		scanf("%s", str_arr[counter]);
	}

	//get the max streak from this string.
	max = MaxStreak(str_arr[ZERO]);
	//set the position of the answer to 0.
	offset = ZERO;
	//run on the other string.
	for (counter = ONE; counter < TEN; counter++)
	{
		//if the max streak
		if (max < MaxStreak(str_arr[counter]))
		{
			//set to max the max sstreak from this string.
			max = MaxStreak(str_arr[counter]);
			//set the position of the answer to counter.
			offset = counter;
		}
	}
	//print for the user.
	printf("%s    %hu\n", str_arr[offset], offset + ONE);
	scanf("%hu", &counter);
}