#pragma once

#include "General.h"

void main(void)
{
	int num = 10;
	int num2 = 327;
	int answer = 0;
	Concatenation(&num, &num2, &answer);
	printf("%d", answer);
	scanf("%d", num);
}