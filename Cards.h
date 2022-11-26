#ifndef Cards_H //header file for data structure storing cards hit by house and player
#define Cards_H
struct Cards{
  int cardval;
  char cardface;
  Cards *next;
};
#endif
