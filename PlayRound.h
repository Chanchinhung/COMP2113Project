#include <iostream>
#include <iomanip>
#include <vector>
#include "Card.h"
#include "RoundStat.h"
#include "SplitCards.h"
#ifndef PlayRound_H
#define PlayRound_H
using namespace std;
void start_round(int &, int &);
void enter_bet(int &, int &);
void player_draw_display();
void house_draw_display();
void player_action(char &, bool &);
void PlayProcess (int &, int &, int &, bool &, bool &, vector<RoundStat> &, vector<card> &, vector<card> &);
void PlayRound (int &, int &, vector<RoundStat> &);
#endif
