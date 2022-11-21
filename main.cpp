#include <iostream>
using namespace std;

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
