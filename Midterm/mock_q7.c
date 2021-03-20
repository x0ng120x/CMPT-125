#include <stdio.h>

int numOfDigits(char* sentence) {
  int i = 0;
  int count = 0;
  while (sentence[i] != '\0') {
    if (sentence[i] >= 48 && sentence[i] <= 57) {
      count++;
    }
    i++;
  }
  return count;
}

int main() {
  char* sentence = "CMPT125 is having its midterm on Mar 8";

  printf("%d", numOfDigits(sentence));
  
  return 0;
}