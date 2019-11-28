#pragma once

#include "General.h"

//-------------------------------------------------------------------------------------------------
//                                        Numbers of substring in string
//                                        ------------------------------
//
// General : Checks how much substrings in the string.
//
// Input   : No input. 
//
// Process : The process calling first the function CounterSubstrings.
//          
// Output  : prints the result of CounterSubstrings.
//
//-------------------------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 12.11.2019
//-------------------------------------------------------------------------------------------------
void main1(void)
{
	string a;
	string b;
	scanf("%s", &a);
	scanf("%s", &b);
	printf("%d", findStr(&a,&b));
	scanf("%s", &a);

}