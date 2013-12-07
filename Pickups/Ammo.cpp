Ammo::Ammo(string name, int amount) {
	pickupName = name;

	if (name == "slugs")
		slugs = amount;
	else if (name == "shells")
		shells = amount;
	else if (name == "rockets")
		rockets = amount;
	else if (name == "plasmaCells")
		plasmaCells = amount;
}

int Ammo::getSlugs() {
	return slugs;
}

int Ammo::getShells() {
	return shells;
}

int Ammo::getRockets() {
	return rockets;
}

int Ammo::getPlasmaCells() {
	return plasmaCells;
}
