#include <list>
#include "Weapon.h"

class Player: public Character {
	public:
		Player(); // Constructor. Not sure what to do yet
		int getPerception();

		void setAgility(int);
		void setAccuracy(int);
		void setMelee(int);
		void setCurrentHitpoints(int);
		void setMaxHitpoints(int);
		void setArmourRating(int);

	private:
		list<Weapon> weaponList; // Keep all the weapons in a linked list
		int armourRating;
		int perception;
}

