#pragma once
#pragma once
#define _CRT_SECURE_NO_WARNINGS

#ifndef _SPARCEMATRIX
#define _SPARCEMATRIX
#include<stdio.h>
#include<conio.h>

#define ZERO 0
#define ONE 1

typedef struct sparceMatNode
{
	void* data;
	struct sparceMatNode* next;
	struct sparceMatNode* bottom;
	int row;
	int col;
}sparceMatNode, * sparceMatNodePtr;
typedef enum BOOLEAN {FALSE,TRUE} BOOLEAN;

void initSparce(sparceMatNodePtr*);
void AddRowSparce(sparceMatNodePtr*, int*);
void AddColSparce(sparceMatNodePtr*, int*);
sparceMatNodePtr findAbove(sparceMatNodePtr *, int, int);
sparceMatNodePtr findBefore(sparceMatNodePtr *, int, int);
BOOLEAN AddItem(sparceMatNodePtr, int, int);
void* RemoveItem(sparceMatNodePtr, int, int);
void PrintSparce(sparceMatNodePtr, int, int);
int DeleteRow(sparceMatNodePtr* manager, int row, int* h);
int DeleteCol(sparceMatNodePtr* manager, int col, int* w);
void printInt(void* data);
sparceMatNodePtr goToManagerRow(sparceMatNodePtr* manager, int row);
sparceMatNodePtr goToManagerCol(sparceMatNodePtr* manager, int col);
#endif _SPARCEMATRIX
