#include <iostream>
#include <iomanip>
#include <vector>
#include "RoundStat.h"

using namespace std;

int DisplayWLStat(vector<RoundStat> WLrec){ // displays the win-loss statistics of the player within the current save
    int WinCount=0, LostCount=0, DrawCount=0, betwon=0;
    float winrate, lostrate, drawrate;
    if (WLrec.size()==0){ // if no rounds have been played
        cout << "No record yet" << endl;
        return 0;
    }
    // displaya a table listing the round-by-round win-loss history and details for every round
    cout << "W: Win, L: Lost, D: Draw" << endl; 
    cout << "==========================================" << endl;
    cout << setw(5) << "Round" << setw(7) << "Result" << setw(11) << "Amount Won" << endl; 
    for (int i=0; i < WLrec.size(); i++){ 
        cout << setw(5) << i+1 << setw(7) << WLrec[i].WL << setw(11) << WLrec[i].moneywon <<endl;
        if (WLrec[i].WL=='W'){ // count total number of win/loss/draw
            WinCount+=1;
        }
        else{
            if (WLrec[i].WL=='L'){
                LostCount+=1;
            }
            else DrawCount+=1;
        }
        betwon += WLrec[i].moneywon;  // calculate the net total amount that the player won
    }
    // displays overall save file statistics
    cout << "==========================================" << endl;
    winrate = (float) WinCount*100/WLrec.size(); //calculate win rate
    lostrate = (float) LostCount*100/WLrec.size(); //calculate loss rate
    drawrate = (float) DrawCount*100/WLrec.size(); //calculate draw rate
    cout << "Summary:" << endl;
    cout << "In a total of " <<  WLrec.size() << " rounds, you won " << WinCount << " rounds, lost " << LostCount << " rounds, and drew "  << DrawCount << " rounds." << endl;
    cout << fixed << setprecision(2);
    cout << "Your win rate is " << winrate << "%, loss rate is " << lostrate << "%, and draw rate is " << drawrate << "%" << endl;
    cout << "Total amount won/lost is $" << betwon << endl; //Display total amount of money won
    cout << "==========================================" << endl;
    return 0;
}
