#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define DAYS_PER_YEAR 360
#define DAYS_PER_MONTH 30
#define ZERO 0
#define TWO 2
#define DOUBLE_TWO 2.0
#define HUNDRED 100
#define TEN_TOUSEND 10000
#define TEN 10
#define ONE 1
#define LENGTH_OF_VECTOR 40
#define MAX_DEVIATION  0.0001
#define FOUR 4
#define SIX 6
#define TWENTY 20
#define NINE 9

#define ABSOLUTE(a)(((a) < 0) ? -(a) : (a))
#define IS_ODD(a)((a) % TWO)
#define IS_EVEN(a)(!IS_ODD(a))
#define NEWTON(x,a)(((x) / DOUBLE_TWO) + (a) /(DOUBLE_TWO * (x)))
#define MAX(a,b) (((a) + (b)) / DOUBLE_TWO + ABSOLUTE(((a) - (b)) / DOUBLE_TWO))
#define MIN(a,b) (((a) + (b)) / DOUBLE_TWO - ABSOLUTE(((a) - (b)) / DOUBLE_TWO))

typedef enum BOOLEAN {FALSE, TRUE};

unsigned int DifInTime(unsigned int, unsigned int);

unsigned int TimeToDays(unsigned int, unsigned int, unsigned int);

unsigned int DaysToDate(unsigned int, unsigned int, unsigned int);

unsigned int TotalTimeFromDate(unsigned int);

unsigned int ToDecimal(unsigned int, unsigned int);

unsigned int OddAndEvenSum(unsigned int);

unsigned int NumberFromOddDigits(unsigned int);

unsigned int NumberFromEvenDigits(unsigned int);

unsigned int HipuhNumber(unsigned int);

unsigned int SumOfEvenDigits(unsigned int);

unsigned int SumOfOddDigits(unsigned int);

unsigned int NumOfDigits(unsigned int);

enum BOOLEAN IsIn(int, unsigned short);

unsigned long long Shirshur1(unsigned long long, unsigned long long);

unsigned long long Shirshur2(unsigned long long, unsigned long long);

double Power(double, double);

unsigned short Sum(unsigned short []);

unsigned short CountNotZeros(unsigned short [], unsigned short);

enum BOOLEAN CommonDigits(int, int);

enum BOOLEAN IsPrime(int);

double NewtonSqrt(double);

enum BOOLEAN IsPerfect(unsigned int);

int MaxInVector(int [], unsigned int);

int MinInVector(int [], unsigned int);

void VectorDifference(int [], int, int []);

unsigned short SumOfDigits(unsigned short [], unsigned short, unsigned int);

unsigned short CountSpecificDigits(unsigned short [], unsigned short, unsigned int);

double Kefel(double, double );

void EmptyAVector(int [], int);

void CheckHits(unsigned short, unsigned short, unsigned short []);

void CheckKliaa(unsigned short, unsigned short, unsigned short []);

void CountAmmountOfNumbers(unsigned short, unsigned short []);