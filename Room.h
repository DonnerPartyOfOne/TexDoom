#include "Pickup.cpp"
#include "PickupQuantity.cpp"
#include "Weapon.cpp"
#include "Character.cpp"

public Room {
	public:
		Room(int, int, int, int);
		~Room();
		Pickup* getPickupList();
		Weapon* getWeaponList();
		Character* getCharacterList();
		void addPickup(Pickup, int);
		void addWeapon(Weapon, int);
		void addCharacter(Character, int);
		void removePickup(int);
		void removeWeapon(int);
		void removeCharacter(int)
	private:
		int roomNumber;
		Pickup* pickupList;;
		Weapon* weaponList;
		Character* characterList;
}
