#include "Player.h"
#include <stdlib.h>
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

void Player::addSlugs(int add) {
        slugs += add;
}

void Player::addShells(int add) {
        shells += add;
}

void Player::addRockets(int add) {
        rockets += add;
}

void Player::addPlasmaCells(int add) {
        plasmaCells += add;
}

void Player::addWeapon(Weapon* add) {
	bool have = false;

	for (int i = 0; i < weaponList.size(); i ++) {
		if (weaponList.at(i)->getWeaponName() == add->getWeaponName())
			have = true;
	}

	if (have) {
		string name = add->getWeaponName();
		if (name == "pistol" || name == "chaingun")
			addSlugs(5);
		else if (name == "shotty" || name == "super shotty")
			addShells(5);
		else if (name == "rocket launcher")
			addRockets(5);
		else if (name == "plasma rifle" || name == "BFG")
			addPlasmaCells(5);
		else
			cout << "derp";
	}
	else
		weaponList.push_back(add);
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

void Player::setArmourRating(int arm) {
	armourRating = arm;
}

void Player::rerollStats() {
	perception = rand() % 10;
	agility = rand() % 10;
	accuracy = rand() % 10;
	melee = rand() % 10;
	if(perception+agility+accuracy+melee > 32){
		if(perception >8)
			perception -=2;
		if(agility >8)
			agility -=2;
		if(accuracy >8)
			accuracy -=2;
		if(melee > 8)
			melee -=2;
		
	}
}

void Player::printStats() {
	cout << "Perception: " << perception << endl <<
		"Agility: " << agility << endl <<
		"Accuracy: " << accuracy << endl <<
		"Melee: " << melee << endl;
}

Weapon* Player::getCurrentWeapon() {
	return currentWeapon;
}

void Player::setCurrentWeapon(int index) {
	currentWeapon = weaponList.at(index);
}

void Player::printWeaponList() {
	for (int i = 0; i < weaponList.size(); i++) {
		string name = weaponList.at(i)->getWeaponName();
		cout << "1) " << name << endl;
		if (name == "Pistol" || name == "Chaingun")
			cout << "Slugs: " << slugs << endl;
		else if (name == "Shotgun" || name == "Super Shotgun")
			cout << "Shells: " << shells << endl;
		else if (name == "Rocket Launcher")
			cout << "Rockets: " << rockets << endl;
		else if (name == "Plasma Rifle" || name == "BFG 9000")
			cout << "Plasma Cells: " << plasmaCells << endl;
		else
			cout << "Incorrect weapon name" << endl;
	}
}
