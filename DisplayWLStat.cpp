#include <RoundStat.h>
#include <iostream>
#include <iomanip>
using namespace std;
int DisplayWLStat(vector<RoundStat> WLrec){
  int WinCount=0, LostCount=0, DrawCount=0, Betwon=0;
  float winrate, lostrate, drawrate;
  if (WLrec.size()==0){
    cout << "No record yet"; << endl;
    return 0;
  }
  cout << "W: Win, L: Lost, D:Draw" << endl;
  cout << setw(5) << "Round" << setw(7) << "Result" << setw(11) << "Amount Won" << endl;
  for (int i=0, i < WLrec.size(), i++){
    cout << setw(5) << i << setw(7) << WLrec[i].WL << setw(11) << WLrec[i].moneywon <<endl;
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
  winrate = (float) WinCount*100/WLrec.size;
  lostrate = (float) LostCount*100/WLrec.size;
  drawrate = (float) DrawCount*100/WLrec.size;
  cout << "Summary:" << endl;
  cout << "In a total of " <<  WLrec.size() << "rounds, you won" << WinCount << "rounds, " << "lost" << LostCount << "rounds, " << "drew" << DrawCount << "rounds" << endl;
  cout << fixed << setprecision(2);
  cout << "You win rate is " << winrate << "%, lost rate is " << lostrate << "%, draw rate is " << drawrate << "%" << endl
  cout << "Total amount won is $" << betwon << endl;
  return 0;
}
