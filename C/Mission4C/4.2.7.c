#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ONE 1
//--------------------------------------------------------------------------------------------
//											Which Is First
//										   ----------------
//
// General : The program checks if the first or the second letters comes first.
//
// Input   : Two Letters.
//
// Process : The program checks if the first or the second letters comes first.
//
// Output  : Prints the letters after the process.
//
//--------------------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 17.9.2019
//--------------------------------------------------------------------------------------------
void main(void)
{
	// Variable definition
	char firstLetter;
	char secondLetter;
	char firstLetterChanged;
	char secondLetterChanged;
	char sign;
	short check;

	printf("Give two letters\n");
	scanf("%c %c", &firstLetter, &secondLetter);

	// Check which letter comes first
	check = firstLetter - secondLetter;

	// If the first is before the second
	if (check < 0)
	{
		firstLetterChanged = firstLetter + ONE;
		secondLetterChanged = secondLetter - ONE;
		sign = '+';		
	}
	// If the first is after the second
	else
	{
		firstLetterChanged = firstLetter - ONE;
		secondLetterChanged = secondLetter + ONE;
		sign = '-';
	}

	printf("%c%c%c", firstLetterChanged, sign, secondLetterChanged);
	scanf("%d", &firstLetter);
}