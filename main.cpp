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
	player->addWeapon(new Weapon("Pistol", 5));
	player->setCurrentWeapon(0);

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
		else {
			cout << "Please enter either '0' to reroll or '1' to start the game." << endl;
			cin >> check;
		}
	}



	int playerLocation = 0;
	int target = 0;
	int playerTurn = 1;
	int choice = 0;
	bool advance = false;

	// Interaction
	while(playerLocation < roomList.size()) {
		bool roomSearched = false;
		while(!advance) {
			playerTurn = 1;
			if (player->isDead()) { // You're dead
				advance = true;
				cout << endl << "You have died!" << endl;
			}
			else if (roomList[playerLocation]->getNumCharacters() == 0) { // Everything else is dead
				if (roomList[playerLocation]->getNumPickups() == 0 && roomList[playerLocation]->getNumWeapons() == 0) { // You picked everything up
					cout << endl << "You have cleared the room. Advancing to next room." << endl;
					advance = true;
				}
				else { // Still have stuff to pick up
					cout << endl << "You found items in this room!" << endl;
					roomList[playerLocation]->printPickups();
					roomList[playerLocation]->printWeapons();
					for(int i = 0; i < roomList[playerLocation]->getNumPickups(); i++){
						Pickup* pick = new Pickup(roomList[playerLocation]->getPickupList()->at(i)->getPickupName());
						player->pickupItem(pick);
						roomList[playerLocation]->removePickup(i);
					}
					for(int i = 0; i < roomList[playerLocation]->getNumWeapons(); i++){
						Weapon* wep = new Weapon(roomList[playerLocation]->getWeaponList()->at(i)->getWeaponName(), roomList[playerLocation]->getWeaponList()->at(i)->getWeaponPower());
						player->addWeapon(wep);
						roomList[playerLocation]->removeWeapon(i);

					}
				}
			}
			else { // Things are still alive
				while (playerTurn) {
					if (!roomSearched) { // Search option if room not searched yet
						cout << endl << "1) Backpack" << endl <<
							"2) Fight!" << endl <<
							"3) Search Room" << endl;
						cin >> choice;
					}
					// Remove option if room searched and nothing to pick up
					else if ((roomSearched) && (roomList[playerLocation]->getNumPickups() == 0) && (roomList[playerLocation]->getNumWeapons() == 0)) {
						cout << endl << "1) Backpack" << endl <<
							"2) Fight!" << endl;
						cin >> choice;
					}
					else { // Option to pick up items if room searched
						cout << endl << "1) Backpack" << endl <<
							"2) Fight!" << endl <<
							"3) Pickup Item" << endl;
						cin >> choice;
					}

					if (choice == 1) { // Backpack choice. Shows all current weapons and allows the user to equip a different weapon
						int weapon;
						char change;
						cout << endl << "Backpack:" << endl;
						player->printWeaponList();
						cout << endl << "Current Weapon: " << player->getCurrentWeapon()->getWeaponName() << endl;
						cout << "Would you like to equip a different weapon? (y/n)" << endl;
						cin >> change;
						if (change == 'y') {
							cout << "Choose a new weapon (1, 2, 3, ... n)" << endl;
							cin >> weapon;
							player->setCurrentWeapon(weapon - 1);
						}
					}
                                        else if (choice == 2) { // Fight choice
                                                int target;
						cout << endl;
						roomList[playerLocation]->printCharacters();
						cout << "Your current health: " << player->getCurrentHitpoints() << endl;
						cout << "Choose a target (1, 2, 3, ... n)" << endl;
						cin >> target;

						roomList[playerLocation]->attack(1, player, target - 1);
						if (roomList[playerLocation]->getCharacterList()->at(target - 1)->getCurrentHitpoints() <= 0) { // Check to see if target is dead
							cout << endl << "You killed " << roomList[playerLocation]->getCharacterList()->at(target - 1)->getCharacterName() << endl;
							roomList[playerLocation]->removeCharacter(target - 1);
						}
						else
							cout << endl << "You dealt " << player->getCurrentWeapon()->getWeaponPower() << " damage" << endl;
						playerTurn = 0; // Turn over
					}
					else if (choice == 3 && !roomSearched) { // Third choice if room isn't searched yet
						roomSearched = true;
						cout << endl << "Items and weapons in the room" << endl;
						roomList[playerLocation]->printPickups();
						roomList[playerLocation]->printWeapons();
						playerTurn = 0;
					}
					// Third choice but it isn't available
					else if (roomSearched && roomList[playerLocation]->getNumPickups() == 0 && roomList[playerLocation]->getNumWeapons() == 0) {
						cout << "Invalid Command" << endl;
					}
					else if (roomSearched && (choice == 3)) { // Pickup items
						int choice;
						if (roomList[playerLocation]->getNumWeapons() > 0 && roomList[playerLocation]->getNumPickups() > 0) { // Player chooses between an item or a weapon
							char type;
							cout << endl << "Weapons in room:" << endl;
							roomList[playerLocation]->printWeapons();

							cout << endl << "Items in room:" << endl;
							roomList[playerLocation]->printPickups();

							cout << "Would you like to pick up and item or a weapon? (w/i)" << endl;
							cin >> type;

							if (type == 'w') { // Choose a weapon
								cout << "Choose a weapon to pick up (1, 2, 3, ... n)" << endl;
        	                                                cin >> choice;
	                                                        Weapon* wep = new Weapon(roomList[playerLocation]->getWeaponList()->at(choice - 1)->getWeaponName(), roomList[playerLocation]->getWeaponList()->at(choice - 1)->getWeaponPower());
                	                                        player->addWeapon(wep);
                        	                                roomList[playerLocation]->removeWeapon(choice);
							}
							else if (type == 'i') { // Choose an item
								cout << "Choose an item to pick up (1, 2, 3, ... n)" << endl;
                                        	                cin >> choice;
                                	                        Pickup* pick = new Pickup(roomList[playerLocation]->getPickupList()->at(choice - 1)->getPickupName());
                       		                                player->pickupItem(pick);
                	                                        roomList[playerLocation]->removePickup(choice - 1);
							}
							else // Invalid command
								cout << "Invalid Command" << endl;
							playerTurn = 0;
						}
						else if (roomList[playerLocation]->getNumPickups() > 0) { // Only items in room, choose an item
							cout << "Items in room:" << endl;
							roomList[playerLocation]->printPickups();
							cout << "Choose an item to pick up (1, 2, 3, ... n)" << endl;
							cin >> choice;
							Pickup* pick = new Pickup(roomList[playerLocation]->getPickupList()->at(choice - 1)->getPickupName());
							player->pickupItem(pick);
							roomList[playerLocation]->removePickup(choice - 1);
						}
						else if (roomList[playerLocation]->getNumWeapons() > 0) { // Only weapons in room, choose a weapon
							cout << "Weapons in room:" << endl;
							roomList[playerLocation]->printWeapons();
							cout << "Choose a weapon to pick up (1, 2, 3, ... n)" << endl;
							cin >> choice;
							Weapon* wep = new Weapon(roomList[playerLocation]->getWeaponList()->at(choice - 1)->getWeaponName(), roomList[playerLocation]->getWeaponList()->at(choice - 1)->getWeaponPower());
							player->addWeapon(wep);
							roomList[playerLocation]->removeWeapon(choice - 1);
						}
					}
					else { // Bad command
						cout << "Invalid Command" << endl;
					}
				}

				// Monster attacks
				for (int i = 0; i < roomList[playerLocation]->getNumCharacters() && !(player->isDead()); i++) {
					roomList[playerLocation]->attack(0, player, i);
					if (player->getCurrentHitpoints() <= 0)
						player->kill();
					else
						cout << endl << roomList[playerLocation]->getCharacterList()->at(i)->getCharacterName() << "dealt " << roomList[playerLocation]->getCharacterList()->at(i)->getPower() << " damage to you" << endl;
				}
				cout << "Your current health: " << player->getCurrentHitpoints() << endl;
			}
		}
		playerLocation ++;
	}
}
