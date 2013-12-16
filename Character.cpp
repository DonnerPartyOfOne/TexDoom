#include "Character.h"
int Character::getPower() {
	return power;
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

void Character::subtractHitpoints(int sub) {
	currentHitpoints -= sub;
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
