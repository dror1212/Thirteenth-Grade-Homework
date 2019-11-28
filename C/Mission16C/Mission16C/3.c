#pragma once
#include "General.h"
void main1(void)
{
	byte a;
	printf("enter a number");
	scanf("%hhu", &a);
	if (CountBits(a) % TWO == ZERO)
	{
		printf("Good Misgeret !! ");
	}
	else
	{
		printf("Bad Misgeret !! ");
	}
}