int Character::getAgility() {
	return agility;
}

int Character::getAccuracy() {
	return accuracy;
}

int Character::getCurrentHitpoints() {
	return currentHitpoints;
}

string Character::getCharacterName() {
	return characterName;
}

bool Character::isDead() {
	return dead;
}

void Character::kill() {
	dead = true;
}
