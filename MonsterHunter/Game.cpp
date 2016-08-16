#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//custom includes
#include "card.h"
#include "deck.h"
#include "field.h"


int main(int argc, const char* argv[])
{
	srand(time(NULL));
	//create deck
	deckCards Hunters(1), Monsters(2);
	//create hands
	handCards Player, Opponent;
	//field
	field GameField;
	int playerDeck = 0, randomNumber, opponentChoice;
	//menu system
	Hunters.shuffle();
	Monsters.shuffle();
	//choose decks
	cout << "Would you like to be Hunters(1) or Monsters(2)" << endl;
	cin >> playerDeck;
	if(playerDeck == 1){
		cout << "You have chosen Hunters" << endl;
	}else if (playerDeck == 2) {
		cout << "You have chosen Monsters" << endl;
	}
	//draw cards
	if (playerDeck == 1) {
		for (int x = 0; x <= 10; x++) {
			Player.addCard(Hunters.dealCard());
			Opponent.addCard(Monsters.dealCard());
		}
	}
	else
	{
		for (int x = 0; x <= 10; x++) {
			Player.addCard(Monsters.dealCard());
			Opponent.addCard(Hunters.dealCard());
		}
	}
	//turns
	GameField.displayField();
	bool gameContinue = true;
	char input;
	int playerChoice = 0, round = 0, wins = 0, losses = 0;
	while (gameContinue) {
		//display the users hand
		cout << "|------HAND---------------|" << endl;
		Player.getCardString();
		//ask user to play a card
		cout << endl << "Please choose your card the number represents what card you want to play:" << endl;
		cin >> playerChoice;
		while (playerChoice > Player.getHandSize()) {
				cin >> playerChoice;
		}
		if (Player.getHandSize() > 0) {
			GameField.placeCard(Player.playCard(playerChoice), 1);
		}
		//opponent plays random card
		if (Opponent.getHandSize() > 0) {
			opponentChoice = rand() % Opponent.getHandSize();
			GameField.placeCard(Opponent.playCard(opponentChoice), 2);
		}
		//display current score and opponent score
		
		GameField.displayField();
		cout << GameField.displayScores() << endl;
		if (Player.getHandSize() > 0) {
			cout << "Do you want to continue (y/n):";
			cin >> input;
		}
		else {
			input = 'n';
		}

		if (input == 'n') {
			round++;
			//figure out who won
			GameField.calcScores();
			if (GameField.determineWinner() == 1) {
				wins++;
			}
			else if (GameField.determineWinner() == 2) {
				losses++;
			}
			cout << "You won " << wins << " rounds" << endl;
			cout << "Your opponent won " << losses << " rounds" << endl;
			GameField.clearField();
			if (Player.getHandSize() == 0 || Opponent.getHandSize() == 0 || wins == 2 || losses == 2) {
				round = 3;
			}
			if (round == 3) {
				gameContinue = false;
			}
		}
	}
	if (wins > losses) {
		cout << "You Won!" << endl;
		system("PAUSE");
	}
	else {
		cout << "You Lost!" << endl;

		system("PAUSE");
	}
}