#include<fstream>
#include<iostream>
#include<RoundStat.h>
using namespace std;
int SaveWLstat(vector<RoundStat> WLrec){
  char filename[]="WLstat.txt";
  ofstream fout;
  fout.open("WLstat.txt");
  if (fout.fail()){
    cout << "Error in file opening, please contact the responsible personnel" << endl;
    exit(1);
  }
  for (int i=0; i < WLrec.size(); i++){
    fout << WLrec[i].WL << " " << WLrec[i].moneywon << endl;
  }
  fout.close();
  return 0;
}
