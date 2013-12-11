#include "Pickup.h"

class PickupQuantity: public Pickup {
	public:
		PickupQuantity(string, int);
		int getAmount();
	private:
		int amount;
}
