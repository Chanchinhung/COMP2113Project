#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include "Card.h"
#include "DealCard.h"
using namespace std;

void dealcard(vector<card> &hand) {
    card *hit_card = new card;
    int value;
    char number;
    char suit;
    int random_number;
    srand(time(NULL));
    random_number = (rand()%13) + 1;
    map<int, char> numbers = {{1, 'A'}, {2, '2'}, {3, '3'}, {4, '4'}, {5, '5'},
    {6, '6'}, {7, '7'}, {8, '8'}, {9, '9'}, {10, '10'}, {11, 'J'}, {12, 'Q'}, {13, 'K'}};
    number = numbers[random_number];
    map<char, int> number_to_value = {{'A', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5},
    {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'10', 10}, {'J', 10}, {'Q', 10}, {'K', 10}};
    value = number_to_value[number];
    random_number = (rand()%4) + 1;
    map<int, char> suits = {{1, 'H'}, {2, 'S'}, {3, 'C'}, {4, 'D'}};
    suit = suits[random_number];
    hit_card->initialise(value, number, suit);
    hand.push_back(*hit_card);
}


