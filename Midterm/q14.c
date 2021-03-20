#include <stdio.h>

void myToLower(char* str, unsigned int value) {
  int i = 0;
  if (value % 2 == 0) {         // even case
    while (str[i] != '\0') {
      if (i % 2 == 0 && str[i] >= 65 && str[i] <= 90) {
        str[i] = str[i] + 32;
      }
      i++;
    }
  }
  else if (value % 2 == 1) {                        // odd case
    while (str[i] != '\0') {
      if (i % 2 == 1 && str[i] >= 65 && str[i] <= 90) {
        str[i] = str[i] + 32;
      }
      i++;
    }
  }
}

int main() {
  char str1[] = "HELLOE FAEWFAWEFAWE 123FAWEFEAW";
  myToLower(str1, 2); //same result if 0 is replaced with 2, 4, 6, ...etc.
  printf("%s\n", str1);

  char str2[] = "We had our very first CMPT125 class on January 11.";
  myToLower(str2, 3); //same result if 1 is replaced with 3, 5, 7, ...etc.
  printf("%s\n", str2);

  return 0;
}