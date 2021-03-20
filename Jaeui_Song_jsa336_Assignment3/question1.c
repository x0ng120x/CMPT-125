#include <stdio.h>
#include "question1.h"
#define swap(a, b) do {char* temp; temp = a; a = b; b = temp;} while (0)

/*
CMPT 125 Assignment 3 Question 1
Author: Jaeui Song
Student ID: jsa336
SFU email: jsa336@sfu.ca
Academic honesty statement: I hereby confirm that this is my own work and I have
not violated any of SFU’s Code of Academic Integrity and Good Conduct (S10.01).
Description: quicksort_cstrings
*/

int partitionNL(char* arr[], int left, int right) {
  swap(arr[left], arr[right]);
  char* pivot = arr[left];
  int low = left + 1;
  int high = right;
 
  while (low <= high) {
    while (low <= right && strcmp(arr[low], pivot) < 0) {
      low++;
    }
    while (high >= (left+1) && strcmp(arr[high], pivot) >= 0) {
      high--;
    }

    if (low <= high) {
      swap(arr[low], arr[high]); 
    }
  } 
  swap(arr[left], arr[high]);
  return high;
}
 
void quickSortNL(char* arr[], int left, int right) {
  if (left <= right) {
    int pivot = partitionNL(arr, left, right); 
    quickSortNL(arr, left, pivot - 1); 
    quickSortNL(arr, pivot + 1, right); 
  }
}



int partitionYL(char* arr[], int left, int right) {
  swap(arr[left], arr[right]);
  char* pivot = arr[left];
  int low = left + 1;
  int high = right;
 
  while (low <= high) {
    while (low <= right && strlen(arr[low]) < strlen(pivot)) {
      low++;
    }
    while (high >= (left+1) && strlen(arr[high]) >= strlen(pivot)) {
      high--;
    }

    if (low <= high) {
      swap(arr[low], arr[high]); 
    }
  } 
  swap(arr[left], arr[high]);
  return high;
}
 
void quickSortYL(char* arr[], int left, int right) {
  if (left <= right) {
    int pivot = partitionYL(arr, left, right); 
    quickSortYL(arr, left, pivot - 1); 
    quickSortYL(arr, pivot + 1, right); 
  }
}

void quicksort_cstrings(char* stringArray[], int size, bool byLength) {
  if (byLength == false) {
    quickSortNL(stringArray, 0, size - 1);
  }
  else if (byLength == true) {
    quickSortYL(stringArray, 0, size - 1);
  }
}