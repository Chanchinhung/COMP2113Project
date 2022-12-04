#include <iostream>
#include <vector>
#include "Card.h"
#include "DisplayHand.h"
using namespace std;

void displaycards(vector<card> &hand) { // displays the number and suit of every card in the input vector
    vector<card>::iterator itr;
    for (itr=hand.begin(); itr!=hand.end(); itr++) { //loop through the vector
        itr->display();
        cout << endl;
    }
}

bool has_ace(vector<card> &hand) { // returns a boolean depending on whether the input vector contains an ace
    vector<card>::iterator itr;
    for (itr=hand.begin(); itr!=hand.end(); itr++) { //loop through the vector
        if (itr->is_ace()) { //check whether the card is an ace
            return true;
        }
    }
    return false;
}

int total_value(vector<card> &hand) { // returns the total summed value of the cards in the input vector as an integer
    int total = 0;
    vector<card>::iterator itr;
    for (itr=hand.begin(); itr!=hand.end(); itr++) {
        total += itr->get_value();
    }
    /*
    If the hand contains an ace and total value +10 is still <=21 (not bust), 
    the function takes the ace's value as 11 instead of 1.
    */
    if (has_ace(hand)) { 
        if ((total+10)<=21) {
            return (total+10);
        }
    }
    return total;
}

void displaytotalvalue(vector<card> &hand) { // displays the total value of the cards in the input vector to the player
    int total = 0;
    vector<card>::iterator itr;
    for (itr=hand.begin(); itr!=hand.end(); itr++) {
        total += itr->get_value();
    }
    if (total>21) { // if the hand has bust
        cout << "Bust (" << total << ")" << endl;
    }
    else if (has_ace(hand)) {
        if ((total+10) > 21) {
            cout << total << endl;
        }
        else { // if the hand contains an ace that can have both 1 OR 11 as its value
            cout << total << " or " << total+10 << endl;
        }
    }
    else {
        cout << total << endl;
    }
}

bool bust(vector<card> &hand) { // returns a boolean depending on whether the input vector of cards has bust
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
