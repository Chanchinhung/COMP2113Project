//header file for GameMenu.cpp
#include <vector>
#include "RoundStat.h"

#ifndef GAMEMENU_H
#define GAMEMENU_H

using namespace std;

void display_start();
void display_gm1();
void game_menu_1(int &, int &, vector<RoundStat> &);
void display_gm2();
void game_menu_2(int &, int &, vector<RoundStat> &);
void display_exit();

#endif
