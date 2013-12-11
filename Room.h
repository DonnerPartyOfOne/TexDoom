#include "Pickup.cpp"
#include "PickupQuantity.cpp"
#include "Weapon.cpp"
#include "Character.cpp"
#include <list>

public Room {
	public:
		Room(int);
		list<Pickup> getPickupList();
		list<Weapon> getWeaponList();
		list<Character> getCharacterList();
		void addPickup(Pickup);
		void addWeapon(Weapon);
		void addCharacter(Character);
		void removePickup(int);
		void removeWeapon(int);
		void removeCharacter(int)
	private:
		int roomNumber;
		list<Pickup> pickupList;
		list<Weapon> weaponList;
		list<Character> characterList;
}
