#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define BOOLEAN unsigned short
#define ONE 1
#define BITS_IN_BYTE 8
#define ZERO 0
#define TWO 2
#define THREE 3
#define FOUR 4
#define TRUE 1
#define FALSE 0

typedef unsigned char byte;

BOOLEAN isEven(int num);
int calculateBitsInInt(BOOLEAN isSigned);
double power(double number, int numberOfTimes);
unsigned int rotationLeft(int num, int times);
unsigned short CountBits(byte b);
void PrintGetRow();
void PrintGetRemoveCount();
unsigned short InputRow();
void RemoveBits(byte* row, unsigned short count, int*counter);
unsigned short SumBits(byte* vec, unsigned short lenght);
void PrintBits(byte b);
void PrintRows(byte* rows, unsigned short lenght);
byte* MaxBitsRow(byte* rows, unsigned short lenght);
void Bot(byte* rows, unsigned short lenght, int * counter);
void Bot5(byte* rows, unsigned short lenght, int* counter);