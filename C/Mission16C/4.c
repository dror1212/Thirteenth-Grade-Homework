#pragma once
#include "General.h"
void main2(void)
{
	byte arr[4] = { 0x7f,0x1f,0x7,0x1 };
	unsigned short removeRow = ZERO;
	unsigned short removeTimes=ZERO;
	unsigned short found = ZERO;
	PrintRows(arr, FOUR);
	int counter = FOUR * FOUR;
	while (counter>ONE&&found==ZERO)
	{
		printf("Enter from what row you want to remove");
		scanf("%hu", &removeRow);
		printf("How Many ?");
		scanf("%hu", &removeTimes);
		for (int i = ONE; i <= FOUR; i++)
		{
			if (removeRow == i)
			{
				RemoveBits(arr + i,removeTimes,&counter);
			}
		}
		PrintRows(arr, FOUR);
		if (counter == ONE)
		{
			found = ONE;
		}
		else
		{
			Bot(arr, FOUR,&counter);
			printf("Robot removed : \n");
			PrintRows(arr, FOUR);
			found = (counter == ONE) ? TWO : ZERO;
		}
		
	}
	if (found == ONE)
	{
		printf("The player has beaten the computer !! well done ! ");

	}
	else
	{
		printf("The computer has won, easy.. ");
	}




}