#include <iostream>
#include <iomanip>
#include <vector>
#include "RoundStat.h"

using namespace std;

int DisplayWLStat(vector<RoundStat> WLrec){ //function that displays the Win Lose Statistics of player in this save
  int WinCount=0, LostCount=0, DrawCount=0, betwon=0;
  float winrate, lostrate, drawrate;
  if (WLrec.size()==0){ //if no rounds played yet, display the message "No record yet"
    cout << "No record yet" << endl;
    return 0;
  }
  cout << "W: Win, L: Lost, D: Draw" << endl; //Indicates the character meaning
  cout << "==========================================" << endl;
  cout << setw(5) << "Round" << setw(7) << "Result" << setw(11) << "Amount Won" << endl; //set the column headings
  for (int i=0; i < WLrec.size(); i++){ //display the statistics
    cout << setw(5) << i+1 << setw(7) << WLrec[i].WL << setw(11) << WLrec[i].moneywon <<endl;
    if (WLrec[i].WL=='W'){
      WinCount+=1;
    }
    else{
      if (WLrec[i].WL=='L'){
        LostCount+=1;
      }
      else DrawCount+=1;
    }
    betwon += WLrec[i].moneywon;
  }
  cout << "==========================================" << endl;
  winrate = (float) WinCount*100/WLrec.size(); //calculate win rates, lose rates, draw rates
  lostrate = (float) LostCount*100/WLrec.size();
  drawrate = (float) DrawCount*100/WLrec.size();
  cout << "Summary:" << endl;
  cout << "In a total of " <<  WLrec.size() << " rounds, you won " << WinCount << " rounds, lost " << LostCount << " rounds, and drew "  << DrawCount << " rounds." << endl; //Display total rounds won/lost/drew
  cout << fixed << setprecision(2);
  cout << "Your win rate is " << winrate << "%, loss rate is " << lostrate << "%, and draw rate is " << drawrate << "%" << endl; //display win/lose/draw rate
  cout << "Total amount won/lost is $" << betwon << endl; //Display total amount of money won
  cout << "==========================================" << endl;
  return 0;
}
