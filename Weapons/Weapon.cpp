Weapon::Weapon(string name, int pow) {
	weaponName = name;
	weapon power = pow;
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
