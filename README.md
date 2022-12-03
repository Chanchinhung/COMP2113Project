# COMP2113Project
<ins>"Blackjack"</ins>  
by Sam, Ryan, Arnold, and Zay

Name: Kam Lap Hang (Sam)
UID: 3035940998
Name: Robert Miles Ryan Reese  
UID: 3035743584  
Name: Arnold  
UID:  3035569158
Name: Zay  
UID:  

We have created a text-based version of the popular casino game "Blackjack" written in C++.

<ins>How to play Blackjack</ins>

Object of the game:  
	Each round, the player tries to win by creating a higher card total than the dealer.  
	However, both the player and the dealer can immediately lose the round if their card total goes over 21 (known as a "bust").  

Typical procedure of play:  
1.  
	Both the player and the dealer start with HKD$1000.  
	Every round, the player decides the amount of money they would like to bet.  
2.  
	The player is randomly dealt 2 cards face-down and the dealer is dealt 1 card face-up.  
	The cards are randomly chosen from a typical deck of 52 cards.  
	Every card has an equivalent numerical value listed below.  
3.  
	The player can see both of their own cards as well as the dealer's card.  
	Using this information, the player decides their next move:  
		A. "Hit"  
			Draw an additional card and add its numerical value to their card total.  
			If their card total exceeds 21, the hand is "bust" and the player immediately loses.  
		B. "Stand"  
			End turn and do not draw an additional card.
4.  
	After the player chooses to "stand", the dealer's hand is resolved. 
	The dealer will continually draw cards until the dealer's card total is 17 or higher.  
	If the dealer's hand "busts", the player immediately wins.  
	If the dealer's hand does not "bust", the winner is whoever has a higher card total.  
	The game ends in a draw if both the dealer and the player end up with the same card total.  

Detail of rules:  
1.  
	If the player wins, the dealer pays back double the amount bet by the player.  
	If the player loses, the player loses their entire bet to the dealer.  
	If the round ends in a draw, the player's initial bet is returned by the dealer.  
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
	-The cards drawn by the player are randomly assigned.
	-The cards drawn by the house are randomly assigned.

2.  Data structures for storing game status
	- //Please write something here if something is missing

3.  Dynamic memory management
	-In the Black Jack game, we used vectors to store the player’s and the house’s cards. At the beginning of the game, the vectors storing the cards are empty. After the player and the house draw cards in the game, the card’s information will be pushed into the vector. When the program needs to calculate the cards’ value or print the cards for the player, the program will access the vector and finish these tasks. After playing a round, the program will initialise the vectors back to some empty vectors.
	-When the program is printing out the cards held by the player or the house, the program will use iterators to implement a for-loop to print all the cards held by a player or a buyer.
	- //Please write something here if something is missing

4.  File input/output
	- //Please write something here if something is missing

5.  Program codes in multiple files
	-We have separated our codes into multiple files and made use of the header files and Makefile to make sure the program is running properly. 
	-main.cpp: Controls the whole logic of the program
	-loadWLstat.cpp:
	-SaveWLstat.cpp:
	-DisplayWLStat.cpp:
	-SaveLoadGame.cpp:
	-PlayRound.cpp: To implement the main BlackJack game.
	-GameMenu.cpp: 
	-DisplayHand.cpp: To display the cards held by the player or the house.
	-DetermineWinner.cpp: This determines whether the player or the house won the game in a round.
	-DealCard.cpp: To assign a card to the player or the dealer randomly.
	-Card.cpp: 

6.  Proper indentation and naming styles: We used relevant keywords to be the name of the variables or functions, increasing the readability of the code. Also, we used 	Standard C++ programming style to implement our code, to ensure that our indentation is proper.

7.  In-code documentation: We wrote comments on each function to show how the function works and what is its intended input/output. We also wrote proper comments when it is necessary to explain the logic of a certain part of the function. We believe that this could increase the readability of our program and thus understand our program with ease.
