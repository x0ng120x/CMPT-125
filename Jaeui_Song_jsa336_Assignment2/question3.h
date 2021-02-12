#ifndef A2_Q3_H
#define A2_Q3_H
#define NUM_OF_CARDS_IN_DECK 52

/*
CMPT 125 Assignment 2 Question 3
Author: Jaeui Song
Student ID: jsa336
SFU email: jsa336@sfu.ca
Academic honesty statement: I hereby confirm that this is my own work and I have
not violated any of SFU’s Code of Academic Integrity and Good Conduct (S10.01).
Description: enum, struct
*/

typedef enum {Spades, Hearts, Clubs, Diamonds} Suit;

typedef struct {
    Suit suit;
    char value;
} Card;

typedef struct {
    char* brand;
    Card cards[NUM_OF_CARDS_IN_DECK];
} Deck;

#endif
