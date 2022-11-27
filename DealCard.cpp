#include<Cards.h>
#include<cstlib>
using namespace std;
Cards* DealCard(Cards *head){
  Cards *hit = new Cards;
  hit->cardval=rand()%13 + 1;
  switch (hit->cardval){
    case 1:
      hit->cardface='A';
      break;
    case 2:
      hit->cardface='2';
      break;
    case 3:
      hit->cardface='3';
      break;
    case 4:
      hit->cardface='4';
      break;
    case 5:
      hit->cardface='5';
      break;
    case 6:
      hit->cardface='6';
      break;
    case 7:
      hit->cardface='7';
      break;  
    case 8:
      hit->cardface='8';
      break;
    case 9:
      hit->cardface='9';
      break;  
    case 10:
      hit->cardface='10';
      break;
    case 11:
      hit->cardface='J';
      hit->cardval=10;
      break;
    case 12:
      hit->cardface='Q';
      hit->cardval=10;
      break;
    case 13:
      hit->cardface='K';
      hit->cardval=10;
      break;  
  }
  hit->next=head;
  head=hit;
  return head;
}

