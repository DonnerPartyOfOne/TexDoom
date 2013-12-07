#include <string>
class Weapon {
	public:
		Weapon(string, int);
		void setWeaponPower(int);
		int getWeaponPower();
		string getWeaponName();

	private:
		int weaponPower;
		string weaponName;
}
