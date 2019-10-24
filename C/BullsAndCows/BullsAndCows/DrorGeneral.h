#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define ZERO 0
#define TWO 2
#define ONE 1
#define FOUR 4
#define TEN 10
#define MAX_NUMBER 9999
#define MIN_NUMBER 1000
#define IS_VALID(num)(((num <= 9999) * (num >= 1000)))
#define BOOLEAN unsigned short
#define TRUE 1
#define FALSE 0

void EmptyAVector(unsigned short [], int);

unsigned short CheckAccurateHits(unsigned short, unsigned short, unsigned short[]);

void CountAmmountOfNumbers(unsigned short, unsigned short []);

unsigned short CheckHits(unsigned short []);