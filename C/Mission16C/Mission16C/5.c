#pragma once
#include "General.h"
void main(void)
{
	byte arr[THREE] = { 0x7f,0x1f,0x7 };
	unsigned short removeRow = ZERO;
	unsigned short removeTimes = ZERO;
	unsigned short found = ZERO;
	PrintRows(arr, THREE);
	int counter = FOUR * FOUR;
	while (counter > ONE && found == ZERO)
	{
		printf("Enter from what row you want to remove");
		scanf("%hu", &removeRow);
		printf("How Many ?");
		scanf("%hu", &removeTimes);
		for (int i = ONE; i <= THREE; i++)
		{
			if (removeRow == i)
			{
				RemoveBits(arr + i, removeTimes, &counter);
			}
		}
		PrintRows(arr, THREE);
		if (counter == ONE)
		{
			found = ONE;
		}
		else
		{
			Bot5(arr, THREE, &counter);
			printf("Robot removed : \n");
			PrintRows(arr, THREE);
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