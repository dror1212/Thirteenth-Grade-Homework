#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define ABS(x) (((x)>0)?(x):(-(x)))
#define ONE 1
#define TWO 2
#define TEN 10
#define ZERO 0
#define THREE 3
#define M 5
#define N 5
#define HIGH_NUMBER 9999

void InDiagonal(unsigned short [][THREE], unsigned short, short, unsigned short [], unsigned short);

void InRow(unsigned short [], unsigned short , unsigned short []);

void InCol(unsigned short [][THREE], unsigned short, unsigned short, unsigned short []);

void Clear_Array(unsigned short [], unsigned short);

unsigned short DigitInArray(unsigned short [], unsigned short, unsigned short);

unsigned short SumOfVecCounter(unsigned short [], unsigned short);

void DisplayGame(unsigned short [][THREE], unsigned short);

unsigned short win(unsigned short [], unsigned short);

unsigned short play(unsigned short, unsigned short [][THREE]);

void PrintMatrix(char [][N], unsigned short);

unsigned short sumOfCharMatrix(char [][N], unsigned short, unsigned short, unsigned short);

