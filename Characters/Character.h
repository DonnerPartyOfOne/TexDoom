#include <string>
#include "Weapon.h"

class Character {
	public:
		int getAgility();
		int getAccuracy();
		int getCurrentHitpoints();

		Weapon getCurrentWeapon();
		string getCharacterName();

	private:
		int agility;
		int accuracy;
		int maxHitpoints;
		int currentHitpoints;

		Weapon currentWeapon;
		string characterName;
}
