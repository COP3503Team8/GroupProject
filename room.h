#ifndef room_h
#define room_h

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stdexcept>
#include <queue>

class Room {

protected:
	int* playerLoc;
	int ** map; //1 means a room is at the location, 2 means it's the end room
	std::vector<int *> monsterList;

public:
	void setPlayerX(int x) {
		playerLoc[0] = x;
	}
	void setPlayerY(int y) {
		playerLoc[1] = y;
	}
	bool virtual isBoss() {
		return false;
	}
	bool virtual atStairs() {
		return false;
	}
	void moveMonster(int* location) /*-1 will mean unvisited, -2 will mean invalid space */ 
	//returns 'l' for left, 'r' for right, 'd' for down, 'u' for up, and 's' for no movement
	{
		int** currRoom = map;
		int** roomCopy = new int*[22];
		for (int i = 0; i<22; i++) {
			roomCopy[i] = new int[22];
		}

		for (int i = 0; i < 22; i++)
		{
			for (int j = 0; j < 22; j++)
			{
				if (currRoom[i][j] == 1) {
					roomCopy[j][i] = -1;
				}
				else {
					roomCopy[j][i] = -2;
				}
			}
		}
		roomCopy[playerLoc[1]][playerLoc[0]] = 0;
		std::queue<int* > pathQueue;
		pathQueue.push(playerLoc);
		while (pathQueue.size() != 0) {
			int* curr = pathQueue.front();
			pathQueue.pop();



			if (curr[0] != 21) {
				if (roomCopy[curr[1]][curr[0] + 1] == -1) {
					roomCopy[curr[1]][curr[0] + 1] = roomCopy[curr[1]][curr[0]] + 1;
					int* tempIntArr = new int[2];
					tempIntArr[0] = curr[0]+1;
					tempIntArr[1] = curr[1];
					pathQueue.push(tempIntArr);
				}
				else if (roomCopy[curr[1]][curr[0]] + 1 < roomCopy[curr[1]][curr[0] + 1]) {
					roomCopy[curr[1]][curr[0] + 1] = roomCopy[curr[1]][curr[0]] + 1;
				}
			}


			if (curr[1] != 21) {
				if (roomCopy[curr[1]+1] [curr[0]] == -1) {
					roomCopy[curr[1]+1][curr[0]] = roomCopy[curr[1]][curr[0]] + 1;
					int* tempIntArr = new int[2];
					tempIntArr[0] = curr[0];
					tempIntArr[1] = curr[1] + 1;
					pathQueue.push(tempIntArr);
				}
				else if (roomCopy[curr[1]][curr[0]] + 1 < roomCopy[curr[1] + 1][curr[0]]) {
					roomCopy[curr[1]+1][curr[0]] = roomCopy[curr[1]][curr[0]] + 1;
				}
			}


			if (curr[0] != 0) {
				if (roomCopy[curr[1]][curr[0] - 1] == -1) {
					roomCopy[curr[1]][curr[0] - 1] = roomCopy[curr[1]][curr[0]] + 1;
					int* tempIntArr = new int[2];
					tempIntArr[0] = curr[0] - 1;
					tempIntArr[1] = curr[1];
					pathQueue.push(tempIntArr);
				}
				else if (roomCopy[curr[1]][curr[0]] + 1 < roomCopy[curr[1]][curr[0] - 1]) {
					roomCopy[curr[1]][curr[0] - 1] = roomCopy[curr[1]][curr[0]] + 1;
				}
			}

			if (curr[1] != 0) {
				if (roomCopy[curr[1]-1] [curr[0]] == -1) {
					roomCopy[curr[1]-1][curr[0]] = roomCopy[curr[1]][curr[0]] + 1;
					int* tempIntArr = new int[2];
					tempIntArr[0] = curr[0];
					tempIntArr[1] = curr[1] - 1;
					pathQueue.push(tempIntArr);
				}
				else if (roomCopy[curr[1]][curr[0]] + 1 < roomCopy[curr[1] - 1][curr[0]]) {
					roomCopy[curr[1]-1][curr[0]] = roomCopy[curr[1]][curr[0]] + 1;
				}
			}

		}



		int myDistance = roomCopy[location[1]][location[0]];
		int* tempIntArr;
		if ((location[0] != 0) && (roomCopy[location[1]][location[0]-1] < myDistance) && (roomCopy[location[1]][location[0]-1] >= 0)) {
			//return 'l';
			tempIntArr = new int[2];
			tempIntArr[0] = location[0] - 1;
			tempIntArr[1] = location[1];
			if (!isMonster(tempIntArr)) {
			location[0] -= 1;
			}
			delete[] tempIntArr;
		}
		else if ((location[1] != 0) && (roomCopy[location[1]-1][location[0]] < myDistance) && (roomCopy[location[1]-1][location[0]] >= 0)) {
			//return 'u';
			tempIntArr = new int[2];
			tempIntArr[0] = location[0];
			tempIntArr[1] = location[1] - 1;
			if (!isMonster(tempIntArr)) {
			location[1] -= 1;
			}
			delete[] tempIntArr;

		}
		else if ((location[0] != 21 ) && (roomCopy[location[1]][location[0]+1] < myDistance) && (roomCopy[location[1]][location[0]+1] >= 0 )) {
			//return 'r';
			tempIntArr = new int[2];
			tempIntArr[0] = location[0] + 1;
			tempIntArr[1] = location[1];
			if (!isMonster(tempIntArr)) {
			location[0] += 1;
			}
			delete[] tempIntArr;
		}
		else if ((location[0] != 21) && (roomCopy[location[1]+1][location[0]] < myDistance) && (roomCopy[location[1]+1][location[0]] >= 0)) {
			//return 'd';
						tempIntArr = new int[2];
			tempIntArr[0] = location[0];
			tempIntArr[1] = location[1] + 1;
			if (!isMonster(tempIntArr)) {
			location[1] += 1;
			}
			delete[] tempIntArr;
		}
		else {
					//return 's';
		}

		// 		for (int i = 0; i< 22; i++) {
		// 	for (int j = 0; j < 22; j++) {
		// 		std::cout << roomCopy[i][j] << " ";
		// 	}
		// 	std::cout << std::endl;
		// }
		// std::cout << std::endl;



	};

	void killMonster(int* coord) {
		for (unsigned int i = 0; i < monsterList.size(); i++) {
			if ((monsterList.at(i)[0] == coord[0]) && (monsterList.at(i)[1] == coord[1])) {
				monsterList.erase(monsterList.begin() + i);			}
		}		
	}

	void virtual moveAllMonsters() {
		for (unsigned int i = 0; i < monsterList.size(); i++) {
			moveMonster(monsterList.at(i));
		}
	}

	bool isMonster(int* coord) {
		bool out = false;
		for (unsigned int i = 0; i < monsterList.size(); i++) {
			if ((monsterList.at(i)[0] == coord[0]) && (monsterList.at(i)[1] == coord[1])) {
				out = true;
			}
		}
		return out;
	}

	bool playerAtMonster() {
		return isMonster(playerLoc);
	}


	void printMap() {

		for (int i = 1; i < 21; i++) {
			for (int j = 1; j < 21; j++) {
				bool isMonster = false;
				for (unsigned int k = 0; k < monsterList.size(); k++) {
					if ((monsterList.at(k)[0] == j) && (monsterList.at(k)[1] == i)) {
						isMonster = true;
					}
				}
				if ((playerLoc[0] == j) && (playerLoc[1] == i)) {
					std::cout << "X";
				}
				else if (isMonster) {
					std::cout << "!";
				}
				else if (map[j][i] == 1) {
					std::cout << " ";
				}
				else {
					std::cout<< "#";
				}
			}
			std::cout << std::endl;
		}
	}

	int* getPlayerLoc() {
		return playerLoc;
	}
	int** getMap() {
		return map;
	}
	void spawnPlayerAtDoor(int door) // 1 for top, -1 for bottom, 2 for right, -2 for left
	{
		if (door == 1) {
			playerLoc[0] = 11;
			playerLoc[1] = 2;
		}
		else if (door == -1) {
			playerLoc[0] = 11;
			playerLoc[1] = 19;
		}
		else if (door == 2) {
			playerLoc[0] = 19;
			playerLoc[1] = 11;
		}
		else if (door == -2) {
			playerLoc[0] = 2;
			playerLoc[1] = 11;
		}
		else {
			throw std::invalid_argument("can only spawn at doors");
		}

	}

	int atDoor() // 1 for top, -1 for bottom, 2 for right, -2 for left, 0 for false
	{
		if ((playerLoc[0] == 11) && (playerLoc[1] == 1)) {
			return 1;
		}
		else if ((playerLoc[0] == 11) && (playerLoc[1] == 20)) {
			return -1;
		}
		else if ((playerLoc[0] == 20) && (playerLoc[1] == 11)) {
			return 2;
		}
		else if ((playerLoc[0] == 1) && (playerLoc[1] == 11)) {
			return -2;
		}
		else {
			return 0;
		}
	}



	Room() {
		map = new int*[22];
		for (int i = 0; i<22; i++) {
			map[i] = new int[22];
			for (int j = 0; j < 22; j++) {
				map[i][j] = 0;
			}
		}
		map[11][11] = 1;
		for (int i = 1; i<21; i++) {
			map[11][i] = 1;
			map[i][11] = 1;
		}
		int roomsLeft = 200;
		while (roomsLeft > 0) {
			std::vector<int*> validRooms;
			for (int i = 2; i < 20; i++) {
				for (int j = 2; j < 20; j++) {
					int numAdj = 0;
					if (map[i][j] == 1) {
						continue;
					}
					if (map[i-1][j] == 1) {
						numAdj += 1;
					}
					if (map[i+1][j] == 1) {
						numAdj += 1;
					}
					if (map[i][j-1] == 1) {
						numAdj += 1;
					}
					if (map[i][j+1] == 1) {
						numAdj += 1;
					}
					if (numAdj > 0) {
						int *temp = new int[2];
						temp[0] = j;
						temp[1] = i;
						validRooms.push_back(temp);
					}


				}
			}
			if (validRooms.size() == 0) {
				map[10][10] = 1;
				break;
			}
			int* nextRoom = validRooms.at(rand() % validRooms.size());
			if (roomsLeft != 1) {
				map[nextRoom[1]][nextRoom[0]] = 1;
			}
			if (roomsLeft == 1) {
				map[nextRoom[1]][nextRoom[0]] = 1;

			}
			roomsLeft -= 1;
			for (unsigned int i = 0; i < validRooms.size(); i++) {
							delete[] validRooms.at(i);
						}
			validRooms.clear();
		}
		playerLoc = new int[2];
		playerLoc[0] = 11, playerLoc[1] = 11;


		int numMonsters = 5 + (rand() % 3);
		std::vector<int*> monsterLocations;
		while (numMonsters > 0) {
			numMonsters -= 1;
			for (int i = 3; i < 19; i++) {
				for (int j = 3; j < 19; j++) {
					if (map[j][i] == 1) {
						int* temploc = new int[2];
						temploc[0] = j;
						temploc[1] = i;
						monsterLocations.push_back(temploc);
					}
				}
			}
			int tempInt = rand() % monsterLocations.size();
			monsterList.push_back(monsterLocations.at(tempInt));
			monsterLocations.erase(monsterLocations.begin() + tempInt);
			for (unsigned int i = 0; i < monsterLocations.size(); i++) {
				delete[] monsterLocations.at(i);
			}
			monsterLocations.clear();
		}




	}


};



class BossRoom : public Room
{
public:
	BossRoom() {
		Room();
		int bossmap [22][22]= {
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
			{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
			{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
			{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
			{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
			{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
			{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
			{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
			{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
			{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
			{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
			{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
			{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
			{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
			{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
			{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
			{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
			{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
					};

			for (int i = 0; i < 22; i++) {
				for (int j = 0; j < 22; j++) {
					map[i][j] = bossmap[i][j];
				}
			}

			while (monsterList.size() > 0) {
				killMonster(monsterList.at(0));
			}
			int* bossLoc = new int[2];
			bossLoc[0] = 13;
			bossLoc[1] = 11;
			monsterList.push_back(bossLoc);

	}

	bool atStairs() {
		if ((playerLoc[0] == 11) && (playerLoc[1] == 11)) {
			return true;
		}
		else {
			return false;
		}

	}

	void moveAllMonsters() {
		return;
	}
	bool isBoss() {
		return true;
	}

	~BossRoom();
	
};




#endif
