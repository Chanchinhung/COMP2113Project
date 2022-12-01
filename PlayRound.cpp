#include <iostream>
#include <iomanip>
#include <vector>
#include <chrono>
#include <thread>
#include "RoundStat.h"
#include "CardValSum.h"
#include "DealCard.h"
#include "DisplayHand.h"
#include "DetermineWinner.h"
#include "PlayRound.h"
#include "Card.h"
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
            cout << "You cannot be bet " << bet << ", you only have " << playermoney << endl;
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

int PlayRound (int &playermoney, int &housemoney, vector<RoundStat> &WLrec){
    vector<card> player_cards;
    vector<card> house_cards;
    int bet;
    char choice;
    RoundStat temp;
    start_round(playermoney, housemoney);
    enter_bet(bet, playermoney);
    
    dealcard(player_cards);
    player_draw_display();
    std::this_thread::sleep_for(500ms);
    dealcard(player_cards);
    player_draw_display();
    cout << "Your hand:" << endl;
    displaycards(player_cards);
    cout << "Current hand value: " << displaytotalvalue(player_cards) << endl;
    cout << "What will you do? (Please enter the corresponding character)" <<endl;
    cout << "H: Hit S:Stand D: Double Down X:Surrender" <<endl;
    while ((choice!='S')&&(choice!='X')&&(choice!='D')&&(CardValSum(playerhead)<21)){
    cout << "Your choice: ";
    cin >> choice;
    if (choice=='X'){
      playermoney-=bet/2;
      housemoney+=bet/2;
      temp.WL='L';
      temp.moneywon=-bet/2;
      WLrec.push_back(temp);
      cout << "You lose this round." << endl;
      return 0;
    }
    if (choice=='D'){
      bet*=2;
      playerhead=DealCard(playerhead);
      cout << "Your hand: ";
      DisplayHand(playerhead);
      cout << "Current hand value: " << CardValSum(playerhead) << endl;
    }
    if (choice=='H'){
      playerhead=DealCard(playerhead);
      cout << "Your hand: ";
      DisplayHand(playerhead);
      cout << "Current hand value: " << CardValSum(playerhead) << endl;
    }
  }
  if (CardValSum(playerhead)>21){
    cout << "Busted! You lose this round" << endl;
    playermoney-=bet;
    housemoney+=bet;
    temp.WL='L';
    temp.moneywon=-bet;
    WLrec.push_back(temp);
    return 0;
  }
  cout << "House's turn!" << endl; 
  while (CardValSum(househead)<17){
    househead=DealCard(househead);
    cout << "House hand: ";
    DisplayHand(househead);
    cout << "Current hand value: " << CardValSum(househead) << endl;
    std::this_thread::sleep_for(500ms);
  }
  if (CardValSum(househead)>21){
    cout << "House busted! You win this round!" << endl;
    playermoney+=bet;
    housemoney-=bet;
    temp.WL='W';
    temp.moneywon=bet;
    WLrec.push_back(temp);
    return 0;
  }
  switch (DetermineWinner(playerhead, househead)){
    case 3:
    cout << "You hand is as good as house's. You draw this round." << endl;
    temp.WL='D';
    temp.moneywon=0;
    WLrec.push_back(temp);
    return 0;
    case 1:
    cout << "House has better hand. You lost this round." << endl;
    playermoney-=bet;
    housemoney+=bet;
    temp.WL='L';
    temp.moneywon=-bet;
    WLrec.push_back(temp);
    return 0;
    case 2:
    cout << "You have better hand. You win this round!" << endl;
    playermoney+=bet;
    housemoney-=bet;
    temp.WL='W';
    temp.moneywon=bet;
    WLrec.push_back(temp);
    return 0;
  }
  return 0;
}



