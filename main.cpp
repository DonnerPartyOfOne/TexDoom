#include "Pickup.cpp"
#include "PickupQuantity.cpp"
#include "Player.cpp"
#include "Character.cpp"
#include "Weapon.cpp"
#include <list>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
	string line;
	int lineNum;
	char* filename;

	// WAD Parsing Code
	filename = argv[1];
	ifstream myfile(filename);
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
		}
	}
}
