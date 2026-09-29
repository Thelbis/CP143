#include <stdio.h>
typedef struct {
  float real;
  float imag;
} Complex;

Complex addComplex(Complex n1, Complex n2);

int main() {
  Complex n1, n2, n3;

  printf("For the first complex number:\n");
  printf("Enter the real part: ");
  scanf("%f", &n1.real);
  printf("Enter the imaginary part: ");
  scanf("%f", &n1.imag);

  printf("\nFor the second complex number:\n");
  printf("Enter the real part: ");
  scanf("%f", &n2.real);
  printf("Enter the imaginary part: ");
  scanf("%f", &n2.imag);

  n3 = addComplex(n1, n2);

  printf("\n(%.2f + %.2fi) + (%.2f + %.2fi) = %.2f + %.2fi\n", n1.real, n1.imag, n2.real, n2.imag, n3.real, n3.imag);

  return 0;
}

Complex addComplex(Complex n1, Complex n2) {
  return (Complex){n1.real + n2.real, n1.imag + n2.imag};
}
