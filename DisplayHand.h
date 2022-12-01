#include <iostream>
#include <iomanip>
#include "Card.h"
#ifndef DisplayHand_H
#define DisplayHand_H
void displaycards(vector<card>);
bool has_ace(vector<card>);
int total_value(vector<card>);
void displaytotalvalue(vector<card>);
bool bust(vector<card>);
#endif
