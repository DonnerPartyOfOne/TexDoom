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

void printStats(Player player) {
        cout << "Perception: " << player.getPerception() << endl <<
                "Agility: " << player.getAgility() << endl <<
                "Accuracy: " << player.getAccuracy() << endl <<
                "Melee: " << player.getMelee() << endl;
}

int main(int argc, char* argv[]) {
	string line;
	string playerName;
	int lineNum;
	int numRooms;
	int check;
	char* filename;
	Room* roomList;

	// WAD Parsing Code
	filename = argv[1];
	ifstream myfile(filename);
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
		}
	}

	roomList = new Room[numRooms];

	// Game start
	cout << "Welcome to Tex Doom! blah blah blah" << endl;
	cout << "Please enter your character's name!" << endl;
	cin >> playerName;

	Player player(playerName);

	cout << "Description of all player stats and current values blah blah" << endl;
	player.rerollStats();
	printStats(player);

	cout << "First roll. Type '0' to reroll or '1' to start the game" << endl;
	cin >> check;

	int reroll = 1;

	// Query user for reroll
	while (reroll) {
		if (check == 0) {
			player.rerollStats();
			printStats(player);
			cout << "Type '0' to reroll or '1' to start the game." << endl;
			cin >> check;
		}
		else if (check == 1)
			reroll = 0;
		else
			cout << "Please enter either '0' to reroll or '1' to start the game." << endl;
	}
}
