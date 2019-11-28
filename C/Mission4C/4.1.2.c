#pragma once
// 3.4.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define BOOLEAN unsigned short
#define TRUE 1
#define FALSE 0
#define MIN_SCORE 40
#define MAX_SCORE 150
#define DIFFERENCE 60
#define ABSOLUTE(x) ((x > 0)? x : -x)

//--------------------------------------------------------------------------------------------
//											Game Is Valid
//										  -----------------
//
// General : The program checks if the score of the game is valid.
//
// Input   : The scores of the two teams.
//
// Process : The program checks if the score of the game is valid.
//
// Output  : Prints whether the game is valid or not.
//
//--------------------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 15.9.2019
//--------------------------------------------------------------------------------------------
void main2(void)
{
	// Variable definition
	unsigned short firstScore;
	unsigned short secondScore;
	BOOLEAN check = FALSE;

	printf("what is the score?\n");
	scanf("%hu %hu", &firstScore, &secondScore);
	printf("%hu %hu\n", firstScore, secondScore);

	// If one of them is false, check will stay False.
	// Check min score
	check = (MIN_SCORE <= firstScore) ? TRUE : FALSE;
	// Check max score
	check *= (firstScore <= MAX_SCORE) ? TRUE : FALSE;
	// Check min score
	check *= (MIN_SCORE <= secondScore) ? TRUE : FALSE;
	// Check max score
	check *= (secondScore <= MAX_SCORE) ? TRUE : FALSE;
	// Check equals
	check *= (firstScore == secondScore) ? FALSE : TRUE;
	// Check difference
	check *= (ABSOLUTE(firstScore - secondScore) >= DIFFERENCE) ? FALSE : TRUE;

	printf("result: %hu", check);
	scanf("%hu %hu", &firstScore, &secondScore);
}