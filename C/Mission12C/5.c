#pragma once

#include "General.h"

void main1(void)
{
	string a;
	string b;
	scanf("%s", &a);
	scanf("%s", &b);
	printf("%d", findStr(&a, &b));
	scanf("%s", &a);

}