#include "Room.h"
#include <stdlib.h>
Room::Room(int number) {
	roomNumber = number;
	pickupList = new vector<Pickup*>;
	weaponList = new vector<Weapon*>;
	characterList = new vector<Character*>;
}

Room::~Room() {
	delete pickupList;
	delete weaponList;
	delete characterList;
}

vector<Pickup*>* Room::getPickupList() {
	return pickupList;
}

vector<Weapon*>* Room::getWeaponList() {
	return weaponList;
}

vector<Character*>* Room::getCharacterList() {
	return characterList;
}

int Room::getNumPickups() {
	return pickupList->size();
}

int Room::getNumWeapons() {
	return weaponList->size();
}

int Room::getNumCharacters() {
	return characterList->size();
}

Weapon* Room::getWeapon(int index) {
	return weaponList->at(index);
}

void Room::addPickup(Pickup* pickup) {
	pickupList->push_back(pickup);
}

void Room::addWeapon(Weapon* weapon) {
	weaponList->push_back(weapon);
}

void Room::addCharacter(Character* character) {
	characterList->push_back(character);
}

void Room::addPlayer(Player* add) {
	player = add;
}

void Room::removePickup(int index) {
	pickupList->erase(pickupList->begin() + index);
}

void Room::removeWeapon(int index) {
	weaponList->erase(weaponList->begin() + index);
}

void Room::removeCharacter(int index) {
	characterList->erase(characterList->begin() + index);
}


void Room::printCharacters() {
	for (int i = 0; i < characterList->size(); i++) {
		cout << (i + 1) << ") " <<
			"Name: " << characterList->at(i)->getCharacterName() <<
			" Current Health: " << characterList->at(i)->getCurrentHitpoints() <<
			" Agility: " << characterList->at(i)->getAgility() << endl;
	}
}

void Room::printPickups() {
	for (int i = 0; i < pickupList->size(); i++) {
		cout << (i + 1) << ") " <<
			"Name: " << pickupList->at(i)->getPickupName() << endl;
	}
}

void Room::printWeapons() {
	for (int i = 0; i < weaponList->size(); i++ ) {
		cout << (i + 1) << ") " <<
			"Name : " << weaponList->at(i)->getWeaponName() << endl;
	}
}

void Room::attack(int a, Player* b, int c) {
	if (a != 1 & a != 0)
		cout << "derp" << endl;
	if (a) {
		int probabilityindex = (b->getAccuracy()-characterList->at(c)->getAgility())+rand() %10;
		if(probabilityindex > 5)
			characterList->at(c)->subtractHitpoints(b->getCurrentWeapon()->getWeaponPower());
	}
	else if (!a) {
		int probabilityindex = (characterList->at(c)->getAccuracy()-b->getAgility())+rand() % 10;
		if(probabilityindex >5){
			if(b->getArmourRating() > characterList->at(c)->getPower())
				b->subtractArmour(characterList->at(c)->getPower());
			else if ((b->getArmourRating() > 0) & b->getArmourRating() < characterList->at(c)->getPower()){
				b->subtractHitpoints(characterList->at(c)->getPower()-b->getArmourRating());
				b->setArmourRating(0);
			}
			else
			b->subtractHitpoints(characterList->at(c)->getPower());
		}
	}
}
