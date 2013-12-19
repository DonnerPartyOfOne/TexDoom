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
int Player::getArmourRating(){
	return armourRating;
}
void Player::pickupItem(Pickup* item){
	if(item->getPickupName() == "HP+10"){
		if((currentHitpoints>90) && (currentHitpoints < 100))
			currentHitpoints = 100;
		else if(currentHitpoints <=90)
			currentHitpoints += 10;
	}
	if(item->getPickupName() == "HP+100"){
		if(currentHitpoints < 100)
			currentHitpoints = 100;
	}
	if(item->getPickupName() == "HP+1"){
		if(currentHitpoints < 200)
			currentHitpoints += 1;
	}
	if(item->getPickupName() == "Armor+100"){
		if(armourRating < 100)
			armourRating = 100;
	}
	if(item->getPickupName() == "Armor+1"){
		if(armourRating < 200)
			armourRating += 1;
	}
	if(item->getPickupName() == "Slugs"){
		if((slugs < 200) && (slugs >180))
			slugs = 200;
		else if (slugs <=180)
			slugs += 20;
	}
	if(item->getPickupName() == "Shotgun Shells"){
                if((shells < 50) && (shells > 46))
                        shells = 50;
                else if (slugs <= 46)
                        shells += 4;
        }
	if(item->getPickupName() == "Rockets"){
                if((rockets < 50) && (rockets >48))
                        rockets = 50;
                else if (rockets <= 48)
                        rockets += 2;
        }
	if(item->getPickupName() == "Plasma Cells"){
                if((plasmaCells < 600) && (plasmaCells>500))
                        plasmaCells = 600;
                else if (plasmaCells <= 500)
                        plasmaCells += 100;
        }

}
void Player::addWeapon(Weapon* add) {
	bool have = false;

	for (int i = 0; i < weaponList.size(); i ++) {
		if (weaponList.at(i)->getWeaponName() == add->getWeaponName())
			have = true;
	}

	string name = add->getWeaponName();
	if (name == "Pistol" || name == "Chaingun")
		slugs += 20;
	else if (name == "Shotgun" || name == "Super Shotgun")
		shells += 4;
	else if (name == "Rocket Launcher")
		rockets += 5;
	else if (name == "Plasma Rifle" || name == "BFG 9000")
		plasmaCells += 100;

	if (!have)
		weaponList.push_back(add);
}

void Player::subtractArmour(int x){
	armourRating -= x;
}
void Player::fire() {
	if (currentWeapon->getWeaponName() == "Pistol")
		slugs -= 1;
	else if (currentWeapon->getWeaponName() == "Chaingun")
		slugs -= 5;
	else if (currentWeapon->getWeaponName() == "Shotgun")
		shells -= 1;
	else if (currentWeapon->getWeaponName() == "Super Shotgun")
		shells -= 2;
	else if (currentWeapon->getWeaponName() == "Rocket Launcher")
		rockets -=1;
	else if (currentWeapon->getWeaponName() == "Plasma Rifle")
		plasmaCells -= 5;
	else if (currentWeapon->getWeaponName() == "BFG 9000")
		plasmaCells -= 60;
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
		cout << i + 1 << ") " << name << endl;
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
