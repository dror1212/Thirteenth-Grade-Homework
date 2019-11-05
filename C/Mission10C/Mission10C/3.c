#pragma once

#include "General.h"

//---------------------------------------------------------------------------------------
//                                              Exc3
//                                              ----
//
// General  : The program checks how many substrings that start with the second input 
//            and ends with the third input inside the string.
//
// Input    : string, a char to start the substring and another char to end the substring.
//
// Process  : run on the string and start counting from the start char until the end char.
//
// Output   : the number of substrings inside the string.
//
//---------------------------------------------------------------------------------------
// Programer    : Dror Tal
// Student No   : 322534793
// Date         : 5.11.2019
//---------------------------------------------------------------------------------------
void main3(void)
{
	//definding variables.
	string s;
	char start;
	char end;
	unsigned short counter = ZERO;
	unsigned short place = ZERO;

	//input from the user.
	scanf("%s %c %c", &s, &start, &end);

	//run on the string.
	while (s[place])
	{
		//if the char in position place equal to start count how many
		//there are from the third input.
		counter += (s[place] == start) ? Counter(s, place, end) : ZERO;

		//increase place.
		place++;
	}
	//print for the user.
	printf("%hu\n", counter);
	scanf("%s", &s);
}