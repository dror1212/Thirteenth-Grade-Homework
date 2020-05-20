#pragma once
#include "Sparce.h"
void initSparce(sparceMatNodePtr* manager)
{
	sparceMatNodePtr temp = (sparceMatNodePtr)malloc(sizeof(sparceMatNode));
	temp->row = temp->col = -ONE;
	temp->data = NULL;
	temp->next = temp->bottom = temp;
	*manager = temp;
}
void AddRowSparce(sparceMatNodePtr* manager, int* h)
{
	sparceMatNodePtr temp = (sparceMatNodePtr)malloc(sizeof(sparceMatNode));
	sparceMatNodePtr curr = *manager;

	for (curr = *manager; curr->bottom != *manager; curr = curr->bottom);
	temp->bottom = curr->bottom;
	curr->bottom = temp;
	temp->next = temp;
	temp->data = NULL;
	temp->row = curr->row + ONE;
	temp->col = -ONE;
	(*h)++;
}
void AddColSparce(sparceMatNodePtr* manager, int* w)
{
	sparceMatNodePtr temp = (sparceMatNodePtr)malloc(sizeof(sparceMatNode));
	sparceMatNodePtr curr = *manager;
	for (curr = *manager; curr->next != *manager; curr = curr->next);
	temp->next = curr->next;
	curr->next = temp;
	temp->bottom = temp;
	temp->data = NULL;
	temp->col = curr->col + ONE;
	temp->row = -ONE;
	(*w)++;
}
sparceMatNodePtr findAbove(sparceMatNodePtr* manager, int row, int col)
{
	sparceMatNodePtr temp=* manager;
	sparceMatNodePtr colManager;
	unsigned short i;
	for (i = ZERO; i < col+ONE; i++)
	{
		temp = temp->next;
	}
	colManager = temp;
	while (temp->bottom->row != row && temp->bottom != colManager)
	{
		temp = temp->bottom;
	}
	return temp;
}
sparceMatNodePtr findBefore(sparceMatNodePtr* manager, int row, int col)
{
	sparceMatNodePtr temp = *manager;
	sparceMatNodePtr colManager;
	unsigned short i;
	for (i = ZERO; i < row+ONE; i++)
	{
		temp = temp->bottom;
	}
	colManager = temp;
	while(temp->next->col!= col&&temp->next!=colManager)
	{
		temp = temp->next;
	}
	return temp;
}
BOOLEAN AddItem(sparceMatNodePtr manager, int row, int col)
{
	BOOLEAN added = FALSE;
	sparceMatNodePtr temp;
	sparceMatNodePtr above = findAbove(&manager, row, col);
	sparceMatNodePtr before = findBefore(&manager, row, col);

	if (above->bottom != before->next)
	{
		temp = (sparceMatNodePtr)malloc(sizeof(sparceMatNode));
		temp->row = row;
		temp->col = col;
		temp->next = before->next;
		before->next = temp;
		temp->bottom = above->bottom;
		above->bottom = temp;
		added = TRUE;
	}
	return added;

}
void* RemoveItem(sparceMatNodePtr manager, int row, int col)
{
	BOOLEAN added = FALSE;
	sparceMatNodePtr temp;
	void* data = NULL;
	sparceMatNodePtr above = findAbove(&manager, row, col);
	sparceMatNodePtr before = findBefore(&manager, row, col);
	if (above->bottom == before->next)
	{
		temp = above->bottom;
		above->bottom = temp->bottom;
		before->next = temp->next;
		data = temp->data;
		free(temp);
	}
	return data;
}
void PrintSparce(sparceMatNodePtr manager, int h, int w)
{
	sparceMatNodePtr above;
	sparceMatNodePtr before;
	int i;
	for (i = ZERO; i < h * w; i++)
	{
		above = findAbove(&manager, i / w, i % w);
		before = findBefore(&manager, i / w, i % w);
		if (above->bottom == before->next)
			printf("1 "); // printf("%d ", (int)(above->bottom->data));
		else
			printf("0 "); // printf("NULL ");
		(i % w == w - ONE) ? puts("") : ZERO;
	}
}
void printInt(void* data)
{
	printf("%d ", *((int*)(int)data));
}
//הורדת שורה מהמסגרת כאשר לפני כן הורדת כל הצמתים ששייכים לרוחד שורה זו.

sparceMatNodePtr goToManagerRow(sparceMatNodePtr *manager, int row)
{
	sparceMatNodePtr temp = *manager;
	for (unsigned short i = ZERO; i < row+ONE; i++)
	{
		temp = temp->bottom;
	}
	return temp;
}
sparceMatNodePtr goToManagerCol(sparceMatNodePtr *manager, int col)
{
	sparceMatNodePtr temp = *manager;
	for (unsigned short i = ZERO; i < col+ONE; i++)
	{
		temp = temp->next;
	}
	return temp;
}
int DeleteRow(sparceMatNodePtr* manager, int row, int* h)
{
	int counter = ZERO;
	sparceMatNodePtr temp = *manager;
	sparceMatNodePtr temp2;
	sparceMatNodePtr curr;
	temp = goToManagerRow(manager, row);
	curr = temp;
	while (temp->next != curr)
	{
		RemoveItem(*manager, temp->next->row, temp->next->col);
		counter++;
	}
	temp2 = goToManagerRow(manager, row - ONE);
	temp2->bottom = temp->bottom;
	free(temp);
	(*h)--;
	return counter;

}
int DeleteCol(sparceMatNodePtr* manager, int col, int* w)
{
	int counter = ZERO;
	sparceMatNodePtr temp = *manager;
	sparceMatNodePtr temp2;
	sparceMatNodePtr curr;
	temp = goToManagerCol(manager, col);
	curr = temp;
	while (temp->bottom != curr)
	{
		RemoveItem(*manager, temp->bottom->row, temp->bottom->col);
		counter++;
	}
	temp2 = goToManagerCol(manager, col - ONE);
	temp2->next = temp->next;
	free(temp);
	(*w)--;
	return counter;
}