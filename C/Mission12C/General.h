#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 1000
#define BOOLEAN unsigned short
#define TRUE 1
#define FALSE 0
#define ONE 1
#define TWO 2
#define TEN 10
#define ZERO 0

typedef char string[SIZE];

int Len(char * strPtr);
BOOLEAN equal(char * firstStrPtr, char * secondStrPtr);
unsigned short findStr(char * strPtr, char * substringPtr);
int MostShowedChar(char * strPtr);
void ConvertIntToAscii(int a);
int CounterSubstring(char* string, char* substring);
BOOLEAN SubstringInString(char* string, char* substring, int* start);
char Itoa(int a);