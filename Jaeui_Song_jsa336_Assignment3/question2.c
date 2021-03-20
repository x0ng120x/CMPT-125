#include <stdlib.h>
#include <stdio.h>
#include "question2.h"

/*
CMPT 125 Assignment 3 Question 2
Author: Jaeui Song
Student ID: jsa336
SFU email: jsa336@sfu.ca
Academic honesty statement: I hereby confirm that this is my own work and I have
not violated any of SFU’s Code of Academic Integrity and Good Conduct (S10.01).
Description: Deck
*/

void initializeDeck(Deck* theDeck, char* brandName) {
  theDeck->brand = brandName;
  for (int i = 0; i < 4; i++) {
    int j = i * 13;
    theDeck->cards[j].suit = i;
    theDeck->cards[j++].value = 'A';
    theDeck->cards[j].suit = i;
    theDeck->cards[j++].value = '2';
    theDeck->cards[j].suit = i;
    theDeck->cards[j++].value = '3';
    theDeck->cards[j].suit = i;
    theDeck->cards[j++].value = '4';
    theDeck->cards[j].suit = i;
    theDeck->cards[j++].value = '5';
    theDeck->cards[j].suit = i;
    theDeck->cards[j++].value = '6';
    theDeck->cards[j].suit = i;
    theDeck->cards[j++].value = '7';
    theDeck->cards[j].suit = i;
    theDeck->cards[j++].value = '8';
    theDeck->cards[j].suit = i;
    theDeck->cards[j++].value = '9';
    theDeck->cards[j].suit = i;
    theDeck->cards[j++].value = 'T';
    theDeck->cards[j].suit = i;
    theDeck->cards[j++].value = 'J';
    theDeck->cards[j].suit = i;
    theDeck->cards[j++].value = 'Q';
    theDeck->cards[j].suit = i;
    theDeck->cards[j++].value = 'K';
  }
}

void shuffleDeck(Deck* theDeck) {
  size_t i;
  for (i = 0; i < NUM_OF_CARDS_IN_DECK; i++) {
    size_t j = rand() % NUM_OF_CARDS_IN_DECK;
    Card t = theDeck->cards[j];
    theDeck->cards[j] = theDeck->cards[i];
    theDeck->cards[i] = t;
  }
}


void printDeck(const Deck* theDeck) {
  printf("Brand of Deck: %s\n", theDeck->brand);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 13; j++) {
      if (j != 0)
        printf(" ");
      
      if (theDeck->cards[i*13 + j].suit == 0)
        printf("%c\u2660", theDeck->cards[i*13 + j].value);
      else if(theDeck->cards[i*13 + j].suit == 1)
        printf("%c\u2661", theDeck->cards[i*13 + j].value);
      else if(theDeck->cards[i*13 + j].suit == 2)
        printf("%c\u2663", theDeck->cards[i*13 + j].value);
      else if(theDeck->cards[i*13 + j].suit == 3)
        printf("%c\u2662", theDeck->cards[i*13 + j].value);
    }
    printf("\n");
  }
}

/*
for (int j = 0; j < 13; j++) {
      theDeck->cards[i*13 + j].suit = i;
      if (j + 1 >= 2 && j + 1 <= 9)
        theDeck->cards[i*13 + j].value = j + 48;
      else if (j + 1 == 1) {
        theDeck->cards[i*13 + j].value = 'A';
      }
      else if (j + 1 == 10) {
        theDeck->cards[i*13 + j].value = 'T';
      }
      else if (j + 1 == 11) {
        theDeck->cards[i*13 + j].value = 'J';
      }
      else if (j + 1 == 12) {
        theDeck->cards[i*13 + j].value = 'Q';
      }
      else if (j + 1 == 13) {
        theDeck->cards[i*13 + j].value = 'K';
      }
    }
*/