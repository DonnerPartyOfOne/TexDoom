#include "Player.h"

int Player::getPerception() {
	return perception;
}

int Player::getMelee() {
	return melee;
}

int Player::getSlugs() {
	return slugs;
}

int Player::getShells() {
	return shells;
}

int Player::getRockets() {
	return rockets;
}

int Player::getPlasmaCells() {
	return plasmaCells;
}

void Player::setAgility(int agi) {
	agility = agi;
}

void Player::setAccuracy(int acc) {
	accuracy = acc;
}

void Player::setMelee(int mel) {
	melee = mel;
}

void Player::setCurrentHitpoints(int current) {
	currentHitpoints = current;
}

void Player::setMaxHitpoints(int hp) {
	maxHitpoints = hp;
}

void Player::setArmourRating(int arm) {
	armourRating = arm;
}

void Player::rerollStats() {

}

void Player::printStats() {
	cout << "Perception: " << perception << endl <<
		"Agility: " << agility << endl <<
		"Accuracy: " << accuracy << endl <<
		"Melee: " << melee << endl;
}

