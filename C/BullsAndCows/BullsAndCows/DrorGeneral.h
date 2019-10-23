#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define ZERO 0
#define TWO 2
#define ONE 1
#define FOUR 4
#define TEN 10

typedef enum BOOLEAN {FALSE, TRUE};

unsigned int NumOfDigits(unsigned int);

unsigned short SumOfDigits(unsigned short [], unsigned short, unsigned int);

void EmptyAVector(int [], int);

void CheckHits(unsigned short, unsigned short, unsigned short []);

unsigned short CheckHit(unsigned short, unsigned short, unsigned short[]);

void CheckKliaa(unsigned short, unsigned short, unsigned short []);

void CountAmmountOfNumbers(unsigned short, unsigned short []);

unsigned short CheckKliaas(unsigned short []);