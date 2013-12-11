#include "Pickup.cpp"
#include "PickupQuantity.cpp"
#include "Player.cpp"
#include "Character.cpp"
#include "Weapon.cpp"
#include "Room.cpp"
#include <list>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
	string line;
	string playerName;
	int lineNum;
	int numRooms;
	int check;
	char* filename;
	Room** roomList;

	// WAD Parsing Code
	filename = argv[1];
	ifstream myfile(filename);
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
		}
	}

	roomList = new Room*[numRooms];

	// Game start
	cout << "Welcome to Tex Doom! blah blah blah" << endl;
	cout << "Please enter your character's name!" << endl;
	cin >> playerName;

	Player player(playerName);

	cout << "Description of all player stats and current values blah blah" << endl;
	player.rerollStats();
	printStats(player);

	int reroll = 1;

	// Query user for reroll
	while (reroll) {
		cout << "Type '0' to reroll or '1' to start the game." << endl;
		cin >> check;
		if (check == 0) {
			player.rerollStats();
			player.printStats();
		}
		else if (check == 1)
			reroll = 0;
		else
			cout << "Please enter either '0' to reroll or '1' to start the game." << endl;
	}

	int playerLocation = 0;
	int target = 0;
	bool advance = false;

	// Interaction
	while(playerLocation < roomList.size()) {
		Pickup* currentPickupList = Room[playerLocation].getPickupList();
		Weapon* currentWeaponList; = Room[playerLocation.getWeaponList();
		Character* currentCharacterList = Room[playerLocation.getCharacterList();

		while(!advance) {
			cout << "Choose a target (1-n)";
			roomList[playerLocation]->printRoom();
			cin >> target;

			if (target > 0 && target <= roomList[playerLocation]->
		}
	}
}
