// 2.5.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define TWO 2

//--------------------------------------------------------------------------------------------
//										   Area Calculator
//										  -----------------
//
// General : The program calculates the area of a given triangle.
//
// Input   : The triangle's perpendiculars.
//
// Process : The program multiply the two perpendiculars and divide by two.
//
// Output  : Prints the area.
//
//--------------------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 7.9.2019
//--------------------------------------------------------------------------------------------
void area(void)
{
	// Variable definition
	float FirstPerpendicular;
	float secondPerpendicular;
	float area;

	printf("Give the length of the two \n");
	scanf("%f %f", &FirstPerpendicular, &secondPerpendicular);
	area = FirstPerpendicular * secondPerpendicular / TWO;
	printf("%f", area);
	scanf("%f", &FirstPerpendicular);
}