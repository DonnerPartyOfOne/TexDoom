#include "Pickup.h"

class Ammo: public Pickup {
	public:
		Ammo(string, int);
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
