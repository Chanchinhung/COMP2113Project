//function for calculating the total value of the cards hit
#include <cards.h>
int CardValSum(Cards *head){
  Cards *current;
  int total=0;
  current=head;
  while (current!=NULL){
    total+=current->cardval;
    current=current->next;
  }
}
