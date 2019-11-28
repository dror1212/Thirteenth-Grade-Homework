// 2.5.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define TWO 2
#define APPLES_KG 7
#define SHEKELS_FOR_KG_APPLES 3.7
#define BANANAS_KG (APPLES_KG + TWO)
#define SHEKELS_FOR_KG_BANANAS (SHEKELS_FOR_KG_APPLES * TWO)

//--------------------------------------------------------------------------------------------
//										   Price Calculator
//										  ------------------
//
// General : The program calculates how much should the buyer pay.
//
// Input   : NONE
//
// Process : The program calculates how much should the buyer pay.
//
// Output  : Prints the price
//
//--------------------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 7.9.2019
//--------------------------------------------------------------------------------------------
void priceCalculator(void)
{
	// Variable definition
	float price = APPLES_KG * (float)SHEKELS_FOR_KG_APPLES +
					BANANAS_KG * (float)SHEKELS_FOR_KG_BANANAS;	

	printf("%f", price);
}