//function for calculating the total value of the cards hit
#include "Cards.h"
#include <cstddef>
int CardValSum(Cards *head){
  Cards *current;
  int total=0, aces=0;
  current=head;
  while (current!=NULL){
    if (current->cardface=="A")
      aces+=1; //count number of aces in hand
    total+=current->cardval; //add up value of cards in hand
    current=current->next; //head to next node
  }
  while ((total+10 < 21)&&(aces>0)){ //since value of Ace can be 1 or 11, the value of hand is maximised by considering Ace as 11 while keeping it <=21
    total+=10;
    aces-=1;
  }
  return total;
}
