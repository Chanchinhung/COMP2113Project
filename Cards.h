#ifndef CARDS_H //header file for data structure storing cards hit by house and player
#define CARDS_H
#include <string>
using namespace std;
struct Cards{ //linked list
  int cardval; //The numeric value of the card
  string cardface; //The face of the card
  Cards *next; //pointer to the next node
};
#endif
