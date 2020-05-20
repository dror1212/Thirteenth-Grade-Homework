#include"dinQueue.h"
void initDynQueue(dyn_queuePtr q)
{
	q->arr = NULL;
	q->rear = 0;
}
BOOLEAN isEmptyDynQueue(dyn_queuePtr q)
{
	return (BOOLEAN)!(q->rear);
}

void insertDynQueue(dyn_queuePtr q, sparceMatNodePtr data)
{
	if (!q->rear)
		q->arr = (sparceMatNodePtr*)malloc(sizeof(sparceMatNode) * ++(q->rear));
	else
		q->arr = (sparceMatNodePtr*)realloc(q->arr, sizeof(sparceMatNode)*++(q->rear));
	if(q->arr != NULL)
		q->arr[q->rear - 1] = data;
}
sparceMatNodePtr removeDynQueue(dyn_queuePtr q)
{
	sparceMatNodePtr data = *(q->arr);
	memcpy(q->arr, q->arr + 1, sizeof(sparceMatNodePtr)*--(q->rear));
	
	q->arr = (sparceMatNodePtr*)realloc(q->arr, sizeof(sparceMatNode)*q->rear);
	(!(q->rear)) ? q->arr = NULL : 0;
	return data;
}

void printDynQueue(dyn_queuePtr q, void(*prn)(sparceMatNodePtr))
{
	int tempSize = q->rear;
	sparceMatNodePtr data;
	while (tempSize--)
	{
		data = removeDynQueue(q);
		prn(data);
		insertDynQueue(q, data);
	}
	puts("print end");
}