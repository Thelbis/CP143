#include <stdio.h>
#include <stdlib.h>
void sortArray(int array[], int size);
float average(const int array[], int size);

int main() {
  int *intPtr;
  int numStudents;
  int min, max, median;
  float avg;

  printf("Enter the number of students: ");
  scanf("%d", &numStudents);

  intPtr = malloc(sizeof(int) * numStudents);

  for (int i = 0; i < numStudents; i++) {
    printf("Enter the mark for student %d: ", i+1);
    scanf("%d", intPtr + i);
  }

  sortArray(intPtr, numStudents);
  min = intPtr[0];
  max = intPtr[numStudents-1];
  median = intPtr[numStudents/2];
  avg = average(intPtr, numStudents);

  printf("Minimum mark: %d\n", min);
  printf("Maximum mark: %d\n", max);
  printf("Median mark: %d\n", median);
  printf("Average mark: %.1f\n", avg);

  return 0;
}

void sortArray(int array[], int size) {
  for (int pass = 0; pass < size-1; pass++) {
    int swapped = 0;
    for (int i = 0; i < size-1-pass; i++) {
      if (array[i] > array[i+1]) {
        int tmp = array[i];
        array[i] = array[i+1];
        array[i+1] = tmp;
        swapped = 1;
      }
    }
    if (!swapped) break;
  }
}

float average(const int array[], int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += array[i];
  }

  return (float) sum / size;
}
