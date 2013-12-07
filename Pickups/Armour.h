#include "Pickup.h"

class Armour: public Pickup {
	public:
		Armour(string, int);
		int getArmour();
	private:
		int armour;
}
