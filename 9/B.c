#include <stdio.h>
#include <stdlib.h>

int main() {
  int numClasses, numStudents = 0, *studentsPerClass, **marksArray;
  double *averages, totalAverage = 0;

  printf("Enter the number of classes: ");
  scanf("%d", &numClasses);

  studentsPerClass = malloc(numClasses * sizeof(int));
  marksArray = malloc(numClasses * sizeof(int*));
  // calloc is the same as malloc, but it initialises to 0.
  // Similar to the difference between:
  // - int myInt;
  // - int myInt = 0;
  averages = calloc(numClasses, sizeof(double));

  for (int class = 0; class < numClasses; class++) {
    printf("\nEnter the number of students in class %d: ", class + 1);
    scanf("%d", &studentsPerClass[class]);
    numStudents += studentsPerClass[class];

    marksArray[class] = malloc(studentsPerClass[class] * sizeof(int));

    for (int student = 0; student < studentsPerClass[class]; student++) {
      printf("Enter the mark for student %d: ", student + 1);
      scanf("%d", &marksArray[class][student]);
    }
  }

  for (int class = 0; class < numClasses; class++) {
    for (int student = 0; student < studentsPerClass[class]; student++) {
      averages[class] += ((double)marksArray[class][student] / (double)studentsPerClass[class]);
    }

    totalAverage += studentsPerClass[class] * averages[class] / numStudents;
    printf("\nAverage for class %d: %.1f%%", class+1, averages[class]);
  }
  printf("\n\nAverage for all students: %.1f%%\n", totalAverage);

  // Freeing everything, not really necessary, but they want us to do it so...
  for (int class = 0; class < numClasses; class++) {
    free(marksArray[class]);
  }
  free(marksArray);
  free(studentsPerClass);
  free(averages);

  return 0;
}
