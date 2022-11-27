# COMP2113Project
<ins>"Blackjack"</ins>  
by Sam, Ryan, Arnold, and Zay

Name: Kam Lap Hang (Sam)
UID: 3035940998
Name: Robert Miles Ryan Reese  
UID: 3035743584  
Name: Arnold  
UID:  
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
	Ace - 1 or 11 (according to the player's choice, choose before the start of the game)  
	Two - 2  
	Three - 3  
	.  
	.  
	.  
	Nine - 9  
	Ten - 10  
	Face cards (Jack/Queen/King) - 10  
3.  
	If the player draws a card total of 21 from their first two cards, this is known as a "Blackjack".  
	In this case, the player immediately wins the round unless the dealer also draws a "Blackjack".  
	If the player draws two identical cards from their first two cards, they can choose to "split".  
	In this case, the two cards are split into two separate hands that are simultaneously played by the player.  
