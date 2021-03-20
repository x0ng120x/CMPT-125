#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "question3.h"

/*
CMPT 125 Assignment 3 Question 3
Author: Jaeui Song
Student ID: jsa336
SFU email: jsa336@sfu.ca
Academic honesty statement: I hereby confirm that this is my own work and I have
not violated any of SFU’s Code of Academic Integrity and Good Conduct (S10.01).
Description: Stack
*/

//creates a new stack following the struct defined
//a new stack has size = 0 and items = NULL
cStringStack* cStringStack_create() {
  cStringStack* stack = (cStringStack*)malloc(sizeof(cStringStack));
  if(stack != NULL) {
    stack->size = 0;
    stack->items = NULL;
  }
  return stack;
}

//pushes a given C string to the stack,
//you must copy the content instead of just the address
void cStringStack_push(cStringStack* csStack, char* cStr) {
  int i;
  char** temp = (char**)malloc(sizeof(char*)*(csStack->size+1));

  for(i=0;i<csStack->size;i++) {
    temp[i] = (char*)malloc(strlen(csStack->items[i]) + 1);
    strcpy(temp[i], csStack->items[i]);
  }
  if(csStack->items != NULL) {
    cStringStack_free(csStack);
  }
  csStack->items = temp;
  csStack->items[csStack->size] = (char*)malloc(strlen(cStr)+1);
  strcpy(csStack->items[csStack->size], cStr);
  csStack->size++;
}

//pops the C string from the stack,
//implemented by returning the address of the C string (copy)
//if the stack has 1 item, once popped it should become the same as a new stack,
//if the stack is empty, return NULL
char* cStringStack_pop(cStringStack* csStack) {
  int i;
  if(csStack->size > 0) {
    char* top = (char*)malloc(strlen(csStack->items[csStack->size-1])+1);
    strcpy(top, csStack->items[csStack->size-1]);
    if(csStack->size > 1) {
      char **temp = (char**)malloc(sizeof(char*)*(csStack->size-1));
      for(i=0;i<csStack->size-1;i++) {
        temp[i] = (char*)malloc(strlen(csStack->items[i])+1);
        strcpy(temp[i], csStack->items[i]);
      }
      cStringStack_free(csStack); // release the memory allocated to stack
      csStack->items = temp; // update items to point to temp
      csStack->size--; // decrement size by 1
    }
    else {
      cStringStack_free(csStack); // release the memory allocated to stack
      csStack->items = NULL; // set items to null
      csStack->size--; // decrement size by 1
    }
    return top;
  }
  return NULL;
}

//checks if the stack is empty
bool cStringStack_isEmpty(cStringStack* csStack) {
  return (csStack->size == 0);
}

//frees all the memory used by the stack to store the C strings
void cStringStack_free(cStringStack* csStack) {
  int i;
  for(i = 0; i < csStack->size; i++)
    free(csStack->items[i]); // release the memory allocated to ith element
  free(csStack->items); // release the memory allocated to items
}

//reverse the order of the C strings stored so the first added one
// will be popped first, and so on
void cStringStack_reverse(cStringStack* csStack) {
  if(csStack->size > 1) {
    int i, j;
    for(i=0, j=csStack->size-1;i<csStack->size/2;i++,j--) {
      char* temp = (char*)malloc(strlen(csStack->items[i])+1);
      strcpy(temp, csStack->items[i]);
      free(csStack->items[i]);
      csStack->items[i] = (char*)malloc(strlen(csStack->items[j])+1);
      strcpy(csStack->items[i], csStack->items[j]);
      free(csStack->items[j]);
      csStack->items[j] = temp;
    } 
  }
}

//creates a copy of a stack,
//each item has to be a C string with the same content but in different address
cStringStack* cStringStack_duplicate(cStringStack* csStack) {
  int i;
  cStringStack* stack = (cStringStack*)malloc(sizeof(cStringStack));
  if(stack != NULL) {
    stack->size = csStack->size;
    stack->items = (char**)malloc(sizeof(char*)*(csStack->size));
    for(i=0;i<csStack->size;i++) {
      stack->items[i] = (char*)malloc(strlen(csStack->items[i])+1);
      strcpy(stack->items[i], csStack->items[i]);
    }
  }
  return stack;
}