#include "Room.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

vector<Room*> parser(char* filename) {
	string line;
	vector<Room*> roomList;
	ifstream myfile(filename);
	int roomIndex = 0;

	if(myfile.is_open()){
		while(getline(myfile, line)){
			roomIndex++;
			roomList.push_back(new Room(roomIndex));
			for(int i = 0; i < line.size(); i = i+4){
				string currentitem = line.substr(i,3);
				int currentitemquantity = line[i+3]-'0';

				if(currentitem == "FHP"){
					for(int j = 0; j < currentitemquantity; j++)
						roomList.back()->addCharacter(new Character("Former Human Private", 1,6,20,5));
				}
				else if (currentitem == "FHS"){
					for(int j = 0; j < currentitemquantity; j++)
                                                roomList.back()->addCharacter(new Character("Former Human Sergeant",1,4,30,10));
                                }
				else if (currentitem ==  "IMP"){
					 for(int j = 0; j < currentitemquantity; j++)
                                                roomList.back()->addCharacter(new Character("Imp",2,2,40,20));
                                }
				else if (currentitem == "DEM"){
					for(int j = 0; j < currentitemquantity; j++)
                                                roomList.back()->addCharacter(new Character("Demon",5,1,50,10));
				}
				else if (currentitem == "CAC"){
                                        for(int j = 0; j < currentitemquantity; j++)
                                                roomList.back()->addCharacter(new Character("Cacodemon",2,2,70,30));
				}
				else if (currentitem == "LOS"){
                                        for(int j = 0; j < currentitemquantity; j++)
                                                roomList.back()->addCharacter(new Character("Lost Soul",8,7,5,5));
                                }
				else if (currentitem == "BOH"){
                                        for(int j = 0; j < currentitemquantity; j++)
                                                roomList.back()->addCharacter(new Character("Baron of Hell",5,4,200,30));
                                }
				else if (currentitem == "HWG"){
                                        for(int j = 0; j < currentitemquantity; j++)
                                                roomList.back()->addCharacter(new Character("Heavy Weapon Guy",2,3,30,30));
                                }
				else if (currentitem == "HEL"){
                                        for(int j = 0; j < currentitemquantity; j++)
                                                roomList.back()->addCharacter(new Character("Hell Knight",5,4,100,30));
                                }
				else if (currentitem == "REV"){
                                        for(int j = 0; j < currentitemquantity; j++)
                                                roomList.back()->addCharacter(new Character("Revenant",8,4,100,50));
                                }
				else if (currentitem == "MAN"){
                                        for(int j = 0; j < currentitemquantity; j++)
                                                roomList.back()->addCharacter(new Character("Mancubus",1,4,100,40));
                                }
				else if (currentitem == "ARA"){
                                        for(int j = 0; j < currentitemquantity; j++)
                                                roomList.back()->addCharacter(new Character("Arachnotron",3,6,100,20));
                                }
				else if (currentitem == "ARC"){
                                        for(int j = 0; j < currentitemquantity; j++)
                                                roomList.back()->addCharacter(new Character("Arch-Vile",8,8,100,60));
                                }
				else if (currentitem == "CYB"){
                                        for(int j = 0; j < currentitemquantity; j++)
                                                roomList.back()->addCharacter(new Character("Cyberdemon",5,5,1000,60));
                                }
				else if (currentitem == "HPT"){
                                        for(int j = 0; j < currentitemquantity; j++)
                                                roomList.back()->addPickup(new Pickup("HP+10"));
                                }
				else if (currentitem == "HPH"){
                                        for(int j = 0; j < currentitemquantity; j++)
                                                roomList.back()->addPickup(new Pickup("HP+100"));
                                }
				else if (currentitem == "HPO"){
                                        for(int j = 0; j < currentitemquantity; j++)
                                                roomList.back()->addPickup(new Pickup("HP+1"));
                                }
				else if (currentitem == "ARH"){
                                        for(int j = 0; j < currentitemquantity; j++)
                                                roomList.back()->addPickup(new Pickup("Armor+100"));
                                }
				else if (currentitem == "ARO"){
                                        for(int j = 0; j < currentitemquantity; j++)
                                                roomList.back()->addPickup(new Pickup("Armor+1"));
                                }
				else if (currentitem == "AMP"){
                                        for(int j = 0; j < currentitemquantity; j++)
                                                roomList.back()->addPickup(new Pickup("Slugs"));
                                }
				else if (currentitem == "AMS"){
                                        for(int j = 0; j < currentitemquantity; j++)
                                                roomList.back()->addPickup(new Pickup("Shotgun Shells"));
                                }
				else if (currentitem == "AMR"){
                                        for(int j = 0; j < currentitemquantity; j++)
                                                roomList.back()->addPickup(new Pickup("Rockets"));
                                }
				else if (currentitem == "AMC"){
                                        for(int j = 0; j < currentitemquantity; j++)
                                                roomList.back()->addPickup(new Pickup("Plasma Cells"));
                                }
				else if (currentitem == "BER"){
					 for(int j = 0; j < currentitemquantity; j++)
						roomList.back()->addPickup(new Pickup("Berserker"));
				}
				else if (currentitem == "VIS"){
					 for(int j = 0; j < currentitemquantity; j++)
						roomList.back()->addPickup(new Pickup("Invisibility"));
				}
				else if (currentitem == "INV"){
                                        for(int j = 0; j < currentitemquantity; j++)
                                                roomList.back()->addPickup(new Pickup("Invincibility"));
                                }
				else if (currentitem =="PST"){
                                         for(int j = 0; j < currentitemquantity; j++)
                                                roomList.back()->addWeapon(new Weapon("Pistol", 5));
                                }
				else if (currentitem =="SHO"){
					 for(int j = 0; j < currentitemquantity; j++)
						roomList.back()->addWeapon(new Weapon("Shotgun", 20));
				}
				else if (currentitem == "SSH"){
					 for(int j = 0; j < currentitemquantity; j++)
						roomList.back()->addWeapon(new Weapon("Super Shotgun", 50));
				}
				else if (currentitem =="CHA"){
                                         for(int j = 0; j < currentitemquantity; j++)
                                                roomList.back()->addWeapon(new Weapon("Chainsaw", 30));
                                }
				else if (currentitem =="CHG"){
                                         for(int j = 0; j < currentitemquantity; j++)
                                                roomList.back()->addWeapon(new Weapon("Chaingun", 20));
                                }
				else if (currentitem =="ROC"){
                                         for(int j = 0; j < currentitemquantity; j++)
                                                roomList.back()->addWeapon(new Weapon("Rocket Launcher", 70));
                                }
				else if (currentitem =="PLS"){
                                         for(int j = 0; j < currentitemquantity; j++)
                                                roomList.back()->addWeapon(new Weapon("Plasma Rifle", 40));
                                }
				else if (currentitem =="BFG"){
                                         for(int j = 0; j < currentitemquantity; j++)
                                                roomList.back()->addWeapon(new Weapon("BFG 9000", 100));
                                }
				else  cout << "something in the wad is undefined";
			}
		}
	}
	return roomList;
}

int main(int argc, char* argv[]) {
	string line;
	int lineNum;
	int numRooms;
	char* filename;
	vector<Room*> roomList;

	// WAD Parsing Code
	filename = argv[1];
	roomList = parser(filename);

	char playerName[255];

	// Game start
	cout << "Welcome to Tex Doom! blah blah blah" << endl;
	cout << "Please enter your character's name!" << endl;
	cin.getline(playerName,255);

	Player* player = new Player(playerName, 5, 5, 100, 5, 5);


	cout << "Description of all player stats and current values blah blah" << endl;
	player->rerollStats();
	player->printStats();


	int reroll = 1;
	int check;

	// Query user for reroll
	while (reroll) {
		cout << "Type '0' to reroll or '1' to start the game." << endl;
		cin >> check;
		if (check == 0) {
			player->rerollStats();
			player->printStats();
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
	//while(playerLocation < roomList.size()) {
		//while(!advance) {
			// Show visible items and monsters
			cout << "Choose a weapon to pick up" << endl;
			roomList[playerLocation]->printWeapons();
			cin >> target;

			Weapon* currentWeapon = roomList[playerLocation]->getWeapon(target - 1);
			player->addWeapon(new Weapon(currentWeapon->getWeaponName(), currentWeapon->getWeaponPower()));
			roomList[playerLocation]->removeWeapon(target - 1);

			player->setCurrentWeapon(0);

			cout << player->getCurrentWeapon()->getWeaponName() << endl;

			cout << "Choose a pickup to pick up" << endl;
			roomList[playerLocation]->printPickups();
			cin >> target;

			roomList[playerLocation]->removePickup(target - 1);
			roomList[playerLocation]->printPickups();

			// Allow player to grab item or select target
			cout << "Choose a target (1-n)" << endl;
			roomList[playerLocation]->printCharacters();
			cin >> target;

			if ((target > 0) && (target <= roomList[playerLocation]->getNumCharacters())) {}
				roomList[playerLocation]->attack(1, player, target - 1);

			roomList[playerLocation]->printCharacters();

			// Monster attacks
			roomList[playerLocation]->attack(0, player, 0);
			cout << player->getCurrentHitpoints() << endl;
		//}
	//}
}
