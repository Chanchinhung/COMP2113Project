#include <iostream>
#include <vector>
#include "GameMenu.h"
#include "SaveLoadGame.h"
#include "RoundStat.h"
#include "PlayRound.h"
#include "DisplayWLStat.h"
using namespace std;

//start screen
void display_start() {
	cout << "===============================" << endl;
	cout << "Welcome to the Blackjack Casino" << endl;
	cout << "===============================" << endl;
}

void display_gm1() {
	cout << "Menu:" << endl;
	cout << "New Game (n)" << endl;
	cout << "Load Game (l)" << endl;
	cout << "Quit Game (q)" << endl;
	cout << "Your Choice: ";
}

//start menu
void game_menu_1(int &playermoney, int &housemoney, vector<RoundStat> &WLrec) { 
	char choice;
	display_gm1();
	cin >> choice;
	while (!((choice=='n') || (choice=='l') || (choice=='q'))) {
		cout << "Invalid input, try again." << endl;
		cout << "Your choice: ";
		cin >> choice;
	}
	if (choice=='n') {
		//implement new game
		playermoney = 1000;
		housemoney = 1000;
		WLrec.clear();
		PlayRound(playermoney, housemoney, WLrec);
		game_menu_2(playermoney, housemoney, WLrec);
	}
	else if (choice=='l') {
		LoadGame(playermoney,housemoney,WLrec);
		game_menu_2(playermoney, housemoney, WLrec);
	}
	else if (choice=='q') {
		display_exit();
		exit(1);
    }
}

void display_gm2() {
	cout << "Options:" << endl;
	cout << "Continue (c)" << endl;
	cout << "New Game (n)" << endl;
	cout << "Save game (s)" << endl;
	cout << "Quit game (q)" << endl;
	cout << "Win/Loss History (h)" << endl;
	cout << "Your Choice: ";
}

//pause menu
void game_menu_2(int &playermoney, int &housemoney, vector<RoundStat> &WLrec) {
	char choice;
	display_gm2();
	cin >> choice;
	while (!((choice=='c') || (choice=='n') || (choice=='s') || (choice=='q') || (choice == 'h'))) {
		cout << "Invalid input, try again." << endl;
		cout << "Your choice: ";
		cin >> choice;
	}
	if (choice=='c') {
		//implement continue game
		PlayRound(playermoney, housemoney, WLrec);
		game_menu_2(playermoney, housemoney, WLrec);
	}
	else if (choice=='n') {
		//implement new game
		cout << "Starting a new game will reset money and game history." << endl;
		cout << "Are you sure you would like to start a new game? (y/n)" << endl;
		cout << "Your choice: ";
		cin >> choice;
		while (!((choice=='y') || (choice=='n'))) {
			cout << "Invalid input, try again." << endl;
			cout << "Your choice: ";
			cin >> choice;
		}
		if (choice == 'y'){
			cout << "========" << endl;
			cout << "New game" << endl;
			cout << "========" << endl;
			playermoney = 1000;
			housemoney = 1000;
			WLrec.clear();
			PlayRound(playermoney, housemoney, WLrec);
		}
		else {
			game_menu_2(playermoney, housemoney, WLrec);
		}

		game_menu_2(playermoney, housemoney, WLrec);
	}
	else if (choice=='s') {
		SaveGame(playermoney,housemoney,WLrec);
		game_menu_2(playermoney, housemoney, WLrec);
	}
	else if (choice=='q') {
		display_exit();
		exit(0);
	}
	else if (choice == 'h'){
		DisplayWLStat(WLrec);
		game_menu_2(playermoney, housemoney, WLrec);
	}
}

//exit screen
void display_exit() {
	cout << "===================================================" << endl;
	cout << "Thank you for playing Blackjack. See you next time!" << endl;
	cout << "===================================================" << endl;
	cout << "By Sam, Ryan, Arnold, and Zay." << endl;
}
