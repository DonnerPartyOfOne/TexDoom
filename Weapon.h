#include <string>
class Weapon {
	public:
		Weapon(string, int);
		void setWeaponPower(int);
		int getWeaponPower();
		string getWeaponName();
		bool isPickedUp();
		void pickupWeapon();
	private:
		int weaponPower;
		string weaponName;
		bool pickedUp;
}
