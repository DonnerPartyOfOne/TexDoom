#include <string>

using namespace std;

class Pickup {
	public:
		Pickup(string m_pickupName = "", bool m_pickedUp = false)
			: pickupName(m_pickupName), pickedUp(m_pickedUp)
		{
		}

		string getPickupName();
		bool isPickedUp();
		void pickupItem();
	protected:
		string pickupName;
		bool pickedUp;
};

