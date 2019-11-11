#include "General.h"

//-------------------------------------------------------------------------------------------------
//                                Delete Substrings from string
//                                -----------------------------
//
// General : Checks how much substrings in the string and deletes the substrings.
//
// Input   : No input. 
//
// Process : The process calling the function DeleteSubstring.
//          
// Output  : Nothing.
//
//-------------------------------------------------------------------------------------------------
// Programmer : Dror Tal
// Student No : 322534793
// Date       : 12.11.2019
//-------------------------------------------------------------------------------------------------
void main5(void)
{
	string a, b;

	printf("enter a string");
	scanf("%s", a);
	printf("enter a substring");
	scanf("%s", b);

	char* aPtr = &a[ZERO];
	char* bPtr = &b[ZERO];
	int temp = 0;
	int check = DeleteSubstring(aPtr, bPtr,&temp);

	printf("%d", check);
}