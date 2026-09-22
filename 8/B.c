#include <ctype.h>
#include <stdio.h>

int isPalindrome(const char * const lowPtr, const char * const highPtr);
int getStringLength(const char string[]);

int main() {
  char input[41];
  char *lowPtr, *highPtr;
  int strLength;

  printf("Enter a word: ");
  scanf("%40s", input);
  printf("\n");

  strLength = getStringLength(input);

  lowPtr = &input[0];
  highPtr = &input[strLength-1];

  if (isPalindrome(lowPtr, highPtr)) {
    printf("\"%s\" IS a palindrome!\n", input);
  } else {
    printf("\"%s\" IS NOT a palindrome!\n", input);
  }
}

int isPalindrome(const char * const lowPtr, const char * const highPtr) {
  int isPal = 1;

  if (highPtr > lowPtr) {
    if (tolower(*lowPtr) == tolower(*highPtr)) {
      isPal = isPalindrome(lowPtr + 1, highPtr - 1);
    } else {
      isPal = 0;
    }
  }
  return isPal;
}

int getStringLength(const char string[]) {
  int i = 0;
  while (string[i] != '\0') {
    i++;
  }
  return i;
}
