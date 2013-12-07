#include "Pickup.h"

class Ammo: public Pickup {
	public:
		int getSlugs();
		int getShells();
		int getRockets();
		int getPlasmaCells();

	private:
		int slugs;
		int shells;
		int rockets;
		int plasmaCells;
}
