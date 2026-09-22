#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#define SIZE 2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMatrix(const int matrix[][SIZE], int size);
void fillRandom(int matrix[][SIZE], int size);
void matMultiply(const int A[][SIZE], const int B[][SIZE], int C[][SIZE], int size);
void transpose(const int matrix[][SIZE], int result[][SIZE], int size);

#endif // MATRIX_H_INCLUDED
