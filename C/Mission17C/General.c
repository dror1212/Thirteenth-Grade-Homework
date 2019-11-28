#pragma once

#include "General.h"

void * twoInARow(StudyHours * stdr)
{
	StudyHours * stdrEnd = stdr + DAYS * DAYS;
	StudyHours * stdrStart = stdr;
	unsigned short temp = DAYS * (DAYS - ONE);
	StudyHours * stdrHelp = stdr + temp;
	unsigned short counter = ZERO;

	while ((stdrHelp < stdrEnd) * (THREE - counter))
	{
		counter = (compareString((*stdr).teacher,(*(stdr + DAYS)).teacher)) ? ++counter : ZERO;
		if (stdr == stdrHelp)
		{
			stdr -= temp + ONE;
			stdr++;
			stdrHelp++;
		}
		else
		{
			stdr += DAYS;
		}
	}
	
	return stdr;
}

BOOLEAN compareString(char * a, char * b)
{
	BOOLEAN found = (Len(a) == Len(b));
	while ((found) * ((*a) != '\0'))
	{
		found = ((*(a++)) != (*(b++))) ? FALSE : found;
	}
	return found;
}

unsigned short Len(char * a)
{
	char * ptrStart = a;
	while ((*a) != '\0')
	{
		a++;
	}

	return (unsigned short)(a - ptrStart);
}

int teachingHours(StudyHours * stdr, string name)
{
	StudyHours * stdrEnd = stdr + DAYS * DAYS;
	unsigned short counter = ZERO;

	while (stdr < stdrEnd)
	{
		counter += (compareString((*(stdr++)).teacher, name));
	}

	return counter;
}

int numOfStudent(StudyHours * stdr, unsigned short subject)
{
	StudyHours * stdrEnd = stdr + DAYS * DAYS;
	unsigned short counter = ZERO;

	while (stdr < stdrEnd)
	{
		counter += (subject == (*(stdr++)).totalStudents);
	}

	return counter;
}

void * findBook(Book * books, char * name, int length)
{
	Book * ptrEnd = books + length;
	Book * ptrPlace = NULL;
	while ((books < ptrEnd) * (!ptrPlace))
	{
		ptrPlace = (compareString((*books).name, name)) ? books : ptrPlace;
	}

	return ptrPlace;
}

void * findAuthor(Book * books, char * name, int length)
{
	Book * ptrEnd = books + length;
	Book * ptrPlace = NULL;
	while ((books < ptrEnd) * (!ptrPlace))
	{
		ptrPlace = (compareString((*books).author, name)) ? books : ptrPlace;
	}

	return ptrPlace;
}

void * findName(Book * books, char * name, int length,BOOLEAN who)
{
	Book * ptrPlace;
	if (who)
	{
		ptrPlace = findBook(books, name, length);
	}
	else
	{
		ptrPlace = findAuthor(books, name, length);
	}

	return ptrPlace;
}

int findAuthor(Book * books, int length)
{
	Book * ptrEnd = books + length;
	int counter;
	while ((books < ptrEnd))
	{
		counter += (((*books).year < TWO_THOUSEND) *(*books).year > ONE_THOUSEND_NINE_HUNDRED);
	}

	return counter;
}

void addBook(Book * books, int length)
{
	realloc(books, sizeof(Book) * (length + ONE));
	books += length - ONE;
	printf("what is the name?");
	scanf("%s", (*books).name);

	printf("what is the author name?");
	scanf("%s", (*books).author);

	printf("what is the price?");
	scanf("%hf", (*books).price);

	printf("what is the id?");
	scanf("%hf", (*books).id);

	printf("what is the name of company?");
	scanf("%s", (*books).nameOfCompany);

	printf("what is the year?");
	scanf("%hu", (*books).year);
}