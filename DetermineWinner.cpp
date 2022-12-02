//function to determine winner of round
#include <vector>
#include "DetermineWinner.h"
#include "Card.h"
#include "DisplayHand.h"

int DetermineWinner(vector<card> &player, vector<card> &house) {
    // Return values: 1 (house wins), 2 (player wins), 3 (draw)
    int player_total = total_value(player);
    int house_total = total_value(house);
    if (has_ace(player)) {
        if ((player_total+10) > 21) {
            if (player_total < house_total) {
                return 1;
            }
            else if (player_total > house_total) {
                return 2;
            }
            else if (player_total == house_total) {
                return 3;
            }
        }
        else {
            if ((player_total+10) < house_total) {
                return 1;
            }
            else if ((player_total+10) > house_total) {
                return 2;
            }
            else if ((player_total+10) == house_total) {
                return 3;
            }
        }
    }
    else {
        if (player_total < house_total) {
            return 1;
        }
        else if (player_total > house_total) {
            return 2;
        }
        else if (player_total == house_total) {
            return 3;
        }
    }
}
