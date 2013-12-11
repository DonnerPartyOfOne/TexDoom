#include <string>
#include "Weapon.h"

class Character {
	public:
		Character(string, int, int, int);
		int getAgility();
		int getAccuracy();
		int getCurrentHitpoints();

		Weapon getCurrentWeapon();
		string getCharacterName();

		bool isDead();
		void kill();
	private:
		int agility;
		int accuracy;
		int maxHitpoints;
		int currentHitpoints;

		Weapon currentWeapon;
		string characterName;

		bool dead;
}
