#include <math.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct {
  int dim;
  double *data;
} Vector;

enum ResultType {SUCCESS, FAIL};
typedef enum ResultType Result;

void fillVector(Vector *vPtr);
void emptyVector(Vector *vPtr);
void printVector(Vector v);
Result dotProduct(Vector v1, Vector v2, double *product);
double norm(Vector v);

int main() {
  Vector vec1, vec2;
  double product, normVec1, normVec2;
  Result dotResult;

  printf("For first vector:\n");
  fillVector(&vec1);
  printf("\n");

  printf("For second vector:\n");
  fillVector(&vec2);
  printf("\n");

  dotResult = dotProduct(vec1, vec2, &product);
  if (dotResult == SUCCESS) {
    printVector(vec1);
    printf(" . ");
    printVector(vec2);
    printf(" = %.3f\n\n", product);
  } else if (dotResult == FAIL) {
    printf("Dot product cannot be calculated!\n\n");
  }

  normVec1 = norm(vec1);
  printf("||");
  printVector(vec1);
  printf("|| = %.3f\n\n", normVec1);

  normVec2 = norm(vec2);
  printf("||");
  printVector(vec2);
  printf("|| = %.3f\n\n", normVec2);

  emptyVector(&vec1);
  emptyVector(&vec2);
  return 0;
}

void fillVector(Vector *vPtr) {
  printf("Enter vector dimension: ");
  scanf("%d", &(vPtr->dim));
  vPtr->data = malloc(vPtr->dim * sizeof(double));

  for (int element = 0; element < vPtr->dim; element++) {
    printf("Enter element %d: ", element);
    scanf("%lf", &(vPtr->data[element]));
  }
  return;
}

Result dotProduct(Vector v1, Vector v2, double *product) {
  if (v1.dim != v2.dim) {
    return FAIL;
  }

  double sum = 0;
  for (int i = 0; i < v1.dim; i++) {
    sum += v1.data[i] * v2.data[i];
  }
  *product = sum;

  return SUCCESS;
}

void printVector(Vector v) {
  if (v.dim <= 0) {
    printf("(UNDEFINED)");
    return;
  }

  printf("(");
  for (int i = 0; i < v.dim-1; i++) {
    printf("%.1f, ", v.data[i]);
  }
  printf("%.1f)", v.data[v.dim]);
  return;
}

double norm(Vector v) {
  double norm2;
  dotProduct(v, v, &norm2);
  return sqrt(norm2);
}

void emptyVector(Vector *vPtr) {
  free(vPtr->data);
}
