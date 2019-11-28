#include "General.h"

void main1(void)
{
	int arr[] = { 0, 1, 2, 32, 4, 5 ,14};

	puts(arr);
	int amount = ZERO;
	int * ptr = EvenSubArray(arr, 7, &amount);
	int * ptrStart = ptr;
	int * ptrEnd = ptr + amount;
	if (amount > 0)
	{
		for (; ptr < ptrEnd; ptr++)
		{
			printf("%-3d", *ptr);
		}
		puts("");
	}
	else
	{
		printf("There are no even numbers");
	}
	free(ptrStart);
	_getch();
	
}