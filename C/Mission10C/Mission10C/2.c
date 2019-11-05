#pragma once

#include "General.h"

//---------------------------------------------------------------------------------------
// 												Exc2
// 												----
//
// General 	: The program checks if the input of the player is valid or not.
//
// Input 	: string with aritmetic sentence.
//
// Process 	: The program adds one to the counter when there is a '(' and 
//			  decrease one when there is a ')'.
//
// Output 	: 0 - the sentence is invalid.
//			  1 - the sentence is valid.
//
//---------------------------------------------------------------------------------------
// Programer 	: Dror Tal
// Student No 	: 322534793
// Date 		: 5.11.2019
//---------------------------------------------------------------------------------------
void main2(void)
{
	string str;
	BOOL check = TRUE;
	scanf("%s", str);

	check = ValidParameters(str);

	printf("%hu", check);
	scanf("%hu", &check);
}