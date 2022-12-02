//This is a headerfile of SplitCards.cpp
#include <iostream>
#include <iomanip>
#include <vector>
#include "Card.h"
#include "RoundStat.h"

#ifndef SPLITCARDS_H
#define SPLITCARDS_H

using namespace std;
bool samecard( vector<card> & );
void split(int &, int &, int &, bool &, vector<RoundStat> &, vector<card> &, vector<card> &);

#endif
