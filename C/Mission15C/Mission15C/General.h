#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 5
#define M 6
#define ZERO 0
#define ONE 1

int SumOfDirectionInMatrix(int mat[M][N], int startingX, int startingY, int endingX, int endingY, int directionX, int directionY);