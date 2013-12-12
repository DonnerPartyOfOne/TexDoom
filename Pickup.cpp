Pickup::Pickup(string name) {
	pickupName = name;
	pickedUp = false;
}

string Pickup::getPickupName() {
	return pickupName;
}

bool Pickup::isPickedUp() {
	return pickedUp;
}

void Pickup::pickupItem() {
	pickedUp = true;
}
