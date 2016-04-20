#include <iostream>
#include "room.h"
#include "User.h"
#include "floor.h"
#include "BattleClass.h"
#include "Print.h"
#include "cheat.h"

int main() {
	//Clear screen
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
	//Seed time for random generation	
	srand(time(0));
	User* player = new User();
	int floorNum = 1;
	char dir;
	bool cheat = false;
	bool godmode = false;

	while (floorNum <= 4) {
		Floor* currFloor = new Floor(floorNum);
		while (true) {
			if (player->getHealth() < 1) {
				std::cout << "YOU LOSE!!!" << std::endl;
				return 0;
			}
			currFloor->getCurrRoom()->printMap();
			std::cin>>dir;

			//input validation
			if(dir == 'q') {
				std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
				menu(player, floorNum);
				while (true) {
					std::cin >> dir;
					if (dir == 'q') {
						std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
						break;
					}
					cin.clear();
					cin.ignore(1024, '\n');
				}
				continue;
			}

			else if (dir == 'e') {
				std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
				currFloor->printMap();
				while (true) {
					std::cin >> dir;
					if (dir == 'e') {
						std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
						break;
					}
					cin.clear();
					cin.ignore(1024, '\n');
				}
				continue;
			}
			else if (dir == '/'){
				cheat = toggle(cheat);
				std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
				(cheat) ? (std::cout << "Cheats enabled" << endl) : (std::cout << "Cheats disabled" << endl);
				continue;
			}
			else if(dir == 'p' && cheat){
				player->setHealth(player->getMaxHealth());
				godmode = toggle(godmode);
				std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
				(godmode) ? (std::cout << "Godmode enabled" << endl) : (std::cout << "Godmode disabled" << endl);
				continue;
			}
			else if (dir != 'w' && dir != 'a' && dir != 's' && dir != 'd' && dir != 'f' && !cheat){
				std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
				std::cout << "Invalid input!" << endl;
				cin.clear();
				cin.ignore(1024, '\n');
				continue;
			}
			if(godmode && cheat){
				player->setHealth(player->getMaxHealth());
			}
			player->move(dir, currFloor->getCurrRoom()->getMap());
			currFloor->getCurrRoom()->setPlayerX(player->getXLocation());
			currFloor->getCurrRoom()->setPlayerY(player->getYLocation());
			currFloor->getCurrRoom()->moveAllMonsters();
			if (currFloor->getCurrRoom()->playerAtMonster()) {
				Battle newBattle;
				newBattle.battleScreen(player, player->getLevel(), floorNum, currFloor->getCurrRoom()->isBoss());
				currFloor->getCurrRoom()->killMonster(currFloor->getCurrRoom()->getPlayerLoc());
				continue;
			}

			int door = currFloor->getCurrRoom()->atDoor();
			if (door != 0) {
				if (currFloor->changeRoom(door)) {
					currFloor->getCurrRoom()->spawnPlayerAtDoor(-1*door);
				}
				int* tempPlayerLoc = currFloor->getCurrRoom()->getPlayerLoc();
				player->setLocation(tempPlayerLoc[0], tempPlayerLoc[1]);
			}
			if (currFloor->getCurrRoom()->atStairs()) {
				floorNum += 1;
				break;
			}
			std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
		}
	}
	std::cout << "Congratulations!!! You won!!!" << std::endl;

	return 0;
}
