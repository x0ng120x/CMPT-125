#include <stdio.h>
#include <stdlib.h>
#include "question4.h"

//a helper function to print the content in the array
//assumes stringArray is not NULL
void printStringArray(char* stringArray[], unsigned int size) {
  for (int i=0; i<size; i++) {
    printf("%s\n", stringArray[i]);
  }
}

int main() {
  int numberOfString;
  char string[64];

  printf("How many words are you going to input?\n");
  scanf("%d", &numberOfString);

  if (numberOfString <= 0) {
    printf("No median to be found.");
  }
  else {
    char* stringArray[numberOfString];

    for (int i = 0; i < numberOfString; i++) {
      printf("Input word #%d: ", i + 1);
      scanf("%s", string);
      if (strlen(string) > 0) {
        char* stringPtr = (char*)malloc(sizeof(char) * (strlen(string) + 1));
        if (stringPtr == NULL) {
          exit(0);
        }
        strcpy(stringPtr, string);
        stringArray[i] = stringPtr;
      } 
      else {
        break;
      }
    }
    printf("The median string is %s", getMedian(stringArray, numberOfString));

    for (int i = 0; i < numberOfString; i++) {
      free(stringArray[i]);
    }
  }
  
  return 0;
}
