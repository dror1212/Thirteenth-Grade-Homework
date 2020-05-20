// Main.c

#include "General.h"

//-----------------------------------------------------------------------------------------
// 											MineSweeper
// 										   -------------
//
// General 	: The program manages the minesweeper game.
//
// Input 	: The info about the bombs and the guesses of the player.
//
// Process 	: The program create the bored depends on the info from the user and then lets
//			  him play untill the game is over.
//
// Output 	: The boared of the game every round and whether the player won or lost.
//
//-----------------------------------------------------------------------------------------
// Programer 	: Dror Tal
// Student No 	: 322534793
// Date 		: 24.12.2019
//-----------------------------------------------------------------------------------------
void main(void)
{
	play();
	_getch();
}