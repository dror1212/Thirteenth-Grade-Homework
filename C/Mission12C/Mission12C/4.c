#pragma once
#include "General.h"

//-------------------------------------------------------------------------------------------------
//                                        Convert int to char
//                                        -------------------
//
// General : Converts an int to char.
//
// Input   : No input. 
//
// Process : The process calling the function Itoa.
//          
// Output  : Nothing.
//
//-------------------------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 12.11.2019
//-------------------------------------------------------------------------------------------------
void main4(void)
{
	char check = Itoa(98);
	printf("%c", check);
}