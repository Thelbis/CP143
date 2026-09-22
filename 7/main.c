#include "matrix.h"

int main() {
  time(NULL);
  srand(time(NULL));

  int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE], A_T[SIZE][SIZE];

  fillRandom(A, SIZE);
  fillRandom(B, SIZE);

  matMultiply(A, B, C, SIZE);
  transpose(A, A_T, SIZE);

  printf("A =\n");
  printMatrix(A, SIZE);
  printf("\n");

  printf("B =\n");
  printMatrix(B, SIZE);
  printf("\n");

  printf("C = A x B =\n");
  printMatrix(C, SIZE);
  printf("\n");

  printf("A transposed =\n");
  printMatrix(A_T, SIZE);

  return 0;
}
