Weapon::Weapon(string name, int pow) {
	weaponName = name;
	weaponPower = pow;
	pickedUp = false;
}

void Weapon::setWeaponPower(int pow) {
	weaponPower = pow;
}

int Weapon::getWeaponPower() {
	return weaponPower;
}

string Weapon::getWeaponName() {
	return weaponName;
}

bool Weapon::isPickedUp() {
	return pickedUp;
}

void Weapon::pickupWeapon() {
	pickedUp = true;
}
