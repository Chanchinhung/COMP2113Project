#include <iostream>
#include <vector>
#include "Card.h"
#include "DisplayHand.h"
using namespace std;

void displaycards(vector<card> &hand) { //function displaying the card faces of a hand
    vector<card>::iterator itr;
    for (itr=hand.begin(); itr!=hand.end(); itr++) {
        itr->display();
        cout << endl;
    }
}

bool has_ace(vector<card> &hand) {
    vector<card>::iterator itr;
    for (itr=hand.begin(); itr!=hand.end(); itr++) {
        if (itr->is_ace()) {
            return true;
        }
    }
    return false;
}

int total_value(vector<card> &hand) {
    int total = 0;
    vector<card>::iterator itr;
    for (itr=hand.begin(); itr!=hand.end(); itr++) {
        total += itr->get_value();
    }
    return total;
}

void displaytotalvalue(vector<card> &hand) {
    int total = total_value(hand);
    if (total>21) {
        cout << "Bust (" << total << ")";
    }
    else if (has_ace(hand)) {
        if ((total+10) > 21) {
            cout << total;
        }
        else {
            cout << total << " or " << total+10;
        }
    }
    else {
        cout << total;
    }
}

bool bust(vector<card> &hand) {
    int total = 0;
    vector<card>::iterator itr;
    for (itr=hand.begin(); itr!=hand.end(); itr++) {
        total += itr->get_value();
    }
    if (total>21) {
        return true;
    }
    return false;
}