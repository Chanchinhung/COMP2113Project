#include <iostream>
#include <vector>
#include "GameMenu.h"
#include "SaveLoadGame.h"
#include "RoundStat.h"
#include "PlayRound.h"
#include "DisplayWLStat.h"
using namespace std;


void display_start() { // displays start screen
    cout << "===============================" << endl;
    cout << "Welcome to the Blackjack Casino" << endl;
    cout << "===============================" << endl;
}


void display_gm1() { // displays start menu (shown at the start of the game)
    cout << "Menu:" << endl;
    cout << "New Game (n) | Load Game (l) | Quit Game (q)" << endl;
    cout << "Your Choice: ";
}

void game_menu_1(int &playermoney, int &housemoney, vector<RoundStat> &WLrec) {  // handles game start menu (initialises game)
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


void display_gm2() { // displays in-game menu (displayed after each round)
    cout << "Options:" << endl;
    cout << "Continue (c) | New Game (n) | Save game (s) | Quit game (q) | Show Win/Loss History (h)" << endl;
    cout << "Your Choice: ";
}

void game_menu_2(int &playermoney, int &housemoney, vector<RoundStat> &WLrec) { // handles game menu after each round
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

void display_exit() { // displays exit screen
    cout << "===================================================" << endl;
    cout << "Thank you for playing Blackjack. See you next time!" << endl;
    cout << "===================================================" << endl;
    cout << "By Sam, Ryan, Arnold, and Zay." << endl;
}
