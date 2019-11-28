#pragma once

#include "General.h"

//---------------------------------------------------------------------------------------
//                                              Len
//                                              ---
//
//  General         : The function calculate the length of the string.
//
//  Parameters      :
//                      arr - string(In)        
//
//  Return Value    : The length of the string.
//
//---------------------------------------------------------------------------------------
unsigned short Len(char a[SIZE])
{
	unsigned short counter = ZERO;
	while (a[counter] != STRING_END)
	{
		counter++;
	}
	return counter;
}

//---------------------------------------------------------------------------------------
//                                          Find char
//                                          ---------
//
//  General : The function checks if there is a char in a string(with what it got)
//
//  Parameters :
//          vec - Chars(In)
//          b   - Char         
//
//  Return Value : If there is that char returns the starting point else -1
//
//---------------------------------------------------------------------------------------
unsigned short FindChar(char a[SIZE], char b)
{
	unsigned short counter = ZERO;
	while ((a[counter] != b) * (a[counter] != STRING_END))
	{
		counter++;
	}
	counter = (a[counter] == b) ? counter : -ONE;
	return counter;
}

void CutString(char text[], unsigned int start, unsigned int size)
{
	unsigned int counter;
	for (counter = ZERO; (counter < size) * text[counter + start]; counter++)
	{
		text[counter] = text[counter + start];
	}
	text[counter] = STRING_END;
}

void CopyString(char text[], char copy[], unsigned int start)
{
	unsigned int counter,
		length = StringLenght(copy) + start;
	for (counter = start; counter < length; counter++)
	{
		text[counter] = copy[counter - start];
	}
	text[counter] = STRING_END;
}

void ReverseString(char textA[])
{
	unsigned int textA_lenght = StringLenght(textA) - ONE,
		counter,
		loop_lenght = (textA_lenght + ONE) / TWO;
	char temp_char;
	for (counter = ZERO; counter < loop_lenght; counter++)
	{
		temp_char = textA[counter];
		textA[counter] = textA[textA_lenght - counter];
		textA[textA_lenght - counter] = temp_char;
	}
}

void LinkingString(char textA[], char textB[])
{
	CopyString(textA, textB, StringLenght(textA));
}

//---------------------------------------------------------------------------------------
//                                              How Many
//                                              --------
//
//  General         : The function calculate how many times the char is in the string.
//
//  Parameters      :
//                      arr - string(In).
//                      pos - from where the function need to start the checking.
//                      c   - char. 
//
//  Return Value    : The amount of the char in the string.
//
//---------------------------------------------------------------------------------------
unsigned short How_many(char arr[], unsigned short pos, char c)
{
	//definding variables.
	unsigned short counter = ZERO;

	//run on the string.
	while (arr[pos])
	{
		//if the value in position pos equal to the char, increase counter.
		(arr[pos] == c) ? counter++ : ZERO;

		//increase pos.
		pos++;
	}
	return counter;
}

BOOL IsExist(char a[SIZE], char b)
{
	unsigned short counter = ZERO;
	BOOL found = FALSE;
	while ((a[counter] != STRING_END)*(a[counter] != b))
	{
		counter++;
	}
	found = (a[counter] == b) ? TRUE : found;
	return found;
}

BOOL CompareString(char a[SIZE], char b[SIZE])
{
	unsigned short counter = ZERO;
	BOOL found = TRUE;
	while ((found) * (a[counter] != STRING_END))
	{
		found = (a[counter] != b[counter++]) ? FALSE : found;
	}
	return found;
}

void ToString(char arr[SIZE])
{
	unsigned short counter = ZERO;
	while (arr[counter] != STRING_END)
	{
		printf("%c", arr[counter++]);
	}
	printf("\n");
}

//---------------------------------------------------------------------------------------
//                                          Find str
//                                          --------
//
//  General : The function checks if there is a string in a string(with what it got)
//
//  Parameters :
//          vec - Chars(In)
//          vec_del - Chars(In)         
//
//  Return Value : If there is that string returns the starting point else -1
//
//---------------------------------------------------------------------------------------
short find_str(char vec[], char vec_del[])
{
	unsigned short counter = ZERO;
	unsigned short counter_sec = ZERO;
	while (vec[counter] != STRING_END && vec_del[counter_sec] != STRING_END)
	{
		counter_sec = (vec[counter] == vec_del[counter_sec]) ? ++counter_sec : 0;
		counter++;
	}
	return (vec_del[counter_sec] == STRING_END) ? counter -Len(vec_del): -1;
}
//---------------------------------------------------------------------------------------
//                                          Delete
//                                          ------
//
//  General         : The function deletes a string from a string
//
//  Parameters      :
//          vec     - Array of chars(In)
//          vec_del - Array of chars(In)            
//
//  Return Value    : If the function deleted a string or not
//
//---------------------------------------------------------------------------------------
BOOL Delete(char vec[], char vec_del[])
{
	unsigned short length = Len(vec_del);
	short jump = find_str(vec, vec_del);
	unsigned short counter = ZERO;
	while (jump != -ONE && vec[counter] != STRING_END)
	{
		vec[jump + counter] = vec[jump + length + counter++];
	}
	return (jump > ZERO);
}

//---------------------------------------------------------------------------------------
//                                          Delete all
//                                          ----------
//
//  General         : The function deletes a string from a string till the there is no more of 
//                    that same string
//
//  Parameters      :
//          vec     - Array of chars(In)
//          vec_del - Array of chars(In)            
//
//  Return Value    : How Many times the function deleted the same string
//
//---------------------------------------------------------------------------------------
unsigned short DeleteAll(char vec[], char vec_del[])
{
	unsigned short counter = ZERO;
	unsigned short counter2 = ZERO;
	while (vec[counter] != STRING_END)
	{
		counter2 += (Delete(vec, vec_del)) ? ONE : ZERO;
		counter++;
	}
	return (counter2);
}

BOOL ValidParameters(char str[])
{
	short counter = ZERO;
	unsigned short offset = ZERO;
	BOOL check = TRUE;

	while (str[offset] != STRING_END)
	{
		counter += (str[offset] == '(') ? ONE : ZERO;
		counter -= (str[offset] == ')') ? ONE : ZERO;
		check = (counter < ZERO) ? FALSE : check;
		offset++;
	}

	check = (counter == ZERO) ? check : FALSE;

	return (check);
}

//---------------------------------------------------------------------------------------
//												Max Streak
//									        	----------
//
//  General			: The function gets string and calculte the highest streak 
//					  of the same letters.
//
//	Parameters 		:
//						arr - string(In)		
//
//	Return Value 	: the highest streak of same letters in the string.
//
//---------------------------------------------------------------------------------------
unsigned short MaxStreak(char arr[])
{
	//definding variables.
	unsigned short counter = ONE;
	unsigned short max = ONE;
	unsigned short streak = ONE;

	//check the first two places.
	max = (arr[ZERO] == arr[counter]) ? max++ : max;

	//run on the string.
	while (arr[counter])
	{
		//if the value in position counter equal to the next one, increase the variable streak.
		(arr[counter] == arr[counter + ONE]) ? streak++ : ZERO;
		//find the max between max and streak and insert him to max.
		max = MAX(max, streak);
		//increase counter.
		counter++;
	}
	return max;
}