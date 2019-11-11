#pragma once

#include "General.h"

//-------------------------------------------------------------------------------------------------
//                                        Most character in the string
//                                        ----------------------------
//
// General : Checks what is the most character in the string.
//
// Input   : No input. 
//
// Process : The process calling first the function MostCharacter and then the function 
//           ConvertIntToAscii.
//          
// Output  : Nothing.
//
//-------------------------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 12.11.2019
//-------------------------------------------------------------------------------------------------
void main2(void)
{
	string a;
	scanf("%s", &a);
	printf("%d", MostShowedChar(&a));
	scanf("%s", &a);

}