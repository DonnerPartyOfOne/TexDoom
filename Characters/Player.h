#include <list>
#include "Weapon.h"

class Player: public Character {
	public:
		Player(string); // Constructor. Not sure what to do yet

		int getPerception();
		int getMelee();
		int getSlugs();
		int getShells();
		int getRockets();
		int getPlasmaCells();

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
		int melee;

		int slugs; // Pistol/Chaingun
		int shells; // Shotty/Super Shotty
		int rockets; // Roket Launcher
		int plasmaCells; // Rifle/BFG
}

