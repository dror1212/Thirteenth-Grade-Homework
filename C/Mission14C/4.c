#include "General.h"

void main4(void)
{
	int vec[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int *even;
	int *odd;
	int evensize;
	int oddsize;

	seperateEvenAndOddPointers(vec, 10, &evensize, &even, &oddsize, &odd);
	_getch();
}