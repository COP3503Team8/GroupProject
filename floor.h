#ifndef floor_h
#define floor_h

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <stdexcept>
#include "room.h"


class Floor {
	struct roomWithCoords{
		int* coords;
		Room* room;
		roomWithCoords(int x, int y, Room* roomToAdd) {
			room = roomToAdd;
			coords = new int[2];
			coords[0] = x;
			coords[1] = y;

		}
	};
private:
	int* playerLoc;
	int ** map; //1 means a room is at the location, 2 means it's the end room
	std::vector<roomWithCoords*> roomList;
public:
	~Floor() {
		delete[] playerLoc;
		for (int i = 0; i < 20; i++) {
			delete[] map[i];
		}
		delete[] map;

	}

	Room* getCurrRoom() {
		for (int i = 0; i < roomList.size(); i++) {
			if ((roomList.at(i)->coords[0] == playerLoc[0]) && (roomList.at(i)->coords[1] == playerLoc[1])) {
				return (roomList.at(i)->room);
			}
		}

		throw std::logic_error("no Current Room?");
	}

	void changeRoom(int dir) //// 1 for up, -1 for down, 2 for right, -2 for left
	{
		if (dir == 1) {
			if (map[playerLoc[1]-1][playerLoc[0]] == 1) {
				playerLoc[1] -= 1;
			}
		}
		else if (dir == -1) {
			if (map[playerLoc[1]+1][playerLoc[0]] == 1) {
				playerLoc[1] += 1;
			}
		}
		else if (dir == -2) {
			if (map[playerLoc[1]][playerLoc[0]-1] == 1) {
				playerLoc[0] -= 1;
			}
		}
		else if (dir == 2) {
			if (map[playerLoc[1]][playerLoc[0]+1] == 1) {
				playerLoc[0] += 1;
			}
		}
		else {
			throw std::invalid_argument("changeRoom must take -2,-1,1,2");
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
				Room* tempRoom = new BossRoom();
				roomList.push_back(new roomWithCoords(10, 10, tempRoom));

				break;
			}
			int* nextRoom = validRooms.at(rand() % validRooms.size());
			if (roomsLeft != 1) {
				map[nextRoom[1]][nextRoom[0]] = 1;
				Room* tempRoom= new Room();
				roomList.push_back(new roomWithCoords(nextRoom[0], nextRoom[1], tempRoom));

			}
			if (roomsLeft == 1) {
				map[nextRoom[1]][nextRoom[0]] = 2;
				Room* tempRoom = new BossRoom();
				roomList.push_back(new roomWithCoords(nextRoom[0], nextRoom[1], tempRoom));

			}
			roomsLeft -= 1;
			for (unsigned int i = 0; i < validRooms.size(); i++) {
							delete[] validRooms.at(i);
						}
			validRooms.clear();
		}
		playerLoc = new int[2];
		playerLoc[0] = 10, playerLoc[1] = 10;
	}
};

#endif
