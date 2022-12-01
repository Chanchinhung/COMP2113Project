#include <iostream>
#include <iomanip>
#include "Cards.h"
using namespace std;

int DisplayHand(Cards *head){ //function displaying the card faces of a hand
  Cards *current;
  current=head;
  while (current!=NULL){
    cout << current->cardface << " ";
    current=current->next;
  }
  cout << endl;
  return 0;
}
