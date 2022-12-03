#include <iostream>
#include <string>
#include "Card.h"

using namespace std;

void card::initialise(int v, char n, char s) {
    value = v;
    number = n;
    suit = s;
}  

void card::display() {
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

bool card::is_ace() {
    return (number == 'A');
}

int card::get_value() {
    return value;
}

char card::get_number() {
    return number;
}

