// 2.2.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define ONE_HUNDRED 100
#define TEN 10

//--------------------------------------------------------------------------------------------
//											 Opposite Number
//											----------------
//
// General : The program gets a number and prints his opposite one.
//
// Input   : A three digits number
//
// Process : The program gets a number and prints its oposite one.
//
// Output  : Prints the number in the opposite way.
//
//--------------------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 7.9.2019
//--------------------------------------------------------------------------------------------
void firstOppositeNumbers(void)
{
	// Variable definition
	unsigned short num;
	unsigned short temp;
	unsigned short newNum;

	printf("Give a number \n");
	scanf("%hu", &num);

	// Calculate the new number
	temp = num / TEN;
	newNum = num - temp * TEN;

	newNum *= TEN;
	newNum += temp;
	temp = temp / TEN;
	newNum -= temp * TEN;

	newNum *= TEN;
	newNum += temp;
	temp = temp / TEN;
	newNum -= temp * TEN;

	// To make it work with four numbers (repeat for more)
	/*
	newNum *= TEN;
	newNum += temp;
	temp = temp / TEN;
	newNum -= temp * TEN;
	*/

	printf("%hu", newNum);
}

void secondOppositeNumbers(void)
{
	// Variable definition
	unsigned short num;
	unsigned short newNum;

	printf("Give a number \n");
	scanf("%hu", &num);

	// Calculate the new number
	newNum = num % TEN * ONE_HUNDRED;
	newNum += num / TEN % TEN * TEN;
	newNum += num / ONE_HUNDRED;
	printf("%hu", newNum);
}