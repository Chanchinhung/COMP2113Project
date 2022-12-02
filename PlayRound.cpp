#include <iostream>
#include <iomanip>
#include <vector>
#include <chrono>
#include <thread>
#include "Card.h"
#include "RoundStat.h"
#include "DealCard.h"
#include "DisplayHand.h"
#include "DetermineWinner.h"
#include "PlayRound.h"

using namespace std;

void start_round(int &playermoney, int &housemoney) {
    cout << "==============" << endl;
    cout << "Start of Round" << endl;
    cout << "==============" << endl;
    cout << "Your money: " << playermoney << endl;
    cout << "House money: " << housemoney << endl;
}

void enter_bet(int &bet, int &playermoney) {
    cout << "Bet: $";
    cin >> bet;
    while ((bet<=0) || (bet>playermoney)) {
        if (bet<=0) {
            cout << "You have to bet at least $1" << endl;
            cout << "Bet: $";
            cin >> bet;
        }
        if (bet>playermoney) {
            cout << "You cannot be bet $" << bet << ", you only have $" << playermoney << endl;
            cout << "Bet: $";
            cin >> bet;
        }
    }
}

void player_draw_display() {
    cout << "=====================" << endl;
    cout << "You have drawn a card" << endl;
    cout << "=====================" << endl;
}

void house_draw_display() {
    cout << "==========================" << endl;
    cout << "The house has drawn a card" << endl;
    cout << "==========================" << endl;
}

void player_action(char &choice) {
    cout << "Hit (h) | Stand (s) | Double Down (d) | Surrender (x) | Options (o)" << endl;
    cout << "Your choice: ";
    cin >> choice;
	while (!((choice=='h') || (choice=='s') || (choice=='d') || (choice=='x') || (choice=='o'))) {
		cout << "Invalid input, try again." << endl;
		cout << "Your choice: ";
		cin >> choice;
	}
}

void PlayRound (int &playermoney, int &housemoney, vector<RoundStat> &WLrec){
    vector<card> player_cards;
    vector<card> house_cards;
    int bet;
    char choice;
    RoundStat temp;
    start_round(playermoney, housemoney);
    enter_bet(bet, playermoney);
    for (int i=0; i<2; i++) {
        dealcard(player_cards);
        player_draw_display();
        cout << "Your hand:" << endl;
        displaycards(player_cards);
        cout << "Current hand value: " << endl;
        displaytotalvalue(player_cards);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    do {
        player_action(choice);
        if (choice=='x') {
            playermoney -= bet/2;
            housemoney += bet/2;
            temp.WL = 'L';
            temp.moneywon =- bet/2;
            WLrec.push_back(temp);
            cout << "========================" << endl;
            cout << "You surrender this round" << endl;
            cout << "========================" << endl;
            cout << "You lose " << bet/2;
            return;
        }
        else if (choice=='d') {
            bet *= 2;
            dealcard(player_cards);
            player_draw_display();
            cout << "Your hand:" << endl;
            displaycards(player_cards);
            cout << "Current hand value: " << endl;
            displaytotalvalue(player_cards);
            break;
        }
        else if (choice=='h') {
            dealcard(player_cards);
            player_draw_display();
            cout << "Your hand:" << endl;
            displaycards(player_cards);
            cout << "Current hand value: " << endl;
            displaytotalvalue(player_cards);
        }
    } while (!((bust(player_cards) || choice=='s')));
    if (bust(player_cards)) {
        cout << "=========================" << endl;
        cout << "Bust! You lose this round" << endl;
        cout << "=========================" << endl;
        playermoney -= bet;
        housemoney += bet;
        temp.WL = 'L';
        temp.moneywon =- bet;
        WLrec.push_back(temp);
        return;
    }
    cout << "House's turn!" << endl; 
    while (total_value(house_cards)<17){
        dealcard(house_cards);
        house_draw_display();
        cout << "House's hand:" << endl;
        displaycards(house_cards);
        cout << "House's hand value: " << endl;
        displaytotalvalue(house_cards);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    if (bust(house_cards)){
        cout << "======================================" << endl;
        cout << "The house has bust! You win this round" << endl;
        cout << "======================================" << endl;
        playermoney += bet;
        housemoney -= bet;
        temp.WL = 'W';
        temp.moneywon = bet;
        WLrec.push_back(temp);
        return;
    }
    switch (DetermineWinner(player_cards, house_cards)){
        case 3:
            cout << "=========================================" << endl;
            cout << "Your hands are equal! You draw this round" << endl;
            cout << "=========================================" << endl;
            temp.WL='D';
            temp.moneywon=0;
            WLrec.push_back(temp);
            return;
        case 1:
            cout << "===============================================" << endl;
            cout << "The house's hand is better! You lose this round" << endl;
            cout << "===============================================" << endl;
            playermoney -= bet;
            housemoney += bet;
            temp.WL = 'L';
            temp.moneywon =- bet;
            WLrec.push_back(temp);
            return;
        case 2:
            cout << "=======================================" << endl;
            cout << "Your hand is better! You win this round" << endl;
            cout << "=======================================" << endl;
            playermoney += bet;
            housemoney -= bet;
            temp.WL = 'W';
            temp.moneywon = bet;
            WLrec.push_back(temp);
            return;
    }
    return;
}




