#pragma once

#include "General.h"

//---------------------------------------------------------------------------------------
// 											tic tac toe
// 											-----------
//
// General 	: the program plays the game tic tac toe.
//
// Input 	: the position of the symbol and the symbol.
//
// Process 	: running checks over the matrix if there is one row\column\diagonal 
//			  that has 3 symbols the same, the player that has that turn won.
//
// Output 	: witch player won.
//
//---------------------------------------------------------------------------------------
// Programer 	: Dror Tal
// Student No 	: 322534793
// Date 		: 1.11.2019
//---------------------------------------------------------------------------------------
void main1(void)
{
	// Definding variables.
	unsigned short mat[THREE][THREE] = { ZERO };
	unsigned short result = ZERO;
	unsigned short x;
	unsigned short y;
	char c;

	// Show the boared
	DisplayGame(mat, THREE);

	//run in the loop until result isn't 0.
	while (!result)
	{
		printf("Play\n");
		scanf("%hu %hu %c", &x, &y, &c);

		// Save the input
		mat[y][x] = (c == 'X') ? ONE : mat[y][x];
		mat[y][x] = (c == 'O') ? TWO : mat[y][x];

		// Check if someone won
		result = (mat[y][x] > ZERO) ? (play(mat[y][x] - ONE, mat)) : ZERO;

		// Show the boared
		DisplayGame(mat, THREE);
	}
	printf("Player %c won!", c);
	scanf("%hu", &result);
}