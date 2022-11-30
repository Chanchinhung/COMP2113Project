#include <iostream>
#include <iomanip>
#include <Cards.h>
#include <RoundStat.h>
using namespace std;

int PlayRound (int &playermoney, &housemoney; &vector<RoundStat> WLrec){
  Cards *playerhead=NULL;
  Cards *househead=NULL;
  int bet=0;
  char choice;
  RoundStat temp;
  cout << "Round start!" << endl;
  cout << "How much you would like to bet? You have $" << playermoney <<"left.
  cout << "Please enter an positive integer from 1 to "<< playermoney << ": ";
  while ((bet==0)||(bet>playermoney)){
    cout << "Please enter an positive integer from 1 to "<< playermoney << ": ";
    cin >> bet;
  }
  playerhead=DealCard(playerhead);
  playerhead=DealCard(playerhead);
  cout << "Your hand: ";
  Displayhand(playerhead);
  cout << "Current hand value: " << CardValSum(playerhead);
  cout << "What will you do? (Please enter the corresponding character)" <<endl;
  cout << "H: Hit S:Stand D: Double Down X:Surrender" <<endl;
  while (((choice!='S')||(choice!='X')||choice!='D'))&&(CardValSum(playerhead)<21)){
    cout << "Your choice: " <<endl;
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
      Displayhand(playerhead);
      cout << "Current hand value: " << CardValSum(playerhead);
    }
    if (choice=='H'){
      playerhead=DealCard(playerhead);
      cout << "Your hand: ";
      Displayhand(playerhead);
      cout << "Current hand value: " << CardValSum(playerhead);
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
  while (CardValSum<17){
    DealCard(househead);
    cout << "House hand: ";
    Displayhand(househead);
    cout << "Current hand value: " << CardValSum(playerhead);
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
  if (CardValSum(househead)=CardValSum(playerhead)){
    cout << "You hand is as good as house's. You draw this round." << endl;
    temp.WL='D';
    temp.moneywon=0;
    WLrec.push_back(temp);
    return 0;
  }
  if (CardValSum(househead)>CardValSum(playerhead){
    cout << "House has better hand. You lost this round." << endl;
    playermoney-=bet;
    housemoney+=bet;
    temp.WL='L';
    temp.moneywon=-bet;
    WLrec.push_back(temp);
    return 0;
  }
  if (CardValSum(househead)<CardValSum(playerhead){
    cout << "You have better hand. You win this round!" << endl;
    playermoney+=bet;
    housemoney-=bet;
    temp.WL='W';
    temp.moneywon=bet;
    WLrec.push_back(temp);
    return 0;
  }
}



