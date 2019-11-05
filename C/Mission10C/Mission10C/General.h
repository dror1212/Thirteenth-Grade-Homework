#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define ABS(x) (((x)>0)?(x):(-(x)))
#define SIZE 1000
#define BOOL unsigned short
#define TRUE 1
#define FALSE 0
#define ZERO 0
#define ONE 1
#define TWO 2
#define TEN 10
#define STRING_END '\0'

typedef char string[SIZE];

unsigned short Len(char a[SIZE]);

unsigned short FindChar(char a[SIZE], char b);

unsigned short How_many(char arr[], unsigned short pos, char c);

BOOL IsExist(char a[SIZE], char b);

BOOL CompareString(char a[SIZE], char b[SIZE]);

void ToString(char arr[SIZE]);

short find_str(char vec[], char vec_del[]);

BOOL Delete(char vec[], char vec_del[]);

short DeleteAll(char vec[], char vec_del[]);

BOOL ValidParameters(char str[]);

unsigned short MaxStreak(char arr[]);