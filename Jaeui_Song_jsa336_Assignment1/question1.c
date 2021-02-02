#include <stdio.h>
//#include "question1.h"
/*
CMPT 125 Assignment 1 Question 1
Author: Jaeui Song
Student ID: jsa336
SFU email: jsa336@sfu.ca
Academic honesty statement: I hereby confirm that this is my own work and I have
not violated any of SFU’s Code of Academic Integrity and Good Conduct (S10.01).
Description: interlace_ints
*/

unsigned int interlace_ints(unsigned int firstNum, unsigned int secondNum)  {
  int newone = firstNum*100000 + secondNum;
  
  return newone;
}

int main() {
  printf("%d",interlace_ints(2300, 30000));
  return 0;
}