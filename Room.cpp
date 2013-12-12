Room::Room(int number) {
	roomNumber = number;
	pickupList = new vector<*Pickup>;
	weaponList = new vector<*Weapon>;
	characterList = new vector<*Character>;
}

Room::~Room() {
	delete pickupList;
	delete weaponList;
	delete characterList;
}

vector<*Pickup>* Room::getPickupList() {
	return pickupList;
}

vector<*Weapon>* Room::getWeaponList() {
	return weaponList;
}

vector<*Character>* Room::getCharacterList() {
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

void addPickup(Pickup* pickup) {
	pickupList->push_back(pickup);
}

void addWeapon(Weapon* weapon) {
	weaponList->push_back(weapon);
}

void addCharacter(Character* character) {
	characterList->push_back(character);
}

void addPlayer(Player* add) {
	player = add;
}

void removePickup(int index) {
	pickupList->erase(pickupList->begin() + index);
}

void removeWeapon(int index) {
	weaponList->erase(weaponList->begin() + index);
}

void removeCharacter(int index) {
	weaponList->erase(weaponList->begin() + index);
}


void printCharacters() {
	for (int i = 0; i < characterList->size(); i++) {
		cout << (i + 1) << ") " <<
			"Name: " << characterList[i]->getName() << 
			" Current Health: " << characterList[i]->getCurrentHealth() <<
			" Agility: " << characterList[i]->getAgility() << endl;
	}
}

void printPickups() {

}

void printWeapons() {

}


void attack(Player* player, int index) {

}
