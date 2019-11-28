#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 1000
#define ZERO 0
#define ONE 1
#define TWO 2
#define TWENTY_FIVE 25
#define BOOLEAN unsigned short
#define TRUE 1
#define FALSE 0
typedef char string[SIZE];


unsigned int MaxStreakInVec(char **ptrStr, int numOfRows);
unsigned int MaxStreak(char *ptrStr);
void copyMatrix(unsigned short * ptr, unsigned short *ptrHelp, int size);
BOOLEAN findSubInStr(char * strPtr, char * substringPtr);
int Len(char * strPtr);
BOOLEAN findStrInVecStr(char **ptrStr, int numOfRows);
BOOLEAN equal(char * firstStrPtr, char * secondStrPtr);