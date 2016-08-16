/*Hand can play cards to field and get card new cards, hand is also a graveyard*/
#ifndef hand_H
#define hand_H
#include "card.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class handCards {
private:

	card tempCard;
	vector<card> Cards;
	int currentCard, handScore;
	string nameToMax(string name);

public:
	handCards();
	card playCard(int num); //return a card from this hand and remove it from the hand
	void addCard(card); //add a card the the players hand
	void getCardString(); //print the names and values of the cards
	int getHandPower(); //get the current power of the hand
	int getHandSize(); //retunr the number of cards
};
handCards::handCards() {

}
card handCards::playCard(int num) {
	card chosenCard = Cards[num];
	Cards.erase(Cards.begin() + num);
	return chosenCard;
}

void handCards::addCard(card newCard) {
	Cards.push_back(newCard);
}


void handCards::getCardString() {
	string cardPreview;
	//loop through hand
	for (int y = 0; y <= 3; y++) {
		for (int x = 0; x < Cards.size(); x++) {
			tempCard = Cards[x];
			cardPreview.append("|");
			
			if (y == 0) {
				cardPreview.append(to_string(x));
				cardPreview.append("  ");
				cardPreview.append(tempCard.getName());
			}
			else if (y == 1) {
				cardPreview.append("  ");
				cardPreview.append(to_string(tempCard.getPosition()));
			}
			else if (y == 2) {
				cardPreview.append("  ");
				cardPreview.append(to_string(tempCard.getTempPower()));
			}
		}
		cardPreview.append("\n");
	}

	//return the string
	cout << cardPreview;
}

string handCards::nameToMax(string name) {
	const int MAX_CHARS = 10;
	int size = name.size();
	if (size <= MAX_CHARS) {
		string newString = name;
		for (int i = size; i < MAX_CHARS; i++) {
			name.append(" ");
		}
		return newString;
	}
	else {
		return name.substr(0, 10);
	}
}

int handCards::getHandPower(){
	int power = 0;
	for (int x = 0; x < Cards.size(); x++) {
		tempCard = Cards[x];
		power += tempCard.getTempPower();
	}
	return power;
}
int handCards::getHandSize() {
	return Cards.size();
}
#endif