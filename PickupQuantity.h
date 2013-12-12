#include <string>
#include "Pickup.h"

using namespace std;

class PickupQuantity: public Pickup {
	public:
		PickupQuantity(string m_pickupName = "", int m_amount = 0)
			: Pickup(m_pickupName),
				amount(m_amount)
		{
		}

		int getAmount();
	private:
		int amount;
};

