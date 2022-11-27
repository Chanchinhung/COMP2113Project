#include<fstream>
#include<iostream>
#include<RoundStat.h>
using namespace std;
int loadWLstat(vector<RoundStat> WLrec){
  char filename[] = "WLstat.txt";
  char WL;
  int bet;
  RoundStat temp;
  ifstream fin;
  fin.open(filename);
  if (fin.fail()){
    cout << "Error in file opening, please contact the responsible personnel" << endl;
    exit(1);
  }
  while (fin >> temp.WL){
    fin >> temp.moneywon;
    WLrec.push_back(temp);
  }
  fin.close();
  return 0;
}
