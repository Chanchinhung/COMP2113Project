#include <iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

class BlackJack{
//You may refer to Module 7 Lecture Notes P.42 on how to use a Class
public:
    //Please add your functions here:
    void initialdeck();
    

private:
    //Please add the member variables here:
    int cardvalue[52]; //The Value of the card in BlackJack Game
    string cardname[52]; //The Name of the Card 
    int A_choice; //The choice of the value of Ace (1 or 11)
    int P_Cards[5]; //The cards of the Player (P:Player), this will store the integers "i" returned by the randomnumber function
    int D_Cards[5]; //The cards of the Dealer (D:Dealer), this will store the integers "i" returned by the randomnumber function
    int P_noofcards; //The number of cards of the Player (P:Player)
    int D_noofcards; //The number of cards of the Dealer (D:Dealer)
}

//Hello Guys I'm Sam! I'm going to make the Deck information part and assign random cards to the player and the dealer...
//Please just make sure we are not doing the same thing! Thanks!

void BlackJack::initialdeck(){
    //This program is to initialise the arrays of CardValue and CardName
    //We can then use cardvalue[i] and cardname[i] to access the value and the name of card i, 
    //    where i is an integer returned by the randomnumber function
    ifstream fin;
    fin.open(Deck_information.txt);
    if (fin.fail()){
        cout << "Error Opening the Deck_Information file" << endl;
        exit(1);
    }
    int part1;
    string part2;
    int i=0;
    while (fin>>part1>>part2){
        cardvalue[i]=part1;
        cardname[i]=part2;
        i+=1;
    }
    file.close();
}

int randomnumber(){
    // Return a random number ranging from 0-52.
    
    srand((unsigned) time(NULL)); 
    int random = 0 + (rand() % 53);
    return random;
}

void game_menu(char &choice){
	cout << "Options\nN: New Game\nL: Load Game\nQ: Quit\nYour Choice: ";
	cin >> choice;
}

void game_menu_2(char &choice){
   cout << "Options\nN: Next Game\nS: Save Game\nQ: Quit\nYour Choice: ";
   cin >> choice;
   if (choice == 'S'){
      // call the save function
   }
   // if not 'S' then return to main()
}


int main(){
    // global variable declaration
    int player_money = 1000, house_money = 1000;
    char choice;
    int arrsize=0;		// for "winstat" array sizing
    char *winstat;
    winstat = new char[arrsize];
    bool Won;

    // read player choice
    game_menu(choice);

    while (choice != 'Q'){
    	if (choice == 'N'){
    		// create a new game
    	}
    	else if (choice == 'L'){
    		// load the game
    	}



    	// sizing the win-loss array
   		char *temp; temp = new char[arrsize];
   		for (int i=0; i<arrsize; i++)
   			temp[i] = winstat[i];
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

   		game_menu_2(choice);
    }

    cout << "================================================" << endl;
    cout << "Thank you for playing the game. Goodbye!" << endl;
    cout << "================================================" << endl;
   return 0;
}
