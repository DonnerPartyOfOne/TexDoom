#include "Room.h"
#include <vector>
#include <iostream>
#include <fstream>

class Game {
	public:
		Game() {}
		int start(vector<Room*>*);
	private:
		vector<Room*>* roomList;
};
