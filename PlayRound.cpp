#include <iostream>
#include <iomanip>
#include <vector>
#include <chrono>
#include <thread>
#include "Cards.h"
#include "RoundStat.h"
#include "CardValSum.h"
#include "DealCard.h"
#include "DisplayHand.h"
#include "DetermineWinner.h"
#include "PlayRound.h"
using namespace std;

int PlayRound (int &playermoney, int &housemoney, vector<RoundStat> &WLrec){
  Cards *playerhead=NULL;
  Cards *househead=NULL;
  int bet=0;
  char choice;
  RoundStat temp;
  cout << "Round start!" << endl;
  cout << "How much you would like to bet? You have $" << playermoney <<" left.";
  while ((bet<=0)||(bet>playermoney)){
    cout << "Please enter an positive integer from 1 to "<< playermoney << ": ";
    cin >> bet;
  }
  playerhead=DealCard(playerhead);
  std::this_thread::sleep_for(500ms);
  playerhead=DealCard(playerhead);
  cout << "Your hand: ";
  DisplayHand(playerhead);
  cout << "Current hand value: " << CardValSum(playerhead) << endl;
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



