// 1.4.c

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define DAYS_TO_PAY (365 / 3)
#define CALCULATE_PRICE (fArea * fPricePerCubicMeter * fWaterConsumption * DAYS_TO_PAY)

//-----------------------------------------------------------------------------------------------------
//										   Irrigation Price
//										  ------------------
//
// General : The program calculate the irrigation Price.
//
// Input   : The area of the area, price per cubic meter, the water consumption.
//
// Process : The program calculate the price by multiplying the input info and the amount of times.
//
// Output  : Prints the price.
//
//-----------------------------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 4.9.2019
//-----------------------------------------------------------------------------------------------------
void main(void)
{
	float fArea;
	float fPricePerCubicMeter;
	float fWaterConsumption;
	printf("What is the area? what is the price per cubic meter?\
			what is the water consumption \n");
	scanf("%f %f %f", &fArea, &fPricePerCubicMeter, &fWaterConsumption);

	// Calculate the price and print it.
	printf("%f", CALCULATE_PRICE);
}