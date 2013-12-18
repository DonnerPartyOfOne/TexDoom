#include "Game.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

vector<Room*>* parser(char* filename) {
	string line;
	vector<Room*>* roomList = new vector<Room*>();
	ifstream myfile(filename);
	int roomIndex = 0;
	if(myfile.is_open()){
		while(getline(myfile, line)){
			roomIndex++;
			roomList->push_back(new Room(roomIndex));
			for(int i = 0; i < line.size(); i = i+4){
				string currentitem = line.substr(i,3);
				int currentitemquantity = line[i+3]-'0';

				if(currentitem == "FHP"){
					for(int j = 0; j < currentitemquantity; j++)
						roomList->back()->addCharacter(new Character("Former Human Private", 1,6,20,5));
				}
				else if (currentitem == "FHS"){
					for(int j = 0; j < currentitemquantity; j++)
                                                roomList->back()->addCharacter(new Character("Former Human Sergeant",1,4,30,10));
                                }
				else if (currentitem ==  "IMP"){
					 for(int j = 0; j < currentitemquantity; j++)
                                                roomList->back()->addCharacter(new Character("Imp",2,2,40,20));
                                }
				else if (currentitem == "DEM"){
					for(int j = 0; j < currentitemquantity; j++)
                                                roomList->back()->addCharacter(new Character("Demon",5,1,50,10));
				}
				else if (currentitem == "CAC"){
                                        for(int j = 0; j < currentitemquantity; j++)
                                                roomList->back()->addCharacter(new Character("Cacodemon",2,2,70,30));
				}
				else if (currentitem == "LOS"){
                                        for(int j = 0; j < currentitemquantity; j++)
                                                roomList->back()->addCharacter(new Character("Lost Soul",8,7,5,5));
                                }
				else if (currentitem == "BOH"){
                                        for(int j = 0; j < currentitemquantity; j++)
                                                roomList->back()->addCharacter(new Character("Baron of Hell",5,4,200,30));
                                }
				else if (currentitem == "HWG"){
                                        for(int j = 0; j < currentitemquantity; j++)
                                                roomList->back()->addCharacter(new Character("Heavy Weapon Guy",2,3,30,30));
                                }
				else if (currentitem == "HEL"){
                                        for(int j = 0; j < currentitemquantity; j++)
                                                roomList->back()->addCharacter(new Character("Hell Knight",5,4,100,30));
                                }
				else if (currentitem == "REV"){
                                        for(int j = 0; j < currentitemquantity; j++)
                                                roomList->back()->addCharacter(new Character("Revenant",8,4,100,50));
                                }
				else if (currentitem == "MAN"){
                                        for(int j = 0; j < currentitemquantity; j++)
                                                roomList->back()->addCharacter(new Character("Mancubus",1,4,100,40));
                                }
				else if (currentitem == "ARA"){
                                        for(int j = 0; j < currentitemquantity; j++)
                                                roomList->back()->addCharacter(new Character("Arachnotron",3,6,100,20));
                                }
				else if (currentitem == "ARC"){
                                        for(int j = 0; j < currentitemquantity; j++)
                                                roomList->back()->addCharacter(new Character("Arch-Vile",8,8,100,60));
                                }
				else if (currentitem == "CYB"){
                                        for(int j = 0; j < currentitemquantity; j++)
                                                roomList->back()->addCharacter(new Character("Cyberdemon",5,5,1000,60));
                                }
				else if (currentitem == "HPT"){
                                        for(int j = 0; j < currentitemquantity; j++)
                                                roomList->back()->addPickup(new Pickup("HP+10"));
                                }
				else if (currentitem == "HPH"){
                                        for(int j = 0; j < currentitemquantity; j++)
                                                roomList->back()->addPickup(new Pickup("HP+100"));
                                }
				else if (currentitem == "HPO"){
                                        for(int j = 0; j < currentitemquantity; j++)
                                                roomList->back()->addPickup(new Pickup("HP+1"));
                                }
				else if (currentitem == "ARH"){
                                        for(int j = 0; j < currentitemquantity; j++)
                                                roomList->back()->addPickup(new Pickup("Armor+100"));
                                }
				else if (currentitem == "ARO"){
                                        for(int j = 0; j < currentitemquantity; j++)
                                                roomList->back()->addPickup(new Pickup("Armor+1"));
                                }
				else if (currentitem == "AMP"){
                                        for(int j = 0; j < currentitemquantity; j++)
                                                roomList->back()->addPickup(new Pickup("Slugs"));
                                }
				else if (currentitem == "AMS"){
                                        for(int j = 0; j < currentitemquantity; j++)
                                                roomList->back()->addPickup(new Pickup("Shotgun Shells"));
                                }
				else if (currentitem == "AMR"){
                                        for(int j = 0; j < currentitemquantity; j++)
                                                roomList->back()->addPickup(new Pickup("Rockets"));
                                }
				else if (currentitem == "AMC"){
                                        for(int j = 0; j < currentitemquantity; j++)
                                                roomList->back()->addPickup(new Pickup("Plasma Cells"));
                                }
				else if (currentitem =="PST"){
                                         for(int j = 0; j < currentitemquantity; j++)
                                                roomList->back()->addWeapon(new Weapon("Pistol", 5));
                                }
				else if (currentitem =="SHO"){
					 for(int j = 0; j < currentitemquantity; j++)
						roomList->back()->addWeapon(new Weapon("Shotgun", 20));
				}
				else if (currentitem == "SSH"){
					 for(int j = 0; j < currentitemquantity; j++)
						roomList->back()->addWeapon(new Weapon("Super Shotgun", 50));
				}
				else if (currentitem =="CHA"){
                                         for(int j = 0; j < currentitemquantity; j++)
                                                roomList->back()->addWeapon(new Weapon("Chainsaw", 30));
                                }
				else if (currentitem =="CHG"){
                                         for(int j = 0; j < currentitemquantity; j++)
                                                roomList->back()->addWeapon(new Weapon("Chaingun", 20));
                                }
				else if (currentitem =="ROC"){
                                         for(int j = 0; j < currentitemquantity; j++)
                                                roomList->back()->addWeapon(new Weapon("Rocket Launcher", 70));
                                }
				else if (currentitem =="PLS"){
                                         for(int j = 0; j < currentitemquantity; j++)
                                                roomList->back()->addWeapon(new Weapon("Plasma Rifle", 40));
                                }
				else if (currentitem =="BFG"){
                                         for(int j = 0; j < currentitemquantity; j++)
                                                roomList->back()->addWeapon(new Weapon("BFG 9000", 100));
                                }
				else  cout << "something in the wad is undefined";
			}
		}
	}
	return roomList;
}

int main(int argc, char* argv[]) {
	char* filename;
	int run = 1;

	filename = argv[1];
	Game game;
	while(run)
		run = game.start(parser(filename));
}
