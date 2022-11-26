//function to determine winner of round
#include<cards.h>
#include<CardValSum.h>
int DetermineWinner(Cards *playerhead, *househead){
  if (CardValSum(playerhead)==CardValSum(househead))
  return 3; //draw
  if ((CardValSum(playerhead)>=CardValSum(househead))&&((CardValSum(playerhead)<=21)))
  return 2; //player won
  if ((CardValSum(playerhead)<=CardValSum(househead))&&((CardValSum(househead)<=21)))
  return 1; //house won
}
