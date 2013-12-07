#include "Pickup.h"

class Health: public Pickup {
	public:
		int getHealth();
	private:
		int health;
}
