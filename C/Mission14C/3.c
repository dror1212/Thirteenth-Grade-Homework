#include "General.h"

void main3(void)
{
	int howManyDigits;
	int howManyNums;
	int * ptr;
	
	printf("How many numbers?\n");
	scanf("%d", &howManyNums);

	printf("How many digits to save?\n");
	scanf("%d", &howManyDigits);

	ptr = createAMatrixFromAmountOfDigits(howManyNums, howManyDigits);
	int * ptrStart = ptr;
	for (int i = 0; i < howManyNums *howManyDigits; i++)
	{
		printf("%d",(*ptr));
		ptr++;
	}
	free(ptrStart);
	_getch();
}