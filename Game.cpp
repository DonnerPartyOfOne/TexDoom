#include "Game.h"

int Game::start(vector<Room*>* list) {
	roomList = list;

	char playerName[255];

	// Game start
	cout << "Welcome to Tex Doom! blah blah blah" << endl;
	cout << "Please enter your character's name!" << endl;
	cin.getline(playerName,255);

	Player* player = new Player(playerName, 5, 5, 100, 5, 5);
	player->addWeapon(new Weapon("Pistol", 5));
	player->setCurrentWeapon(0);
	player->pickupItem(new Pickup("Slugs"));
	player->pickupItem(new Pickup("Slugs"));

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
			cout << "Invalid Command." << endl;
	}



	int playerLocation = 0;
	int target = 0;
	int playerTurn = 1;
	int choice = 0;
	bool advance = false;

	// Interaction
	while(playerLocation < roomList->size()) {
		bool roomSearched = false;
		while(!advance) {
			playerTurn = 1;
			if (player->isDead()) { // You're dead
				advance = true;
				cout << endl << "You have died!" << endl;
				cout << "Continue? (y/n)" << endl;
				char checker;
				cin >> checker;
				if (checker == 'y')
					return 1;
				else
					return 0;
			}
			else if (roomList->at(playerLocation)->getNumCharacters() == 0) { // Everything else is dead
				if (roomList->at(playerLocation)->getNumPickups() == 0 && roomList->at(playerLocation)->getNumWeapons() == 0) { // You picked everything up
					cout << endl << "You have cleared the room. Advancing to next room." << endl;
					advance = true;
				}
				else { // Still have stuff to pick up
					cout << endl << "You found items in this room!" << endl;
					roomList->at(playerLocation)->printPickups();
					roomList->at(playerLocation)->printWeapons();
					for(int i = 0; i < roomList->at(playerLocation)->getNumPickups(); i++){
						Pickup* pick = new Pickup(roomList->at(playerLocation)->getPickupList()->at(i)->getPickupName());
						player->pickupItem(pick);
						roomList->at(playerLocation)->removePickup(i);
					}
					for(int i = 0; i < roomList->at(playerLocation)->getNumWeapons(); i++){
						Weapon* wep = new Weapon(roomList->at(playerLocation)->getWeaponList()->at(i)->getWeaponName(), roomList->at(playerLocation)->getWeaponList()->at(i)->getWeaponPower());
						player->addWeapon(wep);
						roomList->at(playerLocation)->removeWeapon(i);
					}
				}
			}
			else { // Things are still alive
				while (playerTurn) {
					if (!roomSearched) { // Search option if room not searched yet
						cout << endl << "0) Quit" << endl <<
							"1) Backpack" << endl <<
							"2) Fight!" << endl <<
							"3) Search Room" << endl;
						cin >> choice;
					}
					// Remove option if room searched and nothing to pick up
					else if ( (roomSearched) && (roomList->at(playerLocation)->getNumPickups() == 0) && (roomList->at(playerLocation)->getNumWeapons() == 0) ) {
						cout << endl << "0) Quit" << endl <<
							"1) Backpack" << endl <<
							"2) Fight!" << endl;
						cin >> choice;
					}
					else { // Option to pick up items if room searched
						cout << endl << "0) Quit" << endl <<
							"1) Backpack" << endl <<
							"2) Fight!" << endl <<
							"3) Pickup Item" << endl;
						cin >> choice;
					}
					if (choice == 0) {
						cout << endl<< "Thank you for playing texDoom!" << endl;
						return 0;
					}
					else if (choice == 1) { // Backpack choice. Shows all current weapons and allows the user to equip a different weapon
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
						string weaponName = player->getCurrentWeapon()->getWeaponName();
						bool hasAmmo = true;

						if (weaponName == "Pistol") {
							if (player->getSlugs() < 1)
								hasAmmo = false;
						}
						else if (weaponName == "Chaingun") {
							if (player->getSlugs() < 5)
								hasAmmo = false;
						}
						else if (weaponName == "Shotgun") {
							if (player->getShells() < 1)
								hasAmmo = false;
						}
						else if (weaponName == "Super Shotgun") {
							if (player->getShells() < 2)
								hasAmmo = false;
						}
						else if (weaponName == "Rocket Launcher") {
							if (player->getRockets() < 1)
								hasAmmo = false;
						}
						else if (weaponName == "Plasma Rifle") {
							if (player->getPlasmaCells() < 5)
								hasAmmo = false;
						}
						else if (weaponName == "BFG 9000") {
							if (player->getPlasmaCells() < 60)
								hasAmmo = false;
						}
						else
							hasAmmo = false;

						if (hasAmmo) {
        	                       	                int target;
							cout << endl;
							roomList->at(playerLocation)->printCharacters();
							cout << "Your current health: " << player->getCurrentHitpoints() << endl;
							cout << "Choose a target (1, 2, 3, ... n)" << endl;
							cin >> target;

							roomList->at(playerLocation)->attack(1, player, target - 1);
							player->fire();
							if (roomList->at(playerLocation)->getCharacterList()->at(target - 1)->getCurrentHitpoints() <= 0) { // Check to see if target is dead
								cout << endl << "You killed " << roomList->at(playerLocation)->getCharacterList()->at(target - 1)->getCharacterName() << endl;
								roomList->at(playerLocation)->removeCharacter(target - 1);
							}
							else
								cout << endl << "You dealt " << player->getCurrentWeapon()->getWeaponPower() << " damage" << endl <<
								"Your target " << roomList->at(playerLocation)->getCharacterList()->at(target - 1)->getCharacterName() << "has" << roomList->at(playerLocation)->getCharacterList()->at(target - 1)->getCurrentHitpoints() << " hitpoints" << endl;
							playerTurn = 0; // Turn over
						}
						else
							cout << endl << "You do not have have enough ammo for your current weapon. Please switch weapons." << endl;
					}
					else if (choice == 3 && !roomSearched) { // Third choice if room isn't searched yet
						roomSearched = true;
						cout << endl << "Items and weapons in the room" << endl;
						roomList->at(playerLocation)->printPickups();
						roomList->at(playerLocation)->printWeapons();
						playerTurn = 0;
					}
					// Third choice but it isn't available
					else if (roomSearched && roomList->at(playerLocation)->getNumPickups() == 0 && roomList->at(playerLocation)->getNumWeapons() == 0) {
						cout << "Invalid Command" << endl;
					}
					else if (roomSearched && (choice == 3)) { // Pickup items
						int choice;
						if (roomList->at(playerLocation)->getNumWeapons() > 0 && roomList->at(playerLocation)->getNumPickups() > 0) { // Player chooses between an item or a weapon
							char type;
							cout << endl << "Weapons in room:" << endl;
							roomList->at(playerLocation)->printWeapons();

							cout << endl << "Items in room:" << endl;
							roomList->at(playerLocation)->printPickups();

							cout << "Would you like to pick up and item or a weapon? (w/i)" << endl;
							cin >> type;

							if (type == 'w') { // Choose a weapon
								cout << "Choose a weapon to pick up (1, 2, 3, ... n)" << endl;
       	       	                                                cin >> choice;
               	                                                Weapon* wep = new Weapon(roomList->at(playerLocation)->getWeaponList()->at(choice - 1)->getWeaponName(), roomList->at(playerLocation)->getWeaponList()->at(choice - 1)->getWeaponPower());
               	              	                                player->addWeapon(wep);
                       	                                        roomList->at(playerLocation)->removeWeapon(choice);
					  			playerTurn = 0;
							}
							else if (type == 'i') { // Choose an item
								cout << "Choose an item to pick up (1, 2, 3, ... n)" << endl;
                                      		 	        cin >> choice;
                          		                        Pickup* pick = new Pickup(roomList->at(playerLocation)->getPickupList()->at(choice - 1)->getPickupName());
                     		                	        player->pickupItem(pick);
                	                               		roomList->at(playerLocation)->removePickup(choice - 1);
								playerTurn = 0;
							}
							else { // Invalid command
								cout << "Invalid Command" << endl;
								playerTurn = 1;
							}
						}
						else if (roomList->at(playerLocation)->getNumPickups() > 0) { // Only items in room, choose an item
							cout << "Items in room:" << endl;
							roomList->at(playerLocation)->printPickups();
							cout << "Choose an item to pick up (1, 2, 3, ... n)" << endl;
							cin >> choice;
							Pickup* pick = new Pickup(roomList->at(playerLocation)->getPickupList()->at(choice - 1)->getPickupName());
							player->pickupItem(pick);
							roomList->at(playerLocation)->removePickup(choice - 1);
							playerTurn = 0;
						}
						else if (roomList->at(playerLocation)->getNumWeapons() > 0) { // Only weapons in room, choose a weapon
							cout << "Weapons in room:" << endl;
							roomList->at(playerLocation)->printWeapons();
							cout << "Choose a weapon to pick up (1, 2, 3, ... n)" << endl;
							cin >> choice;
							Weapon* wep = new Weapon(roomList->at(playerLocation)->getWeaponList()->at(choice - 1)->getWeaponName(), roomList->at(playerLocation)->getWeaponList()->at(choice - 1)->getWeaponPower());
							player->addWeapon(wep);
							roomList->at(playerLocation)->removeWeapon(choice - 1);
							playerTurn = 0;
						}
					}
					else { // Bad command
						cout << "Invalid Command" << endl;
						playerTurn = 1;
					}
				}

				// Monster attacks
				for (int i = 0; i < roomList->at(playerLocation)->getNumCharacters() && !(player->isDead()); i++) {
					roomList->at(playerLocation)->attack(0, player, i);
					if (player->getCurrentHitpoints() <= 0)
						player->kill();
					else
						cout << endl << roomList->at(playerLocation)->getCharacterList()->at(i)->getCharacterName() << "dealt " << roomList->at(playerLocation)->getCharacterList()->at(i)->getPower() << " damage to you" << endl;
				}
				cout << "Your current health: " << player->getCurrentHitpoints() << endl;
			}
		}
		playerLocation ++;
	}
}
