#include "matrix.h"

void fillRandom(int matrix[][SIZE], int size) {
  for (int row = 0; row < size; row++) {
    for (int col = 0; col < size; col++) {
      matrix[row][col] = rand() % 19 - 9;
    }
  }
}

void printMatrix(const int matrix[][SIZE], int size) {
  for (int row = 0; row < size; row++) {
    printf("|");
    for (int col = 0; col < size; col++) {
      printf("%5d ", matrix[row][col]);
    }
    printf("|\n");
  }
}

void matMultiply(const int A[][SIZE], const int B[][SIZE], int C[][SIZE], int size) {
  for (int row = 0; row < size; row++) {
    for (int col = 0; col < size; col++) {
      C[row][col] = 0;

      for (int leftRightIdx = 0; leftRightIdx < SIZE; leftRightIdx++) {
        C[row][col] += A[row][leftRightIdx] * B[leftRightIdx][col];
      }
    }
  }
}

void transpose(const int matrix[][SIZE], int result[][SIZE], int size) {
  for (int row = 0; row < size; row++) {
    for (int col = 0; col < size; col++) {
      result[row][col] = matrix[col][row];
    }
  }
}
