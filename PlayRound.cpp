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

void split(int&, int&, int&, vector<RoundStat>&, vector<card>&, vector<card>&);

    vector<card> player_cards_1;
    vector<card> player_cards_2;
    player_cards_1.pushback(player_cards[0]);
    player_cards_2.pushback(player_cards[1]);

    //The following is for the player to process their first hand:
    cout << "You are now playing with your first hand."  << endl;
    cout << "Your first hand is : ";
    displaycards(player_cards_1);
    cout << "Value of your first hand: " << endl;
    displaytotalvalue(player_cards_1);
    PlayProcess(playermoney, housemoney, bet, houseprocessed, issamecard, WLrec, player_cards_1, house_cards);

    //The following is for the player to process their second hand:
    cout << "You are now playing with your second hand." << endl;
    cout << "Your second hand is : ";
    displaycards(player_cards_2);
    cout << "Value of your second hand: " << endl;
    displaytotalvalue(player_cards_2);
    PlayProcess(playermoney, housemoney, bet, houseprocessed, issamecard, WLrec, player_cards_1, house_cards);

    return 0;
}

bool samecard(vector<card>&hand) {
    //This bool function is to verify where the first 2 cards the player drawn are the same.
    char number1, number2; //Declare the variables to store the cards' numbers 
	
    //The following is to store the number and suits of the first 2 Cards in Player's hand
    number1 = hand[0].number;
    number2 = hand[1].number;
    //End of the variables storing
	
    if (number1==number2){
        return true;
    }
    return false;
}

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
            cout << "You cannot be bet $" << bet << ", you only have $" << playermoney << " remaining" << endl;
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

void PlayProcess (int &playermoney, int &housemoney, int &bet, bool &houseprocessed, vector<RoundStat> &WLrec, vector<card> &player_cards, vector<card> &house_cards){
	//This PlayProcess function is to handle the playing process in a round.
	
	//declare local variables
	char choice;
    	RoundStat temp;
	
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
	if (houseprocessed==false){
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
		houseprocessed==true; //To ensure that the house will not draw cards for one more time when the player choose to split.
    	else{ 
		//The commands in else{} is to display the house's cards without drawing the cards again. 
		cout << "House's hand:" << endl;
		displaycards(house_cards);
		cout << "House's hand value: " << endl;
        	displaytotalvalue(house_cards);
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
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

void PlayRound (int &playermoney, int &housemoney, vector<RoundStat> &WLrec){
    vector<card> player_cards;
    vector<card> house_cards;
    int bet;
    bool houseprocessed=false; //To check whether the house has already drawn cards in a round. If yes, the house will not be 
				//able to drawn extra cards when the player is playing with his/her split hand.
    bool issamecard=samecard(player_cards); //To check whether the first 2 cards of the Player are the same
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
    if (issamecard==true){
	    //If yes, the buyer can choose whether to split the 2 Cards.
	    char splitchoice;
	    cout<< "Seems you are holding 2 same cards. You can choose to split them apart and play each one like 2 separate hands instead of 1." <<endl;
	    cout<< "If you want to split them apart, you will place your original bet with one hand and place an additional bet on the newly created hand."<<endl;
	    cout<< "Would you like to split your cards? (Yes:'Y', No:'N') "<<endl;
	    cout<< "Your choice: ";
	    cin >> splitchoice;
	    if (splitchoice=='Y'){
	        //Choosing yes, the player wants to split their cards...
		cout << "You chose to split the 2 Cards"<<endl;
    		cout << "You now can play the BlackJack game with 2 separate hands. " << endl;
	        split (playermoney, housemoney, bet, houseprocessed, WLrec, player_cards, house_cards);
	    }
	    else {
		cout << "You chose not to split the 2 Cards"<<endl;    
	        PlayProcess (playermoney, housemoney, bet, houseprocessed, WLrec, player_cards, house_cards);
	    }
    }
    else {
        PlayProcess (playermoney, housemoney, bet, WLrec, player_cards, house_cards); //I just separated the PlayRound function to PlayRound and PlayProcess. 
	    //This is because we need to reuse the PlayProcess function in case the player want to split his cards (Which means he need to play 2 times in a round)
    }
    
    return;
}




