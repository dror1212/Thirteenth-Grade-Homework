#pragma once

#include "General.h"

//---------------------------------------------------------------------------------------
// 												Exc1
// 												----
//
// General 	: The program deletes the chars of the first array from the second array.
//
// Input 	: 2 strings.
//
// Process 	: The program checks if the string that needs too be deleted exist ,if there
//            is ,delete, else stop and print how many times it was deleted and the new 
//            string
//
// Output 	: the new string after the delete and how many chars were deleted.
//
//---------------------------------------------------------------------------------------
// Programer 	: Dror Tal
// Student No 	: 322534793
// Date 		: 5.11.2019
//---------------------------------------------------------------------------------------
void main1(void)
{
	unsigned short c;
	string str1 = { 'a','b','c','\0' };
	string str2 = { 'b','a','b','c','d','e','a','b','c','d','e','a','b','\0' };
	printf("%hu", DeleteAll(str2, str1));
	ToString(str2);
	scanf("%hu", &c);
}