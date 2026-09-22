#include <stdio.h>
#include <math.h>

enum TriangleType {RIGHT, ACUTE, OBTUSE};

enum TriangleType triangleProperties(float a, float b, float c, float *xPtr, float *yPtr, float *zPtr);

int main() {
  float a, b, c, x, y, z;

  printf("Enter side length a: ");
  scanf("%f", &a);
  printf("Enter side length b: ");
  scanf("%f", &b);
  printf("Enter side length c: ");
  scanf("%f", &c);
  printf("\n");

  enum TriangleType triType = triangleProperties(a, b, c, &x, &y, &z);

  printf("Angle x: %.1f degrees\n", x);
  printf("Angle y: %.1f degrees\n", y);
  printf("Angle z: %.1f degrees\n", z);

  printf("Triangle type: ");
  switch (triType) {
    case RIGHT:
      printf("right\n");
      break;
    case ACUTE:
      printf("acute\n");
      break;
    case OBTUSE:
      printf("obtuse\n");
      break;
  }
}

enum TriangleType triangleProperties(float a, float b, float c, float *xPtr, float *yPtr, float *zPtr) {
  float a_sq = a*a, b_sq = b*b, c_sq = c*c;
  *xPtr = acos((b_sq + c_sq - a_sq) / (2 * b * c)) * (180.0 / M_PI);
  *yPtr = acos((a_sq + c_sq - b_sq) / (2 * a * c)) * (180.0 / M_PI);
  *zPtr = acos((a_sq + b_sq - c_sq) / (2 * a * b)) * (180.0 / M_PI);

  float max = *xPtr;
  if (*yPtr > max) max = *yPtr;
  if (*zPtr > max) max = *zPtr;

  if (max < 90.0) return ACUTE;
  if (max == 90.0) return RIGHT;
  return OBTUSE;
}
