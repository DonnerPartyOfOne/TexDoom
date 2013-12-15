#include "Pickup.cpp"
#include "Weapon.cpp"
#include "Player.cpp"
#include "Character.cpp"
#include <vector>
#include <string>

using namespace std;

class Room {
	public:
		Room(int);
		~Room();

		vector<Pickup*>* getPickupList();
		vector<Weapon*>* getWeaponList();
		vector<Character*>* getCharacterList();

	        int getNumPickups();
	        int getNumWeapons();
	        int getNumCharacters();

		Weapon* getWeapon(int);

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
		vector<Pickup*>* pickupList;
		vector<Weapon*>* weaponList;
		vector<Character*>* characterList;
};
