// 2.1.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ONE_HUNDRED_AND_ELEVEN 111
#define ONE_HUNDRED 100
#define TEN 10

//--------------------------------------------------------------------------------------------
//											 The Same Digits
//											-----------------
//
// General : The program checks if all the digits in a number are the same.
//
// Input   : A three digits number
//
// Process : The program takes one of the digits and checks if all the others are the same.
//
// Output  : Prints if all the digits are the same or not
//
//--------------------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 7.9.2019
//--------------------------------------------------------------------------------------------
void checkDigits(void)
{
	// Variable definition
	unsigned short num;
	unsigned short status;
	printf("Give a num \n");
	scanf("%hu", &num);

	// Check if one of the digits three times is the same number as the given one
	status = (num / ONE_HUNDRED * ONE_HUNDRED_AND_ELEVEN == num);
	printf("0 means wrong, 1 means right\nresult: %hu", status);
	scanf("%hu", &num);
}

// The same way but to show my logics
void checkDigitsBetter(void)
{
	// Variable definition
	unsigned short num;
	unsigned short temp;
	unsigned short newNum;
	unsigned short status;
	printf("Give a num \n");
	scanf("%hu", &num);

	temp = num % TEN;
	newNum = temp;

	newNum *= TEN;
	newNum += temp;

	newNum *= TEN;
	newNum += temp;

	// Repeat for longer numbers
	/*
	newNum *= TEN;
	newNum += temp;
	*/

	status = (newNum == num);

	// Check if one of the digits three times is the same number as the given one
	printf("0 means wrong, 1 means right\nresult: %hu", status);
	scanf("%hu", &num);
}