Room::Room(int number) {
	roomNumber = number;
}

list<Pickup> Room::getPickupList() {
	return pickupList;
}

list<Weapon> Room::getWeaponList() {
	return weaponList;
}

list<Character> Room::getCharacterList() {
	return characterList;
}

void addPickup(Pickup add) {
	pickupList.push_front(add);
}

void addWeapon(Weapon add) {
	pickupList.push_front(add);
}

void addCharacter(Character add) {
	pickupList.push_front(add);
}

void removePickup(int) {

}

void removeWeapon(int) {

}

void removeCharacter(int) {

}

