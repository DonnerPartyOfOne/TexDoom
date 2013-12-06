#include "Weapon.h"

class Character {
	public:
		int getAgility();
		int getAccuracy();
		int getMelee();
		int getCurrentHitpoints();

		Weapon getCurrentWeapon();

	private:
		int agility;
		int accuracy;
		int melee;
		int maxHitpoints;
		int currentHitpoints;

		Weapon currentWeapon;
}
