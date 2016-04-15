#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stdexcept>


class Floor {
private:
	int* playerLoc;
	int ** map; //1 means a room is at the location, 2 means it's the end room
public:
	~Floor() {
		delete[] playerLoc;
		for (int i = 0; i < 20; i++) {
			delete[] map[i];
		}
		delete[] map;

	}
	void changeRoom(char dir) //takes in 'u', 'd', 'l', 'r' 
	{
		if (dir == 'u') {
			if (map[playerLoc[1]-1][playerLoc[0]] == 1) {
				playerLoc[1] -= 1;
			}
		}
		else if (dir == 'd') {
			if (map[playerLoc[1]+1][playerLoc[0]] == 1) {
				playerLoc[1] += 1;
			}
		}
		else if (dir == 'l') {
			if (map[playerLoc[1]][playerLoc[0]-1] == 1) {
				playerLoc[0] -= 1;
			}
		}
		else if (dir == 'r') {
			if (map[playerLoc[1]][playerLoc[0]+1] == 1) {
				playerLoc[0] += 1;
			}
		}
		else {
			throw std::invalid_argument("changeRoom must take u,d,l,r");
		}
	}

	void printMap() {

		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				if (map[i][j] == 0) {
					std::cout << " ";
				}
				else if ((i == playerLoc[1]) && (j == playerLoc[0])) {
					std::cout << "x";
				}
				else if (map[i][j] == 2) {
					std::cout << "E";
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
	Floor(int floorNum) {
		srand(time(0));
		map = new int*[20];
		for (int i = 0; i<20; i++) {
			map[i] = new int[20];
			for (int j = 0; j < 20; j++) {
				map[i][j] = 0;
			}
		}
		map[10][10] = 1;
		int roomsLeft = floorNum * 10;
		while (roomsLeft > 0) {
			std::vector<int*> validRooms;
			for (int i = 1; i < 19; i++) {
				for (int j = 1; j < 19; j++) {
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
					if (numAdj == 1) {
						int *temp = new int[2];
						temp[0] = j;
						temp[1] = i;
						validRooms.push_back(temp);
					}


				}
			}
			if (validRooms.size() == 0) {
				map[10][10] = 2;
				break;
			}
			int* nextRoom = validRooms.at(rand() % validRooms.size());

			map[nextRoom[1]][nextRoom[0]] = 1;
			if (roomsLeft == 1) {
				map[nextRoom[1]][nextRoom[0]] = 2;

			}
			roomsLeft -= 1;
			for (int i = 0; i < validRooms.size(); i++) {
							delete[] validRooms.at(i);
						}
			validRooms.clear();
		}
		playerLoc = new int[2];
		playerLoc[0] = 10, playerLoc[1] = 10;
	}
};
