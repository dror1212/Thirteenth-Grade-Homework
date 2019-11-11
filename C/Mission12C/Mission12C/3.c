#include "General.h"

//-------------------------------------------------------------------------------------------------
//                                        Memoyan leserogin?
//                                        ------------------
//
// General : Checks if it is memoyan leserogin or memoyan leserogin hafuh and prints.
//
// Input   : No input. 
//
// Process : The process calling the function isStringMemoyan.
//          
// Output  : Nothing.
//
//-------------------------------------------------------------------------------------------------
// Programmer : DrorTal
// Student No : 322534793
// Date       : 12.11.2019
//-------------------------------------------------------------------------------------------------
void main3(void)
{
	string a;
	printf("enter a string");
	scanf("%s", a);
	string even, odd;
	char* pointerA = &a;
	char* pointerEven = &even;
	char* pointerOdd = &odd;
	isStringMemoyan(a, even, odd);
}