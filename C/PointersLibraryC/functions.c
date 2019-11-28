#pragma once

#include "General.h"

void IsEven(int * ptr, BOOLEAN * answer)
{

	(*answer) = !((*ptr) % TWO);
}

void IsOdd(int * ptr,BOOLEAN * answer)
{
	(*answer) = ((*ptr) % TWO);
}

void Switch(int *firstPtr, int *secondPtr)
{
	int temp = (*firstPtr);
	(*firstPtr) = (*secondPtr);
	(*secondPtr) = temp;
}

void Sum(int *firstPtr, int *secondPtr, int *sum)
{
	(*sum) = (*firstPtr) + (*secondPtr);
}

void SumOfEvenDigits(int *ptr, int *sum)
{
	(*sum) = ZERO;
	int temp = (*ptr);
	for (; temp; temp /= TEN)
	{
		(*sum) += (temp % TWO == ZERO) ? (temp % TEN): ZERO;
	}
}

void SumOfOddUnEvenDigits(int *ptr, int *sum)
{
	(*sum) = ZERO;
	int temp = (*ptr);
	for (; temp; temp /= TEN)
	{
		(*sum) += (temp % TWO == ONE) ? (temp % TEN) : ZERO;
	}
}

void IsExist(int *numberPtr, int *digitPtr, BOOLEAN * exist)
{
	(*exist) = FALSE;
	int temp = (*numberPtr);
	for (;temp;temp /= TEN)
	{
		(*exist) = ((*digitPtr) == temp % TEN) ? TRUE : (*exist);
	}
}

void Length(int *numberPtr, int * length)
{
	int temp = (*numberPtr);
	for (;temp;temp /= TEN)
	{
		(*length)++;
	}
}

void SumOfDigits(int *numberPtr, int * sum)
{
	(*sum) = ZERO;
	int temp = (*numberPtr);
	for (;temp;temp /= TEN)
	{
		(*sum) += temp % TEN;
	}
}

void Power(int * powerPtr, double * numberPtr, double * answer)
{
	int temp = (*powerPtr);
	double help = (*numberPtr);
	for (--temp;temp;temp--)
	{
		help *= (*numberPtr);
	}
	(*answer) = help;
}

//---------------------------------------------------------------------------------------
//                                 		Concatenation
//                                 		-------------
//
//     General 		: The function connect two numbers into one number.
//
//     Parameters 	:
//         firstPtr			- number_pointer(In)
//         secondPtr 		- number_pointer(In)
//		   newNumberPtr 	- result pointer(In)
//
//     Return Value : None
//
//---------------------------------------------------------------------------------------
// Programmer 	: Dror Tal
// Student No 	: 322534793
// date 		: 8.11.2019
//---------------------------------------------------------------------------------------
void Concatenation(int * firstPtr, int * secondPtr, int * newNumberPtr)
{
	int value =	ZERO;
	double valueHelp = ZERO;
	int *length = &value;
	double ten = TEN;
	double *tenPtr = &ten;
	double *helpPtr = &valueHelp;

	Length(firstPtr, length);
	Power(length, tenPtr, helpPtr);
	(*newNumberPtr) = (int)(*helpPtr);
	(*newNumberPtr) = (*newNumberPtr) * (*secondPtr) + (*firstPtr);
}

void SameDigit(int * firstPtr, int * secondPtr, BOOLEAN * answer)
{
	int firstNumber = (*firstPtr);
	int secondNumber = (*secondPtr);
	(*answer) = FALSE;
	for (; firstNumber; firstNumber /= TEN)
	{
		for (secondNumber = *secondPtr; secondNumber; secondNumber /= TEN)
		{
			(*answer) = (secondNumber % TEN == firstNumber % TEN);
		}
	}
}

void numberFromEvenDigits(int *numberPtr, int *newNumber)
{
	(*newNumber) = ZERO;
	int temp = (*numberPtr);
	for (; temp; temp /= TEN)
	{
		(*newNumber) = (temp % TWO) ? (*newNumber) : ((*newNumber) * TEN + temp % TEN);
	}
}

void numberFromOddDigits(int *numberPtr, int *newNumber)
{
	(*newNumber) = ZERO;
	int temp = (*numberPtr);
	for (; temp; temp /= TEN)
	{
		(*newNumber) = (temp % TWO) ? ((*newNumber) * TEN + temp % TEN) : (*newNumber);
	}
}

void IsPrime(int *numberPtr, BOOLEAN * check)
{
	(*check) = FALSE;
	int temp = TWO;
	for (;temp < (*numberPtr) / TWO + ONE; temp++)
	{
		(*check) = ((*numberPtr) % temp == ZERO) ? TRUE : (*check);
	}
}

void IsPerfect(int *numberPtr, BOOLEAN * check)
{
	int temp = TWO;
	int sum = ONE;
	for (;temp < (*numberPtr) / TWO + ONE; temp++)
	{
		sum += ((*numberPtr) % temp == ZERO) ? (temp + ((*numberPtr) / temp)) : ZERO;
	}
	(*check) = ((*numberPtr) == sum);
}

void Opposite(int *numberPtr, int *newNumberPtr)
{
	(*newNumberPtr) = ZERO;
	int temp = *numberPtr;
	for (;temp;temp /= TEN)
	{
		(*newNumberPtr) = (*newNumberPtr) * TEN + temp % TEN;
	}
}

//---------------------------------------------------------------------------------------
//                                 		Divide
//                                 		------
//
//     General 		: The function divide between two numbers.
//
//     Parameters 	:
//         ptr_first_number		- number_pointer(In)
//         ptr_second_number 	- number_pointer(In)
//		   ptr_result 			- result pointer(In)
//
//     Return Value : None
//
//---------------------------------------------------------------------------------------
// Programmer 	: Dror Tal
// Student No 	: 322534793
// date 		: 8.11.2019
//---------------------------------------------------------------------------------------
void Divide(double *ptr_first_number, double *ptr_second_number, int *ptr_result)
{
	//definding variables.
	double first_number = (*ptr_first_number);
	double second_number = (*ptr_second_number);
	int answer = ZERO;
	short sign = (first_number > ZERO) ? ONE : -ONE;
	sign = (second_number > ZERO) ? sign : -sign;

	//run inside the loop until the second number is bigger than the first number.
	while (first_number >= second_number)
	{
		//substract from the first number the second number.
		first_number -= second_number;
		//increase the answer.
		answer++;
	}
	//if the signs are different, than the result is negative, else the result is positive.
	(*ptr_result) = (sign > ZERO) ? answer : answer - answer - answer;
}

//---------------------------------------------------------------------------------------
//                                 		Divide The Rest
//                                 		---------------
//
//     General 		: The function divide between two numbers and put in 
//					  the result the rest of the divide.
//
//     Parameters 	:
//         ptr_first_number		- number_pointer(In)
//         ptr_second_number 	- number_pointer(In)
//		   ptr_result 			- result pointer(In)
//
//     Return Value : None
//
//---------------------------------------------------------------------------------------
// Programmer 	: Dror Tal
// Student No 	: 322534793
// date 		: 8.11.2019
//---------------------------------------------------------------------------------------
void Module(int *ptr_first_number,int *ptr_second_number, int *ptr_result)
{
	//definding variables.
	int first_number = (*ptr_first_number);
	int second_number = (*ptr_second_number);
	short sign = (first_number > ZERO) ? ONE : -ONE;
	sign = (second_number > ZERO) ? sign : -sign;

	//run inside the loop until the second number is bigger than the first number.
	while (first_number >= second_number)
	{
		//substract from the first number the second number.
		first_number -= second_number;
	}
	//if the signs are different, than the result is negative, else the result is positive.
	(*ptr_result) = (sign > ZERO) ? (first_number) : (first_number - first_number - first_number);
}

//---------------------------------------------------------------------------------------
//                             Base unknown to base 10
//                             -----------------------
//
//     General : The function take a number and a base and translates it to base 10
//
//     Parameters :
//         ptr_base 		- base of the number_pointer(In)
//         ptr_number 		- number_pointer(In)
//         ptr_result		- number_pointer(In)
//
//     Return Value : None
//
//---------------------------------------------------------------------------------------
// Programmer 	: Dror Tal
// Student No 	: 322534793
// date 		: 8.11.2019
//---------------------------------------------------------------------------------------
void BaseTransform(int *ptr_number, int *ptr_base, double *ptr_result)
{
	//definding variables.
	unsigned short number = *ptr_number;
	unsigned short counter = ZERO;
	int sum = ZERO;
	double (*ptr_sum);

	//run on the number.
	for(;number;number/=TEN)
	{
		//get the poser of the base in the counter.
		Power((*ptr_base), counter,ptr_sum);
		//add to sum the multiply between the last digit and the result of the power.
		sum += (number % TEN) * (*ptr_sum);
	}
	(*ptr_result) = sum;
}

//---------------------------------------------------------------------------------------
//                             		Date Delta
//                             		----------
//
//     General : The function take a number and a base and translates it to base 10
//
//     Parameters :
//         ptr_first_date 		- the first date pointer(In)
//         ptr_second_date 		- the second date pointer(In)
//         ptr_result			- result pointer(In)
//
//     Return Value : None
//
//---------------------------------------------------------------------------------------
// Programmer 	: Dror Tal
// Student No 	: 322534793
// date 		: 8.11.2019
//---------------------------------------------------------------------------------------
void DateDelta(int *ptr_first_date, int *ptr_second_date, int *ptr_result)
{
	//definding variables.
	int date_one = *ptr_first_date;
	int date_two = *ptr_second_date;
	int date1_in_days = ZERO;
	int date2_in_days = ZERO;
	int delta = ZERO;
	int month_delta = ZERO;
	int year_delta = ZERO;

	//insert to date1_in_days the date after he converted to days.
	date1_in_days = (date_one % TEN_THOUSND) * DAYS_IN_YEAR;
	date_one /= TEN_THOUSND;
	date1_in_days += (date_one % HUNDRED)*DAYS_IN_MONTH;
	date_one /= HUNDRED;
	date1_in_days += date_one;

	//insert to date2_in_days the date after he converted to days.
	date2_in_days = (date_two% TEN_THOUSND) * DAYS_IN_YEAR;
	date_two /= TEN_THOUSND;
	date2_in_days += (date_two % HUNDRED)*DAYS_IN_MONTH;
	date_two /= HUNDRED;
	date2_in_days += date_two;

	//insert to delta the delta between the dates.
	delta = (date2_in_days > date1_in_days) ? date2_in_days - date1_in_days
		: date1_in_days - date2_in_days;

	//insert to year_delta the years.
	year_delta = delta / DAYS_IN_YEAR;

	//substract from delta the years.
	delta = delta - year_delta * DAYS_IN_YEAR;

	//insert to month_delta the months.
	month_delta = delta / DAYS_IN_MONTH;

	//substract from delta the months.
	delta = delta - month_delta * DAYS_IN_MONTH;

	//merge the month_delta and the year_delta with the remaining days.
	delta = delta * TEN_THOUSND + month_delta * HUNDRED + year_delta;

	*ptr_result = delta;
}