/*Field does all the calculations and returns the current scores of the players
field has 9 hands 3 for each player, the weather hand, and the graveyards*/

#ifndef field_H
#define field_H
#include "card.h"
#include "hand.h"
#include <string>
#include <vector>

class field {
private:

	card tempCard;
	handCards playerClose, playerMid, playerLong, playerGrave, opponentClose, opponentMid, opponentLong, opponentGrave, weather;
	int playerScore, OpponentScore;
	bool closeWeather, midWeather, longWeather;
	
public:
	field();
	void placeCard(card, int); //figure out where are card
	void clearField(); //put all cards into their graveyards
	int determineWinner(); // compare the scores of each player
	void calcScores(); //figure out the scores for the lanes
	void displayField(); //show the 6 lanes
	string displayScores(); // show the two scores
};
field::field() {

}
void field::placeCard(card placedCard, int player) {
	int fieldPlace = placedCard.getPosition();
	//check the player
	if (player == 1) {
		//place in player field
		if (fieldPlace == 0) {
			playerClose.addCard(placedCard);
		}
		else if (fieldPlace == 1) {
			playerMid.addCard(placedCard);
		}
		else if (fieldPlace == 2) {
			playerLong.addCard(placedCard);
		}
	}else if (player == 2) {
		//place in opponent field
		if (fieldPlace == 0) {
			opponentClose.addCard(placedCard);
		}
		else if (fieldPlace == 1) {
			opponentMid.addCard(placedCard);
		}
		else if (fieldPlace == 2) {
			opponentLong.addCard(placedCard);
		}
	}
	calcScores();
}
void field::clearField() {
	//go through each hand and add those cards to the graveyards
	int position = 0;
	//Player Close
	int handSize = playerClose.getHandSize();
	for (position = 0; position < handSize; position++) {
		playerGrave.addCard(playerClose.playCard(position));
	}
	//player mid
	handSize = playerMid.getHandSize();
	for (position = 0; position < handSize; position++) {
		playerGrave.addCard(playerMid.playCard(position));
	}
	//player far
	handSize = playerLong.getHandSize();
	for (position = 0; position < handSize; position++) {
		playerGrave.addCard(playerLong.playCard(position));
	}
	//opponent close
	handSize = opponentClose.getHandSize();
	for (position = 0; position < handSize; position++) {
		opponentGrave.addCard(opponentClose.playCard(position));
	}
	//opponent mid
	handSize = opponentMid.getHandSize();
	for (position = 0; position < handSize; position++) {
		opponentGrave.addCard(opponentMid.playCard(position));
	}
	//opponent far
	handSize = opponentLong.getHandSize();
	for (position = 0; position < handSize; position++) {
		opponentGrave.addCard(opponentLong.playCard(position));
	}
	playerScore = 0;
	OpponentScore = 0;
}
int field::determineWinner() {
	
	//return 1 if play return 2 if computer
	if (playerScore > OpponentScore) {
		return 1;
	}
	else {
		return 2;
	}
}
void field::calcScores() {
	//add all the power for player
	playerScore = playerClose.getHandPower() + playerMid.getHandPower() + playerLong.getHandPower();
	//add all the power for computer
	OpponentScore = opponentClose.getHandPower() + opponentMid.getHandPower() + opponentLong.getHandPower();
}
void field::displayField() {
	cout << "|------LONG---------------|" << endl;
	opponentLong.getCardString();
	cout << "|------MID----------------|" << endl;
	opponentMid.getCardString();
	cout << "|------CLOSE--------------|" << endl;
	opponentClose.getCardString();
	cout << "|-------------------------|" << endl;
	playerClose.getCardString();
	cout << "|------CLOSE--------------|" << endl;
	playerMid.getCardString();
	cout << "|------MID----------------|" << endl;
	playerLong.getCardString();
	cout << "|------LONG---------------|" << endl;
}
string field::displayScores() {
	string scores;
	scores.append("Your Score is: " + to_string(playerScore));
	scores.append(" Opponents Score is: " + to_string(OpponentScore));
	return scores;
}
#endif