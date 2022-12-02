#include <iostream>
#include <iomanip>
#include <vector>
#include "Card.h"
#include "RoundStat.h"
#include "PlayRound.h"
using namespace std;

int main (){
  int playermoney=1000, housemoney=1000; 
  vector<RoundStat> WLrec;
  PlayRound(playermoney, housemoney, WLrec);
  cout << playermoney << " " << housemoney << endl;
  return 0;
}
