#include <string>
#include <iostream>
#include <vector>
#include "Character.h"
#include "Weapon.h"
using namespace std;

class Player: public Character {
	public:
		Player(string m_name = "", int m_agi =0, int m_acc = 0, int m_current = 0, int m_perception = 0, int m_melee = 0,
			 int m_slugs = 0, int m_shells = 0, int m_rockets = 0, int m_plasmaCells = 0, bool m_dead = false)
			: Character(m_name, m_agi, m_acc, m_current, m_dead),
				perception(m_perception), melee(m_melee), slugs(m_slugs), shells(m_shells),
				rockets(m_rockets), plasmaCells(m_plasmaCells)
		{
		}

		int getPerception();
		int getMelee();
		int getSlugs();
		int getShells();
		int getRockets();
		int getPlasmaCells();

		void addWeapon(Weapon*);

		void addSlugs(int);
		void addShells(int);
		void addRockets(int);
		void addPlasmaCells(int);

		void setAgility(int);
		void setAccuracy(int);
		void setMelee(int);
		void setCurrentHitpoints(int);
		void setArmourRating(int);

		void rerollStats();
		void printStats();

		Weapon* getCurrentWeapon();
		void setCurrentWeapon(int);
	private:
		vector<Weapon*> weaponList;
		Weapon* currentWeapon;

		int armourRating;
		int perception;
		int melee;

		int slugs; // Pistol/Chaingun
		int shells; // Shotty/Super Shotty
		int rockets; // Roket Launcher
		int plasmaCells; // Rifle/BFG
};



