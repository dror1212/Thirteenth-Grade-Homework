// 1.6.c

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define PRICE_FOR_ADULT 50
#define PRICE_FOR_CHILD 35

//-----------------------------------------------------------------------------------------------------
//										    Price For The Pool
//										   --------------------
//
// General : The program calculates the amount of money the pool made.
//
// Input   : Number of adults and number of childs.
//
// Process : The program uses the permanent prices to calculate the full price.
//
// Output  : Prints the total price.
//
//-----------------------------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 4.9.2019
//-----------------------------------------------------------------------------------------------------
void main(void)
{
	unsigned short usNumOfAdults;
	unsigned short usNumOfChilds;
	printf("How many adults and children came today? \n");
	scanf("%hu %hu", &usNumOfAdults, &usNumOfChilds);
	// Calculate the full price and print it.
	printf("%hu", usNumOfAdults * PRICE_FOR_ADULT + usNumOfChilds * PRICE_FOR_CHILD);
}

//----------------------------------------------------------------------------------
//										    Price For The Pool
//										   --------------------
//
// General : The program calculates the amount of money the pool made.
//
// Input   : Number of adults and number of childs, the prices for adults and childs.
//
// Process : The program uses the permanent prices to calculate the full price.
//
// Output  : Prints the total price.
//
//----------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 4.9.2019
//----------------------------------------------------------------------------------
void changedVersion(void)
{
	unsigned short usNumOfAdults;
	unsigned short usNumOfChilds;
	unsigned short usPriceForAdult;
	unsigned short usPriceForChild;
	printf("How many adults and children came today? \n");
	scanf("%hu %hu", &usNumOfAdults, &usNumOfChilds);
	printf("What is the price for each of them? \n");
	scanf("%hu %hu", &usPriceForAdult, &usPriceForChild);

	// Calculate the full price and print it.
	printf("%hu", usNumOfAdults * usPriceForAdult + usNumOfChilds * usPriceForChild);
}
