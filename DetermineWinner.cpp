//function to determine winner of round
#include <vector>
#include "DetermineWinner.h"
#include "Card.h"
#include "DisplayHand.h"

//function takes the hands of player and house by reference, and return an integer value of which depends on who won
int DetermineWinner(vector<card> &player, vector<card> &house) {
    // Return values: 1 (house wins), 2 (player wins), 3 (draw)
    int player_total = total_value(player); //call function to evaluate total value of hands of player and house respectively
    int house_total = total_value(house);
    if (player_total < house_total) { //if house won
        return 1;
    }
    else if (player_total > house_total) { //if player won
        return 2;
    }
    else if ((player.size()==2) && (house.size()!=2) && (player_total==21)){ //player have blackjack while house don't
        return 2;
    }
    else{
        return 3; //if ends in a draw
    }
}
