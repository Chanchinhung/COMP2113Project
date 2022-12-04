# COMP2113Project
<ins>"Blackjack"</ins>  
by Sam, Ryan, Arnold, and Zay

Name: Kam Lap Hang (Sam)
UID:  3035940998

Name: Robert Miles Ryan Reese  
UID:  3035743584  

Name: Arnold  
UID:  3035569158

Name: Chan Chin Hung (Zay)  
UID:  3035788625

We have created a text-based version of the popular casino game "Blackjack" written in C++.

<ins>How to play Blackjack</ins>

Object of the game:  
	Each round, the player tries to win by creating a higher card total than the house.  
	However, both the player and the house can immediately lose the round if their card total goes over 21 (known as a "bust").  

Typical procedure of play:  
1.  
	Both the player and the house start with HKD$1000.  
	Every round, the player decides the amount of money they would like to bet.  
2.  
	The house is randomly dealt 1 card face-up and the player is randomly dealt 2 cards face-down.  
	The cards are randomly chosen from a typical deck of 52 cards.  
	Every card has an equivalent numerical value listed below.  
3.  
	The player can see both of their own cards as well as the house's card.  
	Using this information, the player decides their next move:  
		A. "Hit"  
			Draw an additional card and add its numerical value to their card total.  
			If their card total exceeds 21, the hand is "bust" and the player immediately loses.  
		B. "Stand"  
			End turn and do not draw an additional card.
		C. "Double Down"
			Double the amount of bet in this round, draw an additional card and add its numerical value to their card total.
			If their card total exceeds 21, the hand is "bust" and the player immediately loses.
			If the hand is not bust then end player turn.
		D. "Surrender"
			The player immediately loses and loses half their bet.
		On special occasions where the player is dealt 2 cards with same card face, e.g., two K, they have the following extra option.
		E. "Split"
			The player can split the two cards into two hands, place a new bet equal to the amount they placed for this round, and play the two hands simultaneously.
4.  
	After the player chooses to "stand", or "double down" wihtout busting, the house's hand will be resolved. 
	The house will continually draw cards until the their card total is 17 or higher.  
	If the house's hand "busts", the player immediately wins.  
	If the house's hand does not "bust", the winner is whoever has a higher card total.  
	The game ends in a draw if both the house and the player end up with the same card total.  

Detail of rules:  
1.  
	If the player wins, the house pays the amount bet by the player.  
	If the player loses, the player loses their entire bet to the dealer.  
	If the round ends in a draw, the player's initial bet is returned to them.  
2.  
	Numerical values of cards (does not depend on suit):  
	Ace - 1 or 11 (according to the player's choice)  
	Two - 2  
	Three - 3  
	...  
	Nine - 9  
	Ten - 10  
	Face cards (Jack/Queen/King) - 10  
3.  
	If the player draws a card total of 21 from their first two cards, this is known as a "Blackjack".  
	In this case, the player immediately wins the round unless the dealer also draws a "Blackjack".  
	If the player draws two identical cards from their first two cards, they can choose to "split".  
	In this case, the two cards are split into two separate hands that are simultaneously played by the player.  

<ins>Our program features encompass the following coding requirements:</ins>

1.  Generation of random game sets or events
	In every round,
	-The cards drawn by the player are randomly assigned.
	-The cards drawn by the house are randomly assigned.

2.  Data structures for storing game status
	-Two integer variables are used to store the amount of money the player and the house has left.
	-A self-defined structure 'card' with two char variable storing its face (A,1,2,...,J,Q,K) and suit and one int variable storing the value of the card 
	-Two vectors (three if player "split" their hand) of the structure 'card' are used to store the hands of house and player
	-A self-defined structure 'RoundStat' with a char variable to store result of the round and an interger variable to store amount of money won by player in the round
	-A vector of 'RoundStat' to store the overall statistics of a run

3.  Dynamic memory management
	-In the Black Jack game, we used vectors to store the player’s and the house’s cards. At the beginning of the game, the vectors storing the cards are empty. After the player and the house draw cards in the game, the card’s information will be pushed into the vector. When the program needs to calculate the cards’ value or print the cards for the player, the program will access the vector and finish these tasks. After playing a round, the program will initialise the vectors back to some empty vectors.
	-When the program is printing out the cards held by the player or the house, the program will use iterators to implement a for-loop to print all the cards held by a player or a buyer.
	-After each round, the information of the round is pushed into the vector storing the information of all rounds played in the run
	-When the program is printing out the statistics of a run, the program will use iterators to implement a for-loop to print the information of all rounds played.
	
4.  File input/output
	-The player can load a previous game they have saved in a text file, retrieving the money the player and house have left, as well as the statistics of all previous rounds played in that game.
	-The player can save their current game to be played later, storing the money the player and house have left, as well as the statistics of all previous rounds played in that game in a text file.

5.  Program codes in multiple files
	-We have separated our codes into multiple files and made use of the header files and Makefile to make sure the program is running properly. 
	-main.cpp: Controls the whole logic of the program
	-DisplayWLStat.cpp: Contains functions to display the statistics of rounds played
	-SaveLoadGame.cpp: Contains functions to save the current game status to text file or load previous game status
	-PlayRound.cpp: Contains functions to implement the main BlackJack game.
	-GameMenu.cpp: Contains functions to output the different menus and instructions for playing the game on screen
	-DisplayHand.cpp: Contains functions to display the cards held by the player or the house.
	-DetermineWinner.cpp: Contains functions to determines whether the player or the house won the game in a round.
	-DealCard.cpp: Contains functions to assign a card to the player or the dealer randomly.
	-Card.cpp: Contains member functions of the self-defined structure 'card' for other functions to use

<ins>Compilation and execution instructions:</ins>
Within the directory, use command 'make main' to create the executable game file, and use command './main' to launch the game and play
