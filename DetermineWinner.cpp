//function to determine winner of round
#include <vector>
#include "DetermineWinner.h"
#include "Card.h"
#include "DisplayHand.h"

/*
Function that takes the hands of the player and the house as input
and returns an integer that corresponds to the result of the round.
Return values: 1 (house wins), 2 (player wins), 3 (draw)
*/ 
int DetermineWinner(vector<card> &player, vector<card> &house) {
    int player_total = total_value(player); // calls function that returns the value of the player's hand
    int house_total = total_value(house); // calls function that returns the value of the house's hand
    if (player_total < house_total) { 
        return 1;
    }
    else if (player_total > house_total) { 
        return 2;
    }
    else if ((player.size()==2) && (house.size()!=2) && (player_total==21)){ // player draws a Blackjack and the house does not
        return 2;
    }
    else{
        return 3; //if ends in a draw
    }
}
