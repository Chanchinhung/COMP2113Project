#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "GameMenu.h"
#include "RoundStat.h"
using namespace std;

int main(){
    // global variable declaration
    int playermoney = 1000, housemoney = 1000;
    vector<RoundStat> WLrec;
    // display start screen
    display_start();
    // runs game start menu (initialises game)
    game_menu_1(playermoney, housemoney, WLrec);
    // Note: game loop is contained in GameMenu.cpp
    return 0;
}
