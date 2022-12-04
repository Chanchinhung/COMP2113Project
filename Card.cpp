#include <iostream>
#include <string>
#include "Card.h"

using namespace std;

void card::initialise(int v, char n, char s) { // initialises a "card" object with initial values as inputs
    value = v;
    number = n;
    suit = s;
}  

void card::display() { // prints the suit and number of the card
    string s;
    if (suit=='H') {
        s = "Hearts";
    }
    else if (suit=='D') {
        s = "Diamonds";
    }
    else if (suit=='C') {
        s = "Clubs";
    }
    else if (suit=='S') {
        s = "Spades";
    }
    cout << number << " of " << s;
}

bool card::is_ace() { // returns true if the card is Ace, since Ace is special(can be 1 or 11)
    return (number == 'A');
}

int card::get_value() { // returns value of the card
    return value;
}

char card::get_number() { // return number of the Card
    return number;
}

