#pragma once

//-------------------------------------------------------------------------------------------------
//                                    Function MemoyanLeseroginHafuh
//                                    ------------------------------
//
// General    : Checks if the string is memoyan leserogin hafuh or not.
//
// Parameter  : A pointer for the even string and for the odd string.
//
// Return     : Returns TRUE if it is memoyan leserogin hafuh and FALSE otherwise.
//          
//-------------------------------------------------------------------------------------------------
BOOL MemoyanLeseroginHafuh(char* even, char* odd)
{
	int lengthEven = StringLength(even);
	int lengthOdd = StringLength(odd);
	BOOL found = TRUE;
	for (int counter = ZERO; counter < lengthEven - ONE; counter++)
	{
		if (*(even + counter) < * (even + counter + ONE))
		{
			found = FALSE;
		}

	}
	for (int counter = ZERO; counter < lengthOdd - ONE; counter++)
	{
		if (*(odd + counter) > *(odd + counter + ONE))
		{
			found = FALSE;
		}

	}
	return found;
}
//-------------------------------------------------------------------------------------------------
//                                    Function isStringMemoyan
//                                    ------------------------
//
// General    : Checks if the string is memoyan leserogin hafuh memoyan leserogin or not memoyan.
//
// Parameter  : A pointer for the string a pointer for the even string and for the odd string.
//
// Return     : Nothing.
//          
//-------------------------------------------------------------------------------------------------
void isStringMemoyan(char* a, char* even, char* odd)
{
	StringCut(a, even, odd);
	BOOL check = MemoyanLeserogin(even, odd);
	BOOL check1 = MemoyanLeseroginHafuh(even, odd);
	if (check == ONE)
	{
		printf("Memuyan Le Serugin");
	}
	if (check1 == ONE)
	{
		printf("Memuyan Le Serugin Hafuh");
	}
	if(check == ZERO&&check1==ZERO)
	{
		printf("Lo Memuyan");
	}

}
//-------------------------------------------------------------------------------------------------
//                                    Function Itoa
//                                    -------------
//
// General    : Coverts an int to a char.
//
// Parameter  : An int.
//
// Return     : Char that is the int in the ascii table.
//          
//-------------------------------------------------------------------------------------------------
char Itoa(int a)
{
	return (char)a;
}



