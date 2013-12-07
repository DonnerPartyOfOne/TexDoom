Character::Character(string name, int agi, int acc, int max) {
	characterName = name;
	agility = agi;
	accuracy = acc;
	maxHitpoints = max;
}

int Character::getAgility() {
	return agility;
}

int Character::getAccuracy() {
	return accuracy;
}

int Character::getCurrentHitpoints() {
	return currentHitpoints;
}

Weapon Character:: getCurrentWeapon() {
	return currentWeapon;
}

string Character::getCharacterName() {
	return characterName;
}

