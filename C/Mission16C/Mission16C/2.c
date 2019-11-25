#pragma once
#include "General.h"

void main(void)
{
	int x;
	int N;
	scanf("%d", &x);
	scanf("%d", &N);
	printf("%u", rotationLeft(x,N));
	_getche();
}  