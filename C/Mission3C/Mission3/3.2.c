#pragma once
// 3.2.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX(x,y) ((x > y) ? x : y)
#define	MIN(x,y) ((x < y) ? x : y)
#define SUM_OF_ANGLES 180
#define RIGHT_ANGLE 90

//--------------------------------------------------------------------------------------------
//										Identify The Triangle
//									   ------------------------
//
// General : The program checks if the info about the triangle is valid and his kind.
//
// Input   : Three numbers (angles).
//
// Process : The program check if the info is valid, order the angles from big to smalland check.
//
// Output  : Prints the kind of the triangle, and if the info is valid.
//
//--------------------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 11.9.2019
//--------------------------------------------------------------------------------------------
void typeOfTriangle(void)
{
	// Variable definition
	float firstAngle;
	float secondAngle;
	float thirdAngle;
	float biggestAngle;
	float middleAngle;
	float smallestAngle;
	printf("Give three angles\n");
	scanf("%f %f %f", &firstAngle, &secondAngle, &thirdAngle);

	// Check if the angles can present a triangle.
	if (firstAngle + secondAngle + thirdAngle == SUM_OF_ANGLES)
	{
		// Check what is the biggest angle
		biggestAngle = firstAngle;
		biggestAngle = MAX(MAX(biggestAngle, secondAngle), thirdAngle);
		smallestAngle = MIN(MIN(firstAngle, secondAngle), thirdAngle);
		middleAngle = firstAngle + secondAngle + thirdAngle;
		middleAngle -= biggestAngle + smallestAngle;

		// Find the types of the triangle

		// Check if the angles are the same
		if (biggestAngle == middleAngle)
		{
			// Equilateral
			if (biggestAngle == smallestAngle)
			{
				printf("The triangle is equilateral\n");
			}
			// Isosceles
			else
			{
				printf("The triangle is an isosceles\n");
			}
		}
		else
		{
			// Isosceles
			if (middleAngle == smallestAngle)
			{
				printf("The triangle is an isosceles\n");
			}
			// Scalene
			else
			{
				printf("The triangle is scalene\n");
			}
		}
		// Obtuse
		if (biggestAngle > RIGHT_ANGLE)
		{
			printf("The triangle has obtuse angle\n");
		}
		else
		{
			// Sharp
			if (biggestAngle < RIGHT_ANGLE)
			{
				printf("The triangle has sharp angle\n");
			}
			// Right
			else
			{
				printf("The triangle has right angle\n");
			}
		}
	}
	else
	{
		printf("The angles does't suit");
	}
	scanf("%f %f %f", &firstAngle, &secondAngle, &thirdAngle);
}