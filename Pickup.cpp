#include "Pickup.h"

string Pickup::getPickupName() {
	return pickupName;
}

bool Pickup::isPickedUp() {
	return pickedUp;
}

void Pickup::pickupItem() {
	pickedUp = true;
}
