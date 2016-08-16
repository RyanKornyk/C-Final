#ifndef CARD_H
#define CARD_H
#include <string>
#include <iostream>

using namespace std;

class card {

public:
	card(string name, int ability, int type, int position, int value, int deck); //constructor
	
	//get methods
	string getName();
	
	int getPower(); //return card power
	int getTempPower(); //return the cards temp power
	int getAbility(); //return card ability
	int getType(); //return card type
	int getPosition(); //return card position
	int getDeck(); //return card deck type
	
	//manipulate the temp power
	void changePower(int newPower);


	
	card(); // default constructor

private:
	string Name, ImageUrl;
	int Ability, Type, Position, Power, Deck, TempPower;

};

card::card() {

}
card::card(string name, int ability, int type, int position, int value, int deck) {
	Name = name;
	Ability = ability;
	Type = type;
	Position = position;
	Power = value;
	Deck = deck;
	changePower(Power);
}

//get values
string card::getName() {
	return Name;
}
int card::getPower() {
	return Power;
}
int card::getAbility() {
	return Ability;
}
int card::getType() {
	return Type;
}
int card::getPosition() {
	return Position;
}
int card::getDeck() {
	return Deck;
}
int card::getTempPower() {
	return TempPower;
}

//change the cards Temp power
void card::changePower(int newPower) {
	TempPower = newPower;
}


#endif