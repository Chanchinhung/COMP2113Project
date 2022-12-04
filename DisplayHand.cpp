#include <iostream>
#include <vector>
#include "Card.h"
#include "DisplayHand.h"
using namespace std;

//function that takes a hand of cards(a vector) and display the card faces of card in hand
void displaycards(vector<card> &hand) {
    vector<card>::iterator itr;
    for (itr=hand.begin(); itr!=hand.end(); itr++) { //loop through the vector
        itr->display();
        cout << endl;
    }
}

//function that takes a hand of cards(a vector) and return boolean value of whether the hand contains Ace(s)
bool has_ace(vector<card> &hand) {
    vector<card>::iterator itr;
    for (itr=hand.begin(); itr!=hand.end(); itr++) { //loop through the vector
        if (itr->is_ace()) { //check whether the card is an ace
            return true;
        }
    }
    return false;
}

//function that takes a hand of card(a vector) and return total value of the hand
int total_value(vector<card> &hand) {
    int total = 0;
    vector<card>::iterator itr;
    for (itr=hand.begin(); itr!=hand.end(); itr++) {
        total += itr->get_value();
    }
    if (has_ace(hand)) { //if the hand has an ace and total value +10 is still <=21(not bust), the return the total value of the hand considering the ace as 11
        if ((total+10)<=21) {
            return (total+10);
        }
    }
    return total;
}

//function that takes the hand and display its total value on screen
void displaytotalvalue(vector<card> &hand) {
    int total = 0;
    vector<card>::iterator itr;
    for (itr=hand.begin(); itr!=hand.end(); itr++) {
        total += itr->get_value();
    }
    if (total>21) { //if a hand busted display that info on screen
        cout << "Bust (" << total << ")" << endl;
    }
    else if (has_ace(hand)) {
        if ((total+10) > 21) {
            cout << total << endl;
        }
        else {
            cout << total << " or " << total+10 << endl;
        }
    }
    else {
        cout << total << endl;
    }
}

bool bust(vector<card> &hand) { //function that takes a hand and see if it busted
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
