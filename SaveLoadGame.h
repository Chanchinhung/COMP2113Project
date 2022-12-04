//header file for SaveLoadGame.cpp
#include <vector>
#include "RoundStat.h"

#ifndef SaveLoadGame_H
#define SaveLoadGame_H

using namespace std;

void LoadGame (int &, int &housemoney, vector<RoundStat> &);
void SaveGame (int, int, vector<RoundStat>);

#endif
