#include <stdio.h>
#include <string.h>
//#include "question4.h"

/*
CMPT 125 Assignment 1 Question 4
Author: jaeui song
Student ID: jsa336
SFU email: jsa336@sfu.ca
Academic honesty statement: I hereby confirm that this is my own work and I have
not violated any of SFU’s Code of Academic Integrity and Good Conduct (S10.01).
Description: mathoperation
*/

int performMathOp(char* operation)  {
  
  while (operation != "\0") {
    char* plus;
    char* minus;
    char* multiply;

    plus = strstr(operation, "+");
    minus = strstr(operation, "-");
    multiply = strstr(operation, "*");

    if (plus != NULL) {
      
      
    }
    else if (minus != NULL) {


    }
    else if (multiply != NULL) {


    }



    operation++;
  }
  

  
  
}

int main() {
  printf("%d\n", performMathOp("12+345"));
  printf("%d\n", performMathOp("0-4"));
  printf("%d\n", performMathOp("13*13"));

  return 0;
}
