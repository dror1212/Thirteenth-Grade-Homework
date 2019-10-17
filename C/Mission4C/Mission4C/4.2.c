#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define TWO 2.0
#define ONE 1.0
#define ZERO 0

#define ABSOLUTE(x) ((x > ZERO)? x : -x)
#define MAX(a,b) ((a + b) / TWO + ABSOLUTE((a - b) / TWO))

#define BOOLEAN unsigned short
#define TRUE 1
#define FALSE 0

void main5(void)
{
	// Variable definition
	unsigned short myRow = ZERO;
	unsigned short myCol = ZERO;
	unsigned short kingRow = ZERO;
	unsigned short kingCol = ZERO;
	BOOLEAN a = TRUE;
	BOOLEAN b = FALSE;

	// Chek if the spire threatens the king
	if((myRow==kingRow) || (myCol = kingCol)){}

	// Check if the runner threatens the king
	if((ABSOLUTE((myRow - kingRow)) == ONE)&& ABSOLUTE((myCol - kingCol)) == ONE){}
	
	// Check if the horseman threatens the king
	if(((ABSOLUTE(myRow - kingRow)== TWO)&&(ABSOLUTE(myCol - kingCol) == ONE))||((ABSOLUTE(myRow - kingRow) == ONE) && (ABSOLUTE(myCol - kingCol) == TWO))){}

	// XOR in two ways
	if((a && !b)||(b && !a)){}
	if((a || b) && !(a && b)){}
}