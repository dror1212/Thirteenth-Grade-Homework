#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <C:\\Users\\dror\\Desktop\\college\\DrorMacros\\DrorMacros\\macros.c>
#include <C:\\Users\\dror\\Desktop\\college\\DrorFunctions\\DrorFunctions\\functions.c>

void main1(void)
{
	unsigned int firstDate;
	unsigned int secondDate;

	scanf("%u %u", &firstDate, &secondDate);
	printf("%08u", DifInTime(firstDate, secondDate));
	scanf("%u %u", &firstDate, &secondDate);
}