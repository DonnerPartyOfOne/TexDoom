#include <string>
#include <iostream>
#include <list>
#include "Character.h"

using namespace std;

class Player: public Character {
	public:
		Player(string m_name = "", int m_agi =0, int m_acc = 0, int m_max = 0, bool m_dead = false,
		       int m_perception = 0, int m_melee = 0, int m_slugs = 0, int m_shells = 0,
		       int m_rockets = 0, int m_plasmaCells = 0)
			: Character(m_name, m_agi, m_acc, m_max, m_dead),
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

		void setAgility(int);
		void setAccuracy(int);
		void setMelee(int);
		void setCurrentHitpoints(int);
		void setMaxHitpoints(int);
		void setArmourRating(int);

		void rerollStats();
		void printStats();
	private:
		int armourRating;
		int perception;
		int melee;

		int slugs; // Pistol/Chaingun
		int shells; // Shotty/Super Shotty
		int rockets; // Roket Launcher
		int plasmaCells; // Rifle/BFG
};


