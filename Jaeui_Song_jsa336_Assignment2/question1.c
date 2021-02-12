#include <stdio.h>
#include "question1.h"

/*
CMPT 125 Assignment 2 Question 1
Author: Jaeui Song
Student ID: jsa336
SFU email: jsa336@sfu.ca
Academic honesty statement: I hereby confirm that this is my own work and I have
not violated any of SFU’s Code of Academic Integrity and Good Conduct (S10.01).
Description: expanding integer
*/

unsigned int expand_int(unsigned int number) {

    if (number == 0) {
        return 0;
    }
    else {
        
        return (number%10) + 100*expand_int(number/10);
        
    }
}