#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "GameMenu.h"
#include "RoundStat.h"
using namespace std;

int main(){
	// global variable declaration
	int playermoney = 1000, housemoney = 1000;
	vector<RoundStat> WLrec;
	
	// display start screen
	display_start();

	// display start menu
	game_menu_1(playermoney, housemoney, WLrec);
	// Note that the game loop is in GameMenu.cpp
	
	// display pause menu
	//game_menu_2(playermoney, housemoney, WLrec);
	
	//display exit menu
	//display_exit();
	return 0;
}
