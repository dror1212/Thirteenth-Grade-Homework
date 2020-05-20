#define _CRT_SECURE_NO_WARNINGS
#pragma once
#ifndef _DYN_QUEUE
#define _DYN_QUEUE
#include<stdio.h>

#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#ifndef _BOOLEAN
#define _BOOLEAN
typedef enum { FALSE, TRUE }BOOLEAN;
#endif


void initDynQueue(dyn_queuePtr);
BOOLEAN isEmptyDynQueue(dyn_queuePtr);

typedef enum Status {UP, LEFT, DOWN, RIGHT, DEATHNEUTRON, ATOM, DEATHATOM }Status;
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
	sparceMatNodePtr*arr;
	int rear;
}dyn_queue, * dyn_queuePtr;

void insertDynQueue(dyn_queuePtr, void*);
sparceMatNodePtr removeDynQueue(dyn_queuePtr);
void printDynQueue(dyn_queuePtr, void(*prn)(void*));
#endif
