#include <iostream>
#include <iomanip>
#include <vector>
#include "Card.h"
#ifndef DisplayHand_H
#define DisplayHand_H
using namespace std;
void displaycards(vector<card> &);
bool has_ace(vector<card> &);
int total_value(vector<card> &);
void displaytotalvalue(vector<card> &);
bool bust(vector<card> &);
#endif
