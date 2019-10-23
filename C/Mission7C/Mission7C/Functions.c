#pragma once

#include "DrorGeneral.h"
//--------------------------------------------------------------------------------------------
//											Difference In Time
//										  ----------------------
//
// General		: The function calculates the difference between two dates.
//
// Parameters   :
//			firstDate  - First date
//			secondDate - Second date
//
// Return Value : The difference in time.
//
//--------------------------------------------------------------------------------------------
unsigned int DifInTime(unsigned int firstDate, unsigned int secondDate)
{
	// Variable definition
	unsigned int difYear;
	unsigned int difMonth;
	unsigned int difDays;
	int timeInDays;
	unsigned int temp;
	unsigned int date;

	// Calculate all the days
	timeInDays = TotalTimeFromDate(firstDate) - TotalTimeFromDate(secondDate);

	// Make it right
	timeInDays = ABSOLUTE(timeInDays);

	// Calculate the difference in time
	difYear = timeInDays / DAYS_PER_YEAR;
	timeInDays -= difYear * DAYS_PER_YEAR;
	difMonth = timeInDays / DAYS_PER_MONTH;
	timeInDays -= difMonth * DAYS_PER_MONTH;
	difDays = timeInDays;

	// Get the date
	date = DaysToDate(difYear, difMonth, difDays);

	return (date);
}

//--------------------------------------------------------------------------------------------
//											Time To Days
//										  ----------------
//
// General		: The function calculates time in years, months and days to total days.
//
// Parameters   :
//			years  - The years
//			months - The months
//			days   - the days
//
// Return Value : The time in days.
//
//--------------------------------------------------------------------------------------------
unsigned int TimeToDays(unsigned int years, unsigned int months, unsigned int days)
{
	// Calcukate the total days from the time given
	return (years * DAYS_PER_YEAR + months * DAYS_PER_MONTH + days);
}

//--------------------------------------------------------------------------------------------
//											Days To Date
//										  ----------------
//
// General		: The function gets years, months and days and change it to date.
//
// Parameters   :
//			years  - The years
//			months - The months
//			days   - the days
//
// Return Value : The date.
//
//--------------------------------------------------------------------------------------------
unsigned int DaysToDate(unsigned int years, unsigned int months, unsigned int days)
{
	unsigned int retValue;

	// Calculate the total days
	retValue = days * HUNDRED;
	retValue += months;
	retValue *= TEN_TOUSEND;
	retValue += years;

	return (retValue);
}

//--------------------------------------------------------------------------------------------
//										Total Days From Date
//									   -----------------------
//
// General		: The function gets years, months and days and change it to date.
//
// Parameters   :
//			years  - The years
//			months - The months
//			days   - the days
//
// Return Value : The date.
//
//--------------------------------------------------------------------------------------------
unsigned int TotalTimeFromDate(unsigned int date)
{
	unsigned int years;
	unsigned int months;
	unsigned int days;
	unsigned int totalDays;

	// Calculate the total days
	years = date % TEN_TOUSEND;
	date /= TEN_TOUSEND;
	months = date % HUNDRED;
	date /= HUNDRED;
	days = date;

	totalDays = TimeToDays(years, months, days);

	return (totalDays);
}

//--------------------------------------------------------------------------------------------
//											To Decimal
//										  --------------
//
// General		: The function gets a number and base and change it to 10 base value.
//
// Parameters   :
//			base   - The base
//			number - The number
//
// Return Value : The date.
//
//--------------------------------------------------------------------------------------------
unsigned int ToDecimal(unsigned int base, unsigned int number)
{
	unsigned int decimalNumber = ZERO;
	unsigned int temp = number;
	unsigned int helpBase;

	// Go on all the number and change it to Ten base
	for (helpBase = ONE; temp; temp = temp / TEN)
	{
		decimalNumber += (temp % TEN) * helpBase;
		helpBase *= base;
	}

	return (decimalNumber);
}

//--------------------------------------------------------------------------------------------
//										Sum Of Odd and Even
//									  -----------------------
//
// General		: The function gets a number and calculate the sum of a numbers made of the
//				  odd and even numbers seperately.
//
// Parameters   :
//			number - The number
//
// Return Value : The sum of the seperated numbers.
//
//--------------------------------------------------------------------------------------------
unsigned int OddAndEvenSum(unsigned int number)
{
	unsigned int even;
	unsigned int odd;
	unsigned int sum;

	// Turn the number around
	number = HipuhNumber(number);

	// Get the odd and even numbers
	even = NumberFromEvenDigits(number);
	odd = NumberFromOddDigits(number);

	// Calculate the sum
	sum = even + odd;

	return (sum);
}

//--------------------------------------------------------------------------------------------
//										Number From Odd Digits
//									  --------------------------
//
// General		: The function gets a number and create a number from the odd digits.
//
// Parameters   :
//			number - The number
//
// Return Value : The new number.
//
//--------------------------------------------------------------------------------------------
unsigned int NumberFromOddDigits(unsigned int number)
{
	unsigned int newNumber = ZERO;

	// Create a number only from the odd digits
	for (number; number; number /= TEN)
	{
		newNumber = (IS_ODD(number)) ? newNumber * TEN + number % TEN : newNumber ;
	}

	return (newNumber);
}

//--------------------------------------------------------------------------------------------
//										Number From Even Digits
//									   -------------------------
//
// General		: The function gets a number and create a number from the even digits.
//
// Parameters   :
//			number - The number
//
// Return Value : The new number.
//
//--------------------------------------------------------------------------------------------
unsigned int NumberFromEvenDigits(unsigned int number)
{
	unsigned int newNumber = ZERO;

	// Create a number only from the even digits
	for (number; number; number /= TEN)
	{
		newNumber = (IS_EVEN(number)) ? newNumber * TEN + number % TEN : newNumber;
	}

	return (newNumber);
}

//--------------------------------------------------------------------------------------------
//										Number From Even Digits
//									  --------------------------
//
// General		: The function gets a number and create a number that is the opposite.
//
// Parameters   :
//			number - The number
//
// Return Value : The new number.
//
//--------------------------------------------------------------------------------------------
unsigned int HipuhNumber(unsigned int number)
{
	unsigned int newNumber = ZERO;

	// Turn the number around
	for (number; number; number /= TEN)
	{
		// Save the numbers in the opposite order
		newNumber = newNumber * TEN + number % TEN;
	}

	return (newNumber);
}

/////////////////////////////////////////////////////////////////////////////////////////////////

unsigned int SumOfEvenDigits(unsigned int number)
{
	unsigned int sum = ZERO;
	for (number; number; number /= TEN)
	{
		sum += IS_EVEN(number) ? number % TEN : ZERO;
	}

	return (sum);
}

unsigned int SumOfOddDigits(unsigned int number)
{
	unsigned int sum = ZERO;
	for (number; number; number /= TEN)
	{
		sum += IS_ODD(number) ? number % TEN : ZERO;
	}

	return (sum);
}

unsigned int NumOfDigits(unsigned int number)
{
	unsigned int counter = ZERO;
	for (; number; number /= TEN + counter++ * ZERO) {}

	return (counter);
}

enum BOOLEAN IsIn(int number, unsigned short digit)
{
	enum BOOLEAN check = FALSE;
	for (; number * !check; number /= TEN)
	{
		check = (number % TEN == check) ? TRUE : check;
	}

	return (check);
}

unsigned long long Shirshur1(unsigned long long firstNumber, unsigned long long secondNumber) //To do better
{
	unsigned long long newNumber = ZERO;

	for (; secondNumber; secondNumber /= TEN)
	{
		// Save the numbers in the opposite order
		newNumber = newNumber * TEN + secondNumber % TEN;
	}

	for (; firstNumber; firstNumber /= TEN)
	{
		// Save the numbers in the opposite order
		newNumber = newNumber * TEN + firstNumber % TEN;
	}

	newNumber = HipuhNumber(newNumber);

	return (newNumber);
}

unsigned long long Shirshur2(unsigned long long firstNumber, unsigned long long secondNumber) //To do better
{
	unsigned long long newNumber = ZERO;
	unsigned int power = NumOfDigits((int)secondNumber);
	newNumber = firstNumber * Power(TEN, power); +secondNumber;
	return (newNumber);
}

double Power(double number, double power)
{
	enum BOOLEAN check = (number == ABSOLUTE(number));
	number = ABSOLUTE(number);
	double retValue = ONE;
	double help = ZERO;
	unsigned int intPower = (int)power;
	double less = power - (double)intPower;
	for (; intPower; intPower--)
	{
		retValue *= number;
	}
	/*
	for (; less - (int)less > 0; less *= TEN);
	help = (less > ZERO) ? ONE : ZERO;

	for (; (int)less; less--)
	{
		help *= number;
		printf("%lf\n", less);
		printf("%lf\n", help);
	}
	
	printf("%lf\n", help);
	help = (help) ? (ONE / help) : help;
	*/
	retValue += help;

	printf("%lf\n", retValue);

	return (retValue);
}

unsigned short Sum(unsigned short check[])
{
	unsigned short counter = 0;
	for (int i = 0; i < 4; i++)
	{
		counter += check[i];
	}
	return (counter);
}

unsigned short CountNotZeros(unsigned short check[], unsigned short length)
{
	unsigned short counter = ZERO;
	for (int i = ZERO; i < length + 1; i++)
	{
		counter += (check[i] != ZERO);
	}
	return (counter);
}

enum BOOLEAN CommonDigits(int firstNumber, int secondNumber)
{
	enum BOOLEAN check = FALSE;
	for (; firstNumber; firstNumber /= TEN)
	{
		for (; secondNumber; secondNumber /= TEN)
		{
			check = (firstNumber % TEN == secondNumber % TEN) ? TRUE : check;
		}
	}

	return (check);
}

enum BOOLEAN IsPrime(int num)
{
	enum BOOLEAN check = TRUE;
	unsigned int compare = TWO;
	unsigned int max = (int)NewtonSqrt(num);
	for (; compare < max + ONE; compare++)
	{
		check = (!(num % compare)) ? FALSE : check;
	}
	return (check);
}

double NewtonSqrt(double number)
{
	double answer = number;
	unsigned short counter = ZERO;
	while (answer * answer - MAX_DEVIATION > number)
	{
		answer = NEWTON(answer, number);
		counter++;
	}
	return (answer);
}

enum BOOLEAN IsPerfect(unsigned int num)
{
	enum BOOLEAN check;
	unsigned int max = (int)NewtonSqrt(num) + ONE;
	unsigned int sum = ONE;
	printf("%u\n", sum);
	unsigned int counter = TWO;
	for (; counter < max; sum += (num / counter + counter) * (!(num % counter)) + (counter++ * ZERO)) {}
	printf("%u\n", sum);
	check = (sum == num) ? TRUE : FALSE;

	return (check);
}

int MaxInVector(int vec[], unsigned int startingOffset)
{
	int max = vec[startingOffset++];
	for (; startingOffset < LENGTH_OF_VECTOR; max = (int)MAX(max, vec[startingOffset]) + startingOffset++ * ZERO){}

	return (max);
}

int MinInVector(int vec[], unsigned int startingOffset)
{
	int min = vec[startingOffset++];
	for (; startingOffset < LENGTH_OF_VECTOR; min = (int)MIN(min, vec[startingOffset]) + startingOffset++ * ZERO) {}

	return (min);
}

void VectorDifference(int vec[], int value, int difference[])
{
	int counter = ZERO;
	for(; counter < LENGTH_OF_VECTOR; difference[counter] = ABSOLUTE(vec[counter] - value) + counter++ * ZERO) {}
}

float Average(int vec[])
{
	int ave = ZERO;
	int counter;
	int sum;
	for (counter = LENGTH_OF_VECTOR - ONE; counter; counter--)
	{
		sum += vec[counter];
	}

	return ((float)sum / LENGTH_OF_VECTOR);
}

unsigned short CountBigger(int vec[], int num)
{
	int counter;
	int bigger = ZERO;
	for (counter = LENGTH_OF_VECTOR - ONE; counter; counter--)
	{
		bigger += (vec[counter] > num) ? ONE : ZERO;
	}

	return (bigger);
}