// 1.5.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SWITCH_THREE_NUMBERS(firstNumber,secondNumber,thirdNumber)\
firstNumber = firstNumber + secondNumber + thirdNumber;\
secondNumber = firstNumber - secondNumber - thirdNumber;\
thirdNumber = firstNumber - secondNumber - thirdNumber;\
firstNumber = firstNumber - secondNumber - thirdNumber;


//-----------------------------------------------------------------------------------------------------
//										   Shifting Circular
//										  -------------------
//
// General : The program get three numbers and change the last number to be the first one.
//
// Input   : Three numbers.
//
// Process : The program prints the numbers in a new order.
//
// Output  : Prints the numbers in the new order.
//
//-----------------------------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 4.9.2019
//-----------------------------------------------------------------------------------------------------
void main(void)
{
	int nFirstNum;
	int nSecondNum;
	int nThirdNum;
	printf("Give three numbers \n");
	scanf("%d %d %d", &nFirstNum, &nSecondNum, &nThirdNum);
	SWITCH_THREE_NUMBERS(nFirstNum, nSecondNum, nThirdNum);

	// Print the numbers in the new order
	printf("%d %d %d", nFirstNum, nSecondNum, nThirdNum);
}