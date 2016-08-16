/*Deck gets the cards and can be drawn from or shuffled or added to*/
#ifndef deck_H
#define deck_H
#include "card.h"
#include <algorithm>
#include <string>
#include <vector>
#include <random>
#include <iostream>
#include <fstream>

using namespace std;

class deckCards {
private:
	
	card tempCard;
	vector<card> Cards;
	int deckType, deckSize, currentCard = 0;
public:
	deckCards(int deckType);
	void shuffle();
	card dealCard();
	void addCard(card);
};

deckCards::deckCards(int getType) {
	deckType = getType;
	//get cards from the file
	//open file
	ifstream ReadFile;
	//open the right deck
	if (deckType == 1) {
		ReadFile.open("hunters.txt");
	}
	else if (deckType == 2) {
		ReadFile.open("monster.txt");
	}

	string output;
	string name, Url;
	int ability = 0, type = 0, place = 0, value = 0, deck = 0;
	int position = 0;
	if (ReadFile.is_open()) {
		while (!ReadFile.eof()) {
			
			//string string int int int int int string
			getline(ReadFile, output);
			if (output == "NEW CARD") {
				position = 1;
			}
			//grabbing card name
			else if (position == 1) {
				name = output; 
				position++;
			}
			//grab card ability
			else if (position == 2) {
				ability = atoi(output.c_str());
				position++;
			}
			//grab card type
			else if (position == 3) {
				type = atoi(output.c_str());
				position++;
			}
			//position
			else if (position == 4) {
				place = atoi(output.c_str());
				position++;
			}
			//value
			else if (position == 5) {
				value = atoi(output.c_str());
				position++;
			}
			//deck
			else if (position == 6) {
				deck = atoi(output.c_str());
				position++;

				tempCard = card(name, ability, type, place, value, deck);
				Cards.push_back(tempCard);
				deckSize++;
			}
		}
	}
	ReadFile.close();
	//loop through cards grabbing cards with type matching deck or neutral cards
}
//shuffle the cards in the deck
void deckCards::shuffle() {
	std::random_shuffle(Cards.begin(), Cards.end());
}

card deckCards::dealCard() {
	currentCard++;
	if (currentCard < deckSize) {
		return Cards[currentCard];
	}
	//Cards.erase(Cards.begin());
	return Cards[0];
}

#endif