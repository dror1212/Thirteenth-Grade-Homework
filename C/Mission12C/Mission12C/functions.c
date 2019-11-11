#include "General.h"

unsigned short findStr(char * strPtr, char * substringPtr)
{
	string help;
	unsigned short counter;
	unsigned short answer = ZERO;
	int len = Len(substringPtr);
	while ((*strPtr) != '\0')
	{
		for (counter = ZERO;counter < len;counter++)
		{
			help[counter] = (*(strPtr++));
		}
		help[counter] = '\0';
		strPtr -= (len - ONE);
		answer += (equal(&help, substringPtr));
	}

	return answer;
}

BOOLEAN equal(char * firstStrPtr, char * secondStrPtr)
{
	BOOLEAN check = (Len(firstStrPtr) == Len(secondStrPtr));
	while (((*firstStrPtr) != '\0') * (check))
	{
		check = ((*(firstStrPtr++)) == (*(secondStrPtr++))) ? check : FALSE;
	}
	return check;
}

int Len(char * strPtr)
{
	char * helpPtr = &(*strPtr);
	while ((*(strPtr++)) != '\0');
	return (int)(strPtr - helpPtr) - ONE;
}

int MostShowedChar(char * strPtr)
{
	int counters[SIZE] = { ZERO };
	int counter = ZERO;
	int max = ZERO;
	while ((*strPtr) != '\0')
	{
		counters[(*strPtr++)]++;
	}

	for (;SIZE - counter;counter++)
	{
		max = (counters[counter] > max) ? counters[counter] : max;
	}

	return max;
}

//-------------------------------------------------------------------------------------------------
//                                    Function ConvertIntToAscii
//                                    --------------------------
//
// General    : Converts the int to ascii and prints.
//
// Parameter  : Int. 
//
// Return     : Nothing.
//          
//-------------------------------------------------------------------------------------------------
void ConvertIntToAscii(int a)
{
	char b = a + 97;
	printf("%c", b);
}

//-------------------------------------------------------------------------------------------------
//                                    Function SubstringInString
//                                    --------------------------
//
// General    : Checks if theres a substring in the string.
//
// Parameter  : A pointer for string and a pointer for substring and a pointer that saves the last
//              index. 
//
// Return     : TRUE if there is and FALSE if there isnt.
//          
//-------------------------------------------------------------------------------------------------
BOOLEAN SubstringInString(char* string, char* substring, int* start)
{
	BOOLEAN found = FALSE;
	unsigned short lengthSubstring = StringLength(substring);
	unsigned short counter = ZERO;
	int startIndex = string;
	while ((*(string + (*start)) != '\0')*(found != TRUE))
	{
		if (*(string + (*start)) == *substring)
		{
			counter++;
			substring++;
			string++;
		}
		else
		{
			substring = substring - counter;
			if (*(string + (*start)) == *substring)
			{
				counter = ONE;
				substring++;
				string++;
			}
			else
			{
				counter = ZERO;
				string++;
			}
		}
		if (counter == lengthSubstring)
		{
			found = TRUE;
			*start = string + *start - startIndex;
		}

	}
	return found;
}
//-------------------------------------------------------------------------------------------------
//                                    Function CounterSubstring
//                                    -------------------------
//
// General    : Checks how many substrings are in the string.
//
// Parameter  : A pointer for string and a pointer for substring 
//
// Return     : Returns the number of substrings in the string.
//          
//-------------------------------------------------------------------------------------------------
int CounterSubstring(char* string, char* substring)
{
	int counter = ZERO;
	int counterStrings = ZERO;
	while (SubstringInString(string, substring, &counter))
	{
		counterStrings++;
	}
	return counterStrings;
}

//-------------------------------------------------------------------------------------------------
//                                    Function DeleteSubstring
//                                    --------------------
//
// General    : Checks how many substrings are in the string and deletes them.
//
// Parameter  : A pointer for string and a pointer for substring.
//
// Return     : Returns the number of substrings in the string.
//          
//-------------------------------------------------------------------------------------------------
int DeleteSubstring(char* string, char* substring)
{
	int counter = ZERO;
	int counterStrings = ZERO;
	unsigned short length = StringLength(substring);
	while (SubstringInString(string, substring, &counter))
	{
		counterStrings++;
		counter = counter - length;
		DeleteParts(string, substring, &counter);
	}
	return counterStrings;
}

//-------------------------------------------------------------------------------------------------
//                                    Function MemoyanLeserogin
//                                    -------------------------
//
// General    : Checks if the string is memoyan leserogin or not.
//
// Parameter  : A pointer for the even string and for the odd string.
//
// Return     : Returns TRUE if it is memoyan leserogin and FALSE otherwise.
//          
//-------------------------------------------------------------------------------------------------
BOOLEAN MemoyanLeserogin(char* even, char* odd)
{
	int lengthEven = StringLength(even);
	int lengthOdd = StringLength(odd);
	BOOLEAN found = TRUE;
	for (int counter = ZERO; counter < lengthEven - ONE; counter++)
	{
		if (*(even + counter) > * (even + counter + ONE))
		{
			found = FALSE;
		}

	}
	for (int counter = ZERO; counter < lengthOdd - ONE; counter++)
	{
		if (*(odd + counter) < *(odd + counter + ONE))
		{
			found = FALSE;
		}

	}
	return found;
}

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
BOOLEAN MemoyanLeseroginHafuh(char* even, char* odd)
{
	int lengthEven = StringLength(even);
	int lengthOdd = StringLength(odd);
	BOOLEAN found = TRUE;
	for (int counter = ZERO; counter < lengthEven - ONE; counter++)
	{
		if (*(even + counter) < *(even + counter + ONE))
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
	BOOLEAN check = MemoyanLeserogin(even, odd);
	BOOLEAN check1 = MemoyanLeseroginHafuh(even, odd);
	if (check == ONE)
	{
		printf("Memuyan Le Serugin");
	}
	if (check1 == ONE)
	{
		printf("Memuyan Le Serugin Hafuh");
	}
	if (check == ZERO && check1 == ZERO)
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