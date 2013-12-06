#include <list>

class Player: public Character {
	public:
		Player(); // Constructor. Not sure what to do yet
		void setArmourRating(int);

	private:
		list<Weapon> weaponList; // Keep all the weapons in a linked list
		int armourRating;
}

