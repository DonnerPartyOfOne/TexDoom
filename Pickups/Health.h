#include "Pickup.h"

class Health: public Pickup {
	public:
		Health(string, int);
		int getHealth();
	private:
		int health;
}
