#include <iostream>
#include <string>
#include "Card.h"

using namespace std;

void card::initialise(int v, char n, char s) { //initialise the structure Card storing information of a Card
    value = v;
    number = n;
    suit = s;
}  

void card::display() { //Display information of a Card
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

bool card::is_ace() { //return true if the card is Ace, since Ace is special(can be 1 or 11)
    return (number == 'A');
}

int card::get_value() { //return value of the card
    return value;
}

char card::get_number() { //return face of the Card
    return number;
}

