#include <iostream>
#include <fstream>
#include <vector>
#include "RoundStat.h"
using namespace std;

// The game will be saved in a file called "game_save.txt"

// Function to Load the Game (Load the player/house money; Load the WL stat)
void LoadGame (int &playermoney, int &housemoney, vector<RoundStat> &WLrec){
	// read the file
	char filename[] = "game_save.txt";
	ifstream fin;
	fin.open(filename);
	if (fin.fail()){
		cout << "Error in loading the game status." << endl;
		exit(1);
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
	cout << "You:    $" << playermoney << endl;
	cout << "Dealer: $" << housemoney << endl;
}

// Function to Save the Game (save the player/house money; save the WL stat)
void SaveGame (int playermoney, int housemoney, vector<RoundStat> WLrec){
	// Create the File
	char filename[] = "game_save.txt";
	ofstream fout;
	fout.open(filename);
	if (fout.fail()){
		cout << "Error in saving the game status." << endl;
		exit(1);
	}

	// Write the playermoney and Housemoney amount into the file
	fout << playermoney << " " << housemoney << endl;

	// Save the W-L record to the file
	for (int i = 0; i < WLrec.size(); i++){
		fout << WLrec[i].WL << " " << WLrec[i].moneywon << endl;
	}

	fout.close();
	
	// Screen output
	cout << "The Game is saved successfully!" << endl;
}


// main program for testing this module

// int main(){ 
// 	int playermoney;
// 	int housemoney;
// 	vector<RoundStat> WLrec;
// 	// RoundStat temp;
// 	// temp.WL = 'D';
// 	// temp.moneywon = 300;
// 	// WLrec.push_back(temp);
// 	// WLrec.push_back(temp);
// 	// SaveGame(playermoney,housemoney,WLrec);
// 	LoadGame(playermoney,housemoney,WLrec);
// 	cout << playermoney << " " << housemoney<< endl;
// 	for (int i = 0; i < WLrec.size(); i++){
// 		cout << WLrec[i].WL << " " << WLrec[i].moneywon << endl;
// 	}
// 	return 0;
// }
