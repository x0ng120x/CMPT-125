#include <stdio.h>
#include <math.h>
#include "question2.h"

/*
CMPT 125 Assignment 2 Question 2
Author: Jaeui Song
Student ID: jsa336
SFU email: jsa336@sfu.ca
Academic honesty statement: I hereby confirm that this is my own work and I have
not violated any of SFU’s Code of Academic Integrity and Good Conduct (S10.01).
Description: foo_recursive(30) is 2692537 times
*/

unsigned long foo_recursive(unsigned long n) {
    if (n == 0) {
        return 1;
    }
    else if (n == 1) {
        return 2;
    }
    else {
        return 2*foo_recursive(n-2) + foo_recursive(n-1) + n + 2;
    }
}



unsigned long foo_fast(unsigned long n) {
    unsigned long ntwo = 1; //foo(n-2)
    unsigned long none = 2; //foo(n-1)
    unsigned long result = 0;

    if (n == 0) {
        result = 1;
    }
    else if (n == 1) {
        result = 2;
    }
    else {
        for (unsigned long i = 2; i <= n; i++) {
            result = 2*ntwo + none + i + 2;
            ntwo = none;
            none = result;
        }
    }
    return result;
}