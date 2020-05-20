#pragma once
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include "dinQueue.h"

#define ROWSIZE 8
#define COLSIZE 8
#define ZERO 0
#define ONE 1
#define TWO 2
#define TEN 10
#define GAMESIZE 25
#define MAXTURN 999999999
void initSparce(sparceMatNodePtr*);

typedef enum { FALSE, TRUE }BOOLEAN;

typedef enum Status { UP, LEFT, DOWN, RIGHT, DEATHNEUTRON, ATOM, DEATHATOM }Status;
typedef struct item
{
	Status status;
	int lastUpdateTurn;
}item, * itemPtr;

typedef struct sparceMatNode
{
	item data;
	struct sparceMatNode* next;
	struct sparceMatNode* bottom;
	int row;
	int col;
}sparceMatNode, * sparceMatNodePtr;

typedef struct
{
	sparceMatNodePtr* arr;
	int rear;
}dyn_queue, * dyn_queuePtr;

void AddRowSparce(sparceMatNodePtr*, int*);
void AddColSparce(sparceMatNodePtr*, int*);
sparceMatNodePtr findAbove(sparceMatNodePtr, int, int);
sparceMatNodePtr findBefore(sparceMatNodePtr, int, int);
BOOLEAN AddItem(sparceMatNodePtr, int, int, item);
item RemoveItem(sparceMatNodePtr, int, int);
void PrintSparce(sparceMatNodePtr, int, int);
int DeleteRow(sparceMatNodePtr* manager, int row, int* h);
int DeleteCol(sparceMatNodePtr* manager, int col, int* w);
void printInt(void* data);
sparceMatNodePtr goToManagerRow(sparceMatNodePtr * manager, int row);
sparceMatNodePtr goToManagerCol(sparceMatNodePtr * manager, int col);
#endif // !_SPARCEMATRIX