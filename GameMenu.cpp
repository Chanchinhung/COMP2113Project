#include <iostream>
#include "GameMenu.h"
#include "SaveLoadGame.h"
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
void game_menu_1() { 
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
		exit(1);
	}
	else if (choice=='l') {
		//implement load game
		LoadGame(playermoney,housemoney,WLrec);
		exit(1);
	}
	else if (choice=='q') {
        //implement quit game
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
	cout << "Your Choice: ";

}

//pause menu
void game_menu_2() {
	char choice;
	display_gm2();
	cin >> choice;
	while (!((choice=='c') || (choice=='n') || (choice=='s') || (choice=='q'))) {
		cout << "Invalid input, try again." << endl;
		cout << "Your choice: ";
		cin >> choice;
	}
	if (choice=='c') {
		//implement continue game
		exit(1);
	}
	else if (choice=='n') {
		//implement new game
		exit(1);
	}
	else if (choice=='s') {
		//implement save game
		SaveGame(playermoney,housemoney,WLrec);
		exit(1);
	}
	else if (choice=='q') {
		//implement quit game
		display_exit();
		exit(1);
	}
}

//exit screen
void display_exit() {
	cout << "===================================================" << endl;
	cout << "Thank you for playing Blackjack. See you next time!" << endl;
	cout << "===================================================" << endl;
	cout << "By Sam, Ryan, Arnold, and Zay." << endl;
}
