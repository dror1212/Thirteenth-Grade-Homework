// General.h

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <conio.h>

#define UPPER 12
#define FULL_SIZE 144
#define BOMBS 14
#define ZERO 0
#define ONE 1
#define BOOLEAN char
#define FALSE 0
#define TRUE 1
#define TWO 2
#define TEN 10

// Typedef declaration
typedef char string[1000];
typedef struct hiddenShort
{
    short value;
    BOOLEAN isHidden;
} hiddenShort;

// The functions
void init(hiddenShort **mat);
void setBombs(hiddenShort *mat, char * ptr);
BOOLEAN printMatrixAndCheck(hiddenShort *mat);
short tryHit(hiddenShort *mat);
unsigned short getRow(unsigned short y);
unsigned short getCol(unsigned short x);
void updateNeighors(hiddenShort *mat, unsigned short counter);
void hit(hiddenShort * mat, BOOLEAN * check, BOOLEAN * lose);
unsigned short getInfo(hiddenShort * mat, BOOLEAN * check);
void play();