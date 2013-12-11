#include <string>

class Pickup {
	public:
		Pickup(string);
		string getPickupName();
		bool isPickedUp();
		void pickupItem();
	private:
		string pickupName;
		bool pickedUp;
}
