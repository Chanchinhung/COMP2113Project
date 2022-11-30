#include <iostream>
#include <iomanip>
#include <Cards.h>
using namespace std;

int DisplayHand(Cards *head){
  Cards *current;
  current=head;
  while (current!=NULL){
    cout << current->cardface << " ";
    current=current->next;
  }
  cout << endl;
  return 0;
}
