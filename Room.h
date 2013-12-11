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
		void addPickup(Pickup*, int);
		void addWeapon(Weapon*, int);
		void addCharacter(Character*, int);
		void addPlayer(Player*);
		void removePickup(int);
		void removeWeapon(int);
		void removeCharacter(int);

		void attack(Player*, int);
		void printCharacters();
		void printPickups();
		void printWeapons();
		int getCharacterQuantity();
	private:
		int roomNumber;
		Player** player;
		Pickup** pickupList;
		Weapon** weaponList;
		Character** characterList;
}
