#include <string>

using namespace std;

class Character {
	public:
		Character(string m_name = "", int m_agi = 0, int m_acc = 0, int m_max = 0, bool m_dead = false)
			: characterName(m_name), agility(m_agi), accuracy(m_acc), maxHitpoints(m_max), dead(m_dead)
		{
		}

		int getAgility();
		int getAccuracy();
		int getCurrentHitpoints();

		string getCharacterName();

		bool isDead();
		void kill();
	protected:
		int agility;
		int accuracy;
		int maxHitpoints;
		int currentHitpoints;

		string characterName;

		bool dead;
};
