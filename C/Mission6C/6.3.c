#pragma once

void main3(void)
{
	unsigned int firstNumber;
	unsigned int secondNumber;

	scanf("%u %u", &firstNumber, &secondNumber);
	printf("%u", ToDecimal(firstNumber, secondNumber));
	scanf("%u %u", &firstNumber, &secondNumber);

}