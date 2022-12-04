#include <iostream>
#include <fstream>
#include <vector>
#include "RoundStat.h"
using namespace std;

// Every game state is saved in a file named "game_save.txt"

// Function to Load the Game (Load the player/house money; Load the WL stat)
void LoadGame (int &playermoney, int &housemoney, vector<RoundStat> &WLrec){
    // read the file
    char filename[] = "game_save.txt";
    ifstream fin;
    fin.open(filename);
	
    // if fail opening the file then exit the function
    if (fin.fail()){
        cout << "Error in loading the game status." << endl;
        return;
    }

    // read the player and house money balance from the file
    fin >> playermoney;
    fin >> housemoney;

    // load the W-L record from the file
    RoundStat temp;
    while (fin >> temp.WL){
        fin >> temp.moneywon;
        WLrec.push_back(temp);
    }

    fin.close();
	
    // Screen output money balance
    cout << "Game loaded successfully." <<endl;
    cout << "Bank Balance:" << endl;
    cout << "Your money:    $" << playermoney << endl;
    cout << "House money: $" << housemoney << endl;
}

// Function to Save the Game (save the player/house money; save the WL stat)
void SaveGame (int playermoney, int housemoney, vector<RoundStat> WLrec){
    // Create the File
    char filename[] = "game_save.txt";
    ofstream fout;
    fout.open(filename);

    // if fail saving the file then exit the function
    if (fout.fail()){
        cout << "Error in saving the game status." << endl;
        return;
    }

    // Write the playermoney and Housemoney amount into the file
    fout << playermoney << " " << housemoney << endl;

    // Save the W-L record to the file
    for (int i = 0; i < WLrec.size(); i++){
        fout << WLrec[i].WL << " " << WLrec[i].moneywon << endl;
    }

    fout.close();

    // Screen output
    cout << "The game has successfully been saved!" << endl;
}
