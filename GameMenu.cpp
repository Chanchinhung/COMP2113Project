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

//start menu (displayed at the start of the game)
void display_gm1() {
    cout << "Menu:" << endl;
    cout << "New Game (n) | Load Game (l) | Quit Game (q)" << endl;
    cout << "Your Choice: ";
}

//handling player choice in the start game menu
void game_menu_1(int &playermoney, int &housemoney, vector<RoundStat> &WLrec) { 
    char choice;
    display_gm1();
    cin >> choice;
	
    while (!((choice=='n') || (choice=='l') || (choice=='q'))) {	//handle wrong input
        cout << "Invalid input, try again." << endl;
        cout << "Your choice: ";
        cin >> choice;
    }
    if (choice=='n') {							// new game
        playermoney = 1000;
        housemoney = 1000;
        WLrec.clear();
        PlayRound(playermoney, housemoney, WLrec);
        game_menu_2(playermoney, housemoney, WLrec);
    }
    else if (choice=='l') {						// load game
        LoadGame(playermoney,housemoney,WLrec);
        game_menu_2(playermoney, housemoney, WLrec);
    }
    else if (choice=='q') {						// quit game
        display_exit();
        exit(1);
    }
}

//In-Game Menu (displayed in the middle of the game)
void display_gm2() {
    cout << "Options:" << endl;
    cout << "Continue (c) | New Game (n) | Save game (s) | Quit game (q) | Show Win/Loss History (h)" << endl;
    cout << "Your Choice: ";
}

//handling player choice in the second game menu
void game_menu_2(int &playermoney, int &housemoney, vector<RoundStat> &WLrec) {
    char choice;
    display_gm2();
    cin >> choice;
	
    while (!((choice=='c') || (choice=='n') || (choice=='s') || (choice=='q') || (choice == 'h'))) {
        cout << "Invalid input, try again." << endl;			// handle wrong input
        cout << "Your choice: ";
        cin >> choice;
    }
    if (choice=='c') {							// continue game
        if (playermoney<=0){
            cout << "You cannot continue, you don't have any money left." << endl;
        }
        else if (housemoney<=0){
            cout << "You cannot continue, you have already won!" << endl;
        }        
        else {
            PlayRound(playermoney, housemoney, WLrec);
        }
        game_menu_2(playermoney, housemoney, WLrec);
    }
    else if (choice=='n') {						// new game (reset the balance, clear previous win/lost statistics)
        cout << "Starting a new game will reset money and game history." << endl;
        cout << "Are you sure you would like to start a new game? (y/n)" << endl;
        cout << "Your choice: ";
        cin >> choice;
        while (!((choice=='y') || (choice=='n'))) {			// new game (handle wrong input)
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

        game_menu_2(playermoney, housemoney, WLrec);
    }
    else if (choice=='s') {						// save game
        SaveGame(playermoney,housemoney,WLrec);
        game_menu_2(playermoney, housemoney, WLrec);
    }
    else if (choice=='q') {						// quit game
        display_exit();
        exit(0);
    }
    else if (choice == 'h'){						// show gameplay statistics
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
