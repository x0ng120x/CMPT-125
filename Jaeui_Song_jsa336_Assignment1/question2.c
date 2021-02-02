#include <stdio.h>
#include <string.h>
//#include "question2.h"

/*
CMPT 125 Assignment 1 Question 2
Author: jaeui song 
Student ID: jsa336
SFU email: jsa336@sfu.ca
Academic honesty statement: I hereby confirm that this is my own work and I have
not violated any of SFU’s Code of Academic Integrity and Good Conduct (S10.01).
Description: findpair
*/

void findPair(int arrays[], unsigned int size, int target, char* result) {
  int i;
  int j;
  int count = 0;
  int sum;
  for (i=0; i<size; i++)  {
    for (j=0; j<size; j++)  {
      sum = arrays[i] + arrays[j];
      
      if (sum == target)  {
        char s1[20];
        char s2[20];
        sprintf(s1, "%d", arrays[i]);
        sprintf(s2, "%d", arrays[j]);
        strcat(result, s1);
        strcat(result, "+");
        strcat(result, s2);
        strcat(result, " ");
        count++;
      }
      
      
    }
  }
  if (count == 0) {
    strcpy(result, "not_found");
  }
}

int main() {
  int intArr1[] = {-1, 0, 2, 3, 4, 5, 6, 7};
  char pair[32];
  char pair2[32];
  char pair3[32];

  findPair(intArr1, 8, 25, pair3);
  printf("%s\n", pair3);

  findPair(intArr1, 8, -1, pair);
  printf("%s\n", pair);

  findPair(intArr1, 8, 5, pair2);
  printf("%s\n", pair2);

  

  return 0;
}
