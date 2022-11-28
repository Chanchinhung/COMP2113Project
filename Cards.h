#ifndef Cards_H //header file for data structure storing cards hit by house and player
#define Cards_H
struct Cards{
  int cardval; //The numeric value of the card
  char cardface; //The face of the card
  Cards *next; //The next node
};
#endif
