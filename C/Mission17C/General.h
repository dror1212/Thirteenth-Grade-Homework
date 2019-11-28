#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>

#define SIZE 1000
#define ONE 1
#define ZERO 0
#define TWO 2
#define THREE 3
#define MAXSIZE 5
#define DAYS 6
#define BOOLEAN unsigned short
#define TRUE 1
#define FALSE 0
#define TWO_THOUSEND 2000
#define ONE_THOUSEND_NINE_HUNDRED 1900

typedef char string[SIZE];

typedef struct
{
	string teacher;
	unsigned short subjet;
	int totalStudents;
} StudyHours;

typedef struct
{
	char * name;
	char * author;
	char * nameOfCompany;
	unsigned short year;
	float price;
	int id;
} Book;

void * twoInARow(StudyHours * stdr);
BOOLEAN compareString(char * a, char * b);
unsigned short Len(char * a);
int teachingHours(StudyHours * stdr, string name);
int numOfStudent(StudyHours * stdr, unsigned short subject);
void * findBook(Book * books, char * name, int length);
void * findAuthor(Book * books, char * name, int length);
void * findName(Book * books, char * name, int length, BOOLEAN who);