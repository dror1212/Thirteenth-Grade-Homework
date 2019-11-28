#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#define ZERO 0
#define ONE 1
#define TWO 2
#define SPACE " "
#define SIZE 1000
#define TEN 10
#define BOOLEAN unsigned short;
#define TRUE 1;
#define FALSE 0;

typedef char string[SIZE];

int * EvenSubArray(int [], int, int *);
void SearchLongestWord(char [], char **);
int Length(char *strPtr, char whereToStop);
int Len(int number);
int * createAMatrixFromAmountOfDigits(int howManyNums, int howManyDigits);
int createANumberFromNumber(int number, int newLength);
void seperateEvenAndOddPointers(int vec[], int length, int * evenSize, int **even, int *oddSize, int **odd);
int * OddSubArray(int vec[], int len, int *ptrEven);
void alphabeticOrder(char * names[], int length);