#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//--------------------------------------------------------------------------------------------
//											Kind of Tiles
//										   ---------------
//
// General : The program checks what tiles needed from the given.
//
// Input   : The length of the way, the size of the two kind of tiles.
//
// Process : The program divide by the bigger one and after that by the smaller one.
//
// Output  : Prints the amount that is needed.
//
//--------------------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 23.9.2019
//--------------------------------------------------------------------------------------------
void main7(void)
{
	// Variable definition
	unsigned int A;
	unsigned int B;
	unsigned int N;
	unsigned int numOfA;
	unsigned int numOfB;
	unsigned int temp;

	printf("Give A B N\n");
	scanf("%u %u %u", &A, &B, &N);

	// Check the amount of tiles that is needed.
	temp = N;
	numOfB = temp / B;
	temp -= numOfB * B;
	numOfA = temp / A;

	printf("A : %u , B : %u", numOfA, numOfB);
	scanf("%u %u %u", &A, &B, &N);
}