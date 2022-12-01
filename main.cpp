#include <iostream>
#include <cstdlib>
#include <fstream>
#include "GameMenu.h"
using namespace std;

int main(){
    // global variable declaration
    int player_money = 1000, house_money = 1000;
    int arrsize=0;		// for "winstat" array sizing
    char *winstat;
    winstat = new char[arrsize];
    bool Won;

    // display start screen
    display_start();
	// display start menu
	game_menu_1();
	// display pause menu
	game_menu_2();

    // sizing the win-loss array
	char *temp; temp = new char[arrsize];
	for (int i=0; i<arrsize; i++) {
		temp[i] = winstat[i];
	}
	delete [] winstat;
	arrsize += 1;
	winstat = new char[arrsize];
	for (int i=0; i<arrsize-1; i++)
		winstat[i] = temp[i];
	delete [] temp;
	// append the win-loss history to the new array
	if (Won)
		winstat[arrsize-1] = 'W';
	else
		winstat[arrsize-1] = 'L';
	
	//display exit menu
	display_exit();
    return 0;
}
