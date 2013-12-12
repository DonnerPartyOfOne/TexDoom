#include "Pickup.cpp"
#include "PickupQuantity.cpp"
#include "Weapon.cpp"
#include "Character.cpp"
#include <vector>

public Room {
	public:
		Room(int);
		~Room();

		vector<*Pickup>* getPickupList();
		vector<*Weapon>* getWeaponList();
		vector<*Character>* getCharacterList();

	        int getNumPickups();
	        int getNumWeapons();
	        int getNumCharacters();

		void addPickup(Pickup*);
		void addWeapon(Weapon*);
		void addCharacter(Character*);
		void addPlayer(Player*);

		void removePickup(int);
		void removeWeapon(int);
		void removeCharacter(int);

		void printCharacters();
		void printPickups();
		void printWeapons();

	        void attack(int, Player*, int);

	private:
		int roomNumber;
		Player* player;
		vector<*Pickup> *pickupList;
		vector<*Weapon> *weaponList;
		vector<*Character> *characterList;
}
