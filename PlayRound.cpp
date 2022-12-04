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
#include "SplitCards.h"

using namespace std;

void split(int& playermoney, int& housemoney, int& bet, bool& houseprocessed, bool& issamecard, vector<RoundStat>& WLrec, vector<card>& player_cards, vector<card>& house_cards) {

    vector<card> player_cards_1;
    vector<card> player_cards_2;
    player_cards_1.push_back(player_cards[0]);
    player_cards_2.push_back(player_cards[1]);

    // first hand is player
    cout << "==========" << endl;
    cout << "First hand" << endl;
    cout << "==========" << endl;
    cout << "Your first hand is: " << endl;
    displaycards(player_cards_1);
    cout << "Value of your first hand: " << endl;
    displaytotalvalue(player_cards_1);
    PlayProcess(playermoney, housemoney, bet, houseprocessed, issamecard, WLrec, player_cards_1, house_cards);

    // second hand is played
    house_cards.clear();
    cout << "===========" << endl;
    cout << "Second hand" << endl;
    cout << "===========" << endl;
    cout << "Your second hand is: " << endl;
    displaycards(player_cards_2);
    cout << "Value of your second hand: " << endl;
    displaytotalvalue(player_cards_2);
    PlayProcess(playermoney, housemoney, bet, houseprocessed, issamecard, WLrec, player_cards_2, house_cards);

}

bool samecard(vector<card>& hand) { //returns a boolean depending on whether the first 2 cards drawn by the player have the same number
    char number1, number2; // declares the variables to store the card numbers 
    // stores the number and suits of the first 2 cards in player's hand
    number1 = hand[0].get_number();
    number2 = hand[1].get_number();
    if (number1 == number2) {
        return true;
    }
    return false;
}

void start_round(int &playermoney, int &housemoney) { // displays the player's and house's money at the start of each round
    cout << "==============" << endl;
    cout << "Start of Round" << endl;
    cout << "==============" << endl;
    cout << "Your money: $" << playermoney << endl;
    cout << "House money: $" << housemoney << endl;
}

void enter_bet(int &bet, int &playermoney) { // takes player input as their bet at the start of each round
    cout << "Bet: $";
    cin >> bet;
    while ((bet<=0) || (bet>playermoney)) {
        if (bet<=0) { // ensures that a nonnegative amount is bet
            cout << "You have to bet at least $1" << endl;
            cout << "Bet: $";
            cin >> bet;
        }
        if (bet>playermoney) { // ensures that the player cannot bet more than their remaining money
            cout << "You cannot be bet $" << bet << ", you only have $" << playermoney << " remaining" << endl;
            cout << "Bet: $";
            cin >> bet;
        }
    }
}

void player_draw_display() { // displays text when the player draws a card
    cout << "=====================" << endl;
    cout << "You have drawn a card" << endl;
    cout << "=====================" << endl;
}

void house_draw_display() { // displays text when the player draws a card
    cout << "==========================" << endl;
    cout << "The house has drawn a card" << endl;
    cout << "==========================" << endl;
}

void player_action(char &choice) { // takes player input as their choice during the round
    cout << "Hit (h) | Stand (s) | Double Down (d) | Surrender (x)" << endl;
    cout << "Your choice: ";
    cin >> choice;
	while (!((choice=='h') || (choice=='s') || (choice=='d') || (choice=='x'))) {
		cout << "Invalid input, try again." << endl;
		cout << "Your choice: ";
		cin >> choice;
	}
}

void PlayProcess(int& playermoney, int& housemoney, int& bet, bool& houseprocessed, bool& issamecard, vector<RoundStat>& WLrec, vector<card>& player_cards, vector<card>& house_cards) {
    /*
    This PlayProcess function handles the process of play for every round.
    It contains the main game logic for our version of Blackjack.
    */
    char choice='a';
    RoundStat temp;
    while (!((bust(player_cards) || choice == 's'))) { // the player continues making choices until they bust or they stand
        player_action(choice);
        if (choice == 'x') { // the player chooses to surrender
            playermoney -= (bet+1) / 2;
            housemoney += (bet+1) / 2;
            temp.WL = 'L';
            temp.moneywon = -(bet+1) / 2;
            WLrec.push_back(temp);
            cout << "========================" << endl;
            cout << "You surrender this round" << endl;
            cout << "========================" << endl;
            cout << "You lose " << bet / 2 << endl;
            return;
        }
        else if (choice == 'd') { // the player chooses to double down
            if (playermoney<bet*2)
                cout << "You don't have enough money left to double down" << endl;
            else{
                bet *= 2;            
                dealcard(player_cards);
                player_draw_display();
                cout << "Your hand:" << endl;
                displaycards(player_cards);
                cout << "Current hand value: " << endl;
                displaytotalvalue(player_cards);
                choice='s';
            }	
        }
        else if (choice == 'h') { // the player chooses to hit
            dealcard(player_cards);
            player_draw_display();
            cout << "Your hand:" << endl;
            displaycards(player_cards);
            cout << "Current hand value: " << endl;
            displaytotalvalue(player_cards);
        }
        if (bust(player_cards)) {
            cout << "=========================" << endl;
            cout << "Bust! You lose this round" << endl;
            cout << "=========================" << endl;
            playermoney -= bet;
            housemoney += bet;
            temp.WL = 'L';
            temp.moneywon = -bet;
            WLrec.push_back(temp);
            return;
        }
    }
    if (houseprocessed == false) {
        cout << "House's turn!" << endl;
        while (total_value(house_cards) < 17) { // the house continues drawing cards until their total card value is >=17
            dealcard(house_cards);
            house_draw_display();
            cout << "House's hand:" << endl;
            displaycards(house_cards);
            cout << "House's hand value: " << endl;
            displaytotalvalue(house_cards);
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        houseprocessed == true; // ensures that the house will not draw cards an additional time when the player chooses to split
    }
    else {
        // displays the house's cards without drawing the cards again
        cout << "House's hand:" << endl;
        displaycards(house_cards);
        cout << "House's hand value: " << endl;
        displaytotalvalue(house_cards);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    if (bust(house_cards)) {
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
    /*
    The result of the round is determined by the DetermineWinner function contained in DetermineWinner.cpp.
    The function returns an integer depending on whether the player wins, the house wins, or the round ends in a draw.
    */
    switch (DetermineWinner(player_cards, house_cards)) {
    case 3:
        cout << "=========================================" << endl;
        cout << "Your hands are equal! You draw this round" << endl;
        cout << "=========================================" << endl;
        temp.WL = 'D';
        temp.moneywon = 0;
        WLrec.push_back(temp);
        return;
    case 1:
        cout << "===============================================" << endl;
        cout << "The house's hand is better! You lose this round" << endl;
        cout << "===============================================" << endl;
        playermoney -= bet;
        housemoney += bet;
        temp.WL = 'L';
        temp.moneywon = -bet;
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
}

/*
Function that initialises the start of every round.
Every round begins with the player drawing two cards and the house drawing one card.
If the player draws two cards with the same number, they have the option to split them via the split() function.
*/
void PlayRound(int& playermoney, int& housemoney, vector<RoundStat>& WLrec) { 
    vector<card> player_cards;
    vector<card> house_cards;
    int bet;
    bool houseprocessed = false; 
    /*
    Used to check whether the house has already drawn cards in a round. 
    If yes, the house will not be able to draw additional cards when the player is playing with their second split hand.
    */
    start_round(playermoney, housemoney);
    enter_bet(bet, playermoney);
    dealcard(house_cards);
    house_draw_display();
    cout << "House's hand:" << endl;
    displaycards(house_cards);
    cout << "House's hand value: " << endl;
    displaytotalvalue(house_cards);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    for (int i = 0; i < 2; i++) {
        dealcard(player_cards);
        player_draw_display();
        cout << "Your hand:" << endl;
        displaycards(player_cards);
        cout << "Current hand value: " << endl;
        displaytotalvalue(player_cards);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    bool issamecard = samecard(player_cards); //To check whether the first 2 cards of the Player are the same
    if (issamecard == true) {
        //If yes, the buyer can choose whether to split the 2 Cards.
        char splitchoice;
        cout << "You have two of the same card." << endl;
        cout << "Would you like to split your cards? (Yes:'y', No:'n') " << endl;
        cout << "Your choice: ";
        cin >> splitchoice;
        while (!((splitchoice=='y') || (splitchoice=='n'))) {
            cout << "Invalid input, try again." << endl;
            cout << "Your choice: ";
            cin >> splitchoice;
	}
        if (splitchoice == 'y') {
            //Choosing yes, the player wants to split their cards...
            cout << "You chose to split your Cards." << endl;
            cout << "You now can play BlackJack with 2 separate hands. " << endl;
            split(playermoney, housemoney, bet, houseprocessed, issamecard, WLrec, player_cards, house_cards);
        }
        else {
            cout << "You chose not to split your Cards" << endl;
            PlayProcess(playermoney, housemoney, bet, houseprocessed, issamecard, WLrec, player_cards, house_cards);
        }
    }
    else {
        PlayProcess(playermoney, housemoney, bet, houseprocessed, issamecard, WLrec, player_cards, house_cards); 
    }
    cout << "Your money: $" << playermoney << endl;
    cout << "House money: $" << housemoney << endl;
    return;
}

