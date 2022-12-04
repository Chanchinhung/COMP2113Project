#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include "Card.h"
#include "DealCard.h"
using namespace std;

void random_time() { // generates a random seed for rand() using system time
    srand(time(NULL));
}

/*
Function that takes a vector of cards as input,
appends a new randomised card to the end of the vector,
and returns the same vector including the additional card.
*/ 
void dealcard(vector<card> &hand) {
    card *hit_card = new card; // a new card object created in dynamic memory
    int value;
    char number;
    char suit;
    int random_number;
    random_time();
    random_number = (rand()%13) + 1;
    //a map that help convert the random_number to number(face of card)
    map<int, char> numbers = {{1, 'A'}, {2, '2'}, {3, '3'}, {4, '4'}, {5, '5'},
    {6, '6'}, {7, '7'}, {8, '8'}, {9, '9'}, {10, 'T'}, {11, 'J'}, {12, 'Q'}, {13, 'K'}};
    number = numbers[random_number];
    //map that help convert number to value of the card, T stands for the card '10'
    map<char, int> number_to_value = {{'A', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5},
    {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'T', 10}, {'J', 10}, {'Q', 10}, {'K', 10}};
    value = number_to_value[number];
    random_number = (rand()%4) + 1;
    //a map that help convert the random_number to suit of card
    map<int, char> suits = {{1, 'H'}, {2, 'S'}, {3, 'C'}, {4, 'D'}};
    suit = suits[random_number];
    //initialise hit_card with the random values generated above
    hit_card->initialise(value, number, suit);
    //push hit_card to the vector hand, so a card is dealt to hand of player/house
    hand.push_back(*hit_card);
}


