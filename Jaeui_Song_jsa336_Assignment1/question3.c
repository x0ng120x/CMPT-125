#include <stdio.h>
//#include "question3.h"

/*
CMPT 125 Assignment 1 Question 3
Author: jaeui song
Student ID: jsa336
SFU email: jsa336@sfu.ca
Academic honesty statement: I hereby confirm that this is my own work and I have
not violated any of SFU’s Code of Academic Integrity and Good Conduct (S10.01).
Description: rowsubtraction
*/



//a helper function that prints the content of the 2D array
//assumes the array is either regular or empty with correct dimensions provided
void print2DArray(unsigned int rows, unsigned int cols, int matrix[rows][cols]) {
  if (rows==0 && cols==0) {
    printf("Empty array\n");
  }
  for (int r=0; r<rows; r++) {
    for (int c=0; c<cols-1; c++) {
      printf("%d ", matrix[r][c]);
    }
    printf("%d\n", matrix[r][cols-1]); //print the last item without a space
  }
}

void rowSubtraction(unsigned int rows, unsigned int columns, int matrix[rows][columns], unsigned int row1, unsigned int row2) {
  for(int x=0; x<columns; x++)  {
    matrix[row2][x] = matrix[row1][x] - matrix[row2][x];
  }
} 

int main() {
  int matrix1[3][4] = {{1, 2, 3, 2}, {2, 3, 4, 3}, {1, 1, 1, 1}};

  printf("Original matrix1:\n");
  print2DArray(3, 4, matrix1);

  printf("Result matrix1:\n");
  rowSubtraction(3, 4, matrix1, 0, 1);
  print2DArray(3, 4, matrix1);

  printf("Result matrix1:\n");
  rowSubtraction(3, 4, matrix1, 1, 2);
  print2DArray(3, 4, matrix1);

  printf("Result matrix1:\n");
  rowSubtraction(3, 4, matrix1, 2, 3);
  print2DArray(3, 4, matrix1);

  return 0;
}
