#include "Room.h"

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

}

void Room::printWeapons() {

}

void Room::attack(int a, Player* b, int c) {

}
