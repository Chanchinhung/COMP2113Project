//function for calculating the total value of the cards hit
#include <cards.h>
int CardValSum(Cards *head){
  Cards *current;
  int total=0, aces=0;
  current=head;
  while (current!=NULL){
    if (current->cardface='A')
      aces+=1;
    total+=current->cardval;
    current=current->next;
  }
  while ((total+10 < =21)&&(aces>0)){
    total+=10;
    aces-=1;
  }
  return total;
}
