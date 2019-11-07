#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define BOOLEAN unsigned short
#define TRUE 1
#define FALSE 0
#define ONE 1
#define TWO 2
#define TEN 10
#define ZERO 0
#define TEN_THOUSND 10000
#define DAYS_IN_YEAR 360
#define HUNDRED 100
#define DAYS_IN_MONTH 30
#define ABS(n) (((n) < 0) ? (-(n)) : (n))

void Concatenation(int * firstPtr, int * secondPtr, int * newNumberPtr);
void Power(int * powerPtr, double * numberPtr, double * answer);
void SumOfDigits(int *numberPtr, int * sum);
void Length(int *numberPtr, int * length);
void IsExist(int *numberPtr, int *digitPtr, BOOLEAN * exist);
void SumOfOddUnEvenDigits(int *ptr, int *sum);
void SumOfEvenDigits(int *ptr, int *sum);
void Sum(int *firstPtr, int *secondPtr, int *sum);
void Switch(int *firstPtr, int *secondPtr);
void IsOdd(int * ptr, BOOLEAN * answer);
void IsEven(int * ptr, BOOLEAN * answer);
void SameDigit(int * firstPtr, int * secondPtr, BOOLEAN * answer);
void numberFromEvenDigits(int *numberPtr, int *newNumber);
void numberFromOddDigits(int *numberPtr, int *newNumber);
void IsPrime(int *numberPtr, BOOLEAN * check);
void Opposite(int *numberPtr, int *newNumberPtr);
void Divide(double *ptr_first_number, double *ptr_second_number, int *ptr_result);
void Module(int *ptr_first_number, int *ptr_second_number, int *ptr_result);