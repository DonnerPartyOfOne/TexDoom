#include <string>

using namespace std;

class Character {
	public:
		Character(string m_name = "", int m_agi = 0, int m_acc = 0, int m_current = 0, int m_power = 0, bool m_dead = false)
			: characterName(m_name), power(m_power), agility(m_agi), accuracy(m_acc), currentHitpoints(m_current), dead(m_dead)
		{
		}

		int getPower();
		int getAgility();
		int getAccuracy();
		int getCurrentHitpoints();
		void subtractHitpoints(int);
		string getCharacterName();

		bool isDead();
		void kill();
	protected:
		int power;
		int agility;
		int accuracy;
		int currentHitpoints;

		string characterName;

		bool dead;
};
