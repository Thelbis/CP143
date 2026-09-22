#include <stdio.h>

void displayArray(const double *elementPtr);

int main() {
  double dblArr[5] = {13.4, 23.4, -16.67, 9.0, 127.9903};
  double *dblPtr = &dblArr[0];

  printf("REFERRING TO MEMORY BLOCK USING ARRAY NAME:\n");
  for (int i = 0; i < 5; i++) {
    printf("Value stored at index %d: %6.1f; Address at index %d: %p\n", i, dblArr[i], i, (void *) &dblArr[i]);
  }
  printf("\n");

  printf("REFERRING TO MEMORY BLOCK BY USING THE POINTER WITH [] NOTATION:\n");
  for (int i = 0; i < 5; i++) {
    printf("Value stored at index %d: %6.1f; Address at index %d: %p\n", i, dblPtr[i], i, dblPtr + i);
  }
  printf("\n");

  printf("REFERRING TO MEMORY BLOCK BY USING THE POINTER WITH * NOTATION:\n");
  for (int i = 0; i < 5; i++) {
    printf("Value stored at index %d: %6.1f; Address at index %d: %p\n", i, *(dblPtr + i), i, dblPtr + i);
  }
  printf("\n");

  printf("REFERRING TO MEMORY BLOCK BY USING THE POINTER PASSED TO FUNCTION:\n");
  displayArray(dblArr);
  return 0;
}

void displayArray(const double *elementPtr) {
  printf("Value stored at index %d: %6.1f; Address at index %d: %p\n", 0, *elementPtr, 0, elementPtr);
  elementPtr++;
  printf("Value stored at index %d: %6.1f; Address at index %d: %p\n", 1, *elementPtr, 1, elementPtr);
  elementPtr++;
  printf("Value stored at index %d: %6.1f; Address at index %d: %p\n", 2, *elementPtr, 2, elementPtr);
  elementPtr++;
  printf("Value stored at index %d: %6.1f; Address at index %d: %p\n", 3, *elementPtr, 3, elementPtr);
  elementPtr++;
  printf("Value stored at index %d: %6.1f; Address at index %d: %p\n", 4, *elementPtr, 4, elementPtr);
}
