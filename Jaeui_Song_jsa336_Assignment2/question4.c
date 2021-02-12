#include <stdio.h>
#include "question4.h"

void sortAscending(char* stringArray[], unsigned int size) {
    char* greatest;
    int greatIndex;
    char* temp;
    int j;
    int i;

    for (i = 0; i < size-1; i++) {
        greatest = stringArray[i];
        greatIndex = i;

        for (j = i+1; j < size; j++) {
            if (strcmp(greatest, stringArray[j]) > 0) {
                greatest = stringArray[j];
                greatIndex = j;
            }
        }

        temp = stringArray[i];
        stringArray[i] = stringArray[greatIndex];
        stringArray[greatIndex] = temp;
    }
}


char* getMedian(char* stringArray[], unsigned int size){
    int median = 0;

    sortAscending(stringArray, size);

    if (size % 2 == 0) {
        median = size / 2;
    }
    else if (size % 2 == 1) {
        median = (size-1) / 2;
    }

    return stringArray[median];
}