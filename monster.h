#include <queue>
#include <stdexcept>

//currRoomLoc is the [x,y] for the current room
// currRoom is the array for the current room


class Monster {
private:
	int* location;
	bool isMonsterAlive;
public:
	Monster(int* loc) {
		if (loc.size() != 2) {
			throw std::invalid_argument("Invalid spawn input");
		}
		if ((loc[0] < 0 || loc[0] > currRoom.size()) || loc[1] < 0 || loc[1] > currRoom.size()) {
			throw std::invalid_argument("Invalid starting location");
		}
		else if (currRoom[loc[1][loc[0]] != 0) {
			throw std::invalid_argument("Generating on rock");
		}
		else {
			location = loc;
			isMonsterAlive = true;
		}
	};
	bool isAlive() {
		return isMonsterAlive;
	}

	int* getLocation() {
		return location;
	};

	void move() {
		char dir = this->calculateMovingDirection();
		if (dir == 'u') {
			location[1] -= 1;
		}
		else if (dir == 'd') {
			location[1] += 1;
		}
		else if (dir == 'l') {
			location[0] -= 1;
		}
		else if (dir == 'r') {
			location[0] += 1;
		}

	}




	char calculateMovingDirection(RoomGen* inputRoom) /*-1 will mean unvisited, -2 will mean invalid space */ 
	//returns 'l' for left, 'r' for right, 'd' for down, 'u' for up, and 's' for no movement
	{
		currRoom = inputRoom->getMap();
		int roomCopy [currRoom.size()][currRoom[0].size()];
		for (int i = 0; i < currRoom.size(); i++)
		{
			for (int j = 0; j < currRoom[0].size(); j++)
			{
				if (currRoom[i][j] == ' ') {
					roomCopy[i][j] = -1;
				}
				else {
					roomCopy[i][j] = -2;
				}
			}
		}
		playerLoc = currRoom.getPlayerLocation();
		roomCopy[playerLoc[1]][playerLoc[0]] = 0;
		std::queue<int* > pathQueue;
		pathQueue.push(playerLoc);
		while (pathQueue.size() != 0) {
			int* curr = pathQueue.pop();



			if (curr[0] != roomCopy[0].size()-1) {
				if (roomCopy[curr[1]][curr[0] + 1] == -1) {
					roomCopy[curr[1]][curr[0] + 1] = roomCopy[curr[1]][curr[0]] + 1
					pathQueue.push({curr[0]+1, curr[1]})
				}
				else if (roomCopy[curr[1]][curr[0]] + 1 < roomCopy[curr[1]][curr[0] + 1]) {
					roomCopy[curr[1]][curr[0] + 1] = roomCopy[curr[1]][curr[0]] + 1;
				}
			}


			if (curr[1] != roomCopy.size()-1) {
				if (roomCopy[curr[1]+1] [curr[0]] == -1) {
					roomCopy[curr[1]+1][curr[0]] = roomCopy[curr[1]][curr[0]] + 1
					pathQueue.push({curr[0], curr[1]+1})
				}
				else if (roomCopy[curr[1]][curr[0]] + 1 < roomCopy[curr[1] + 1][curr[0]]) {
					roomCopy[curr[1]+1][curr[0]] = roomCopy[curr[1]][curr[0]] + 1;
				}
			}


			if (curr[0] != 0) {
				if (roomCopy[curr[1]][curr[0] - 1] == -1) {
					roomCopy[curr[1]][curr[0] - 1] = roomCopy[curr[1]][curr[0]] + 1
					toAdd
					pathQueue.push({curr[0]-1, curr[1]})
				}
				else if (roomCopy[curr[1]][curr[0]] + 1 < roomCopy[curr[1]][curr[0] - 1]) {
					roomCopy[curr[1]][curr[0] - 1] = roomCopy[curr[1]][curr[0]] + 1;
				}
			}

			if (curr[1] != 0) {
				if (roomCopy[curr[1]-1] [curr[0]] == -1) {
					roomCopy[curr[1]-1][curr[0]] = roomCopy[curr[1]][curr[0]] + 1
					pathQueue.push({curr[0], curr[1] - 1})
				}
				else if (roomCopy[curr[1]][curr[0]] + 1 < roomCopy[curr[1] - 1][curr[0]]) {
					roomCopy[curr[0]][curr[1]-1] = roomCopy[curr[1]][curr[0]] + 1;
				}
			}

		}

		myDistance = roomCopy[location[1]][location[0]];
		if ((location[0] != 0) && (roomCopy[location[1]][location[0]-1] < myDistance)) {
			return 'l';
		}
		else if ((location[1] != 0) && (roomCopy[location[1]-1][location[0]] < myDistance)) {
			return 'u';
		}
		else if ((location[0] != roomCopy[0].size() -1 ) && (roomCopy[location[1]][location[0]+1] < myDistance)) {
			return 'r';
		}
		else if ((location[0] != roomCopy.size() -1) && (roomCopy[location[1]+1][location[0]] < myDistance)) {
			return 'd';
		}
		else {
			return 's';
		}



	};
}
