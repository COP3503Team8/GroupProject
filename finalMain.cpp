#include <iostream>
#include "room.h"
#include "User.h"
#include "floor.h"
#include "BattleClass.h"
#include "Print.h"
#include "cheat.h"

int main() {
	//Declare and initilize variables
	User* player = new User();
	int floorNum = 1;
	char dir;
	bool cheat = false;
	bool godmode = false;
	//Clear screen
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
	//Seed time for random generation
	srand(time(0));
	//Begin game
	while (floorNum <= 4) {
		//Generate new floor. Game should only have 4 floors.
		Floor* currFloor = new Floor(floorNum);
		while (true) {
			//Check if player is still alive
			if (player->getHealth() < 1) {
				return 0;
			}
			//Print map
			currFloor->getCurrRoom()->printMap();
			//Receive input
			std::cin>>dir;
			//Read input for menu, minimap, and cheat input
			if(dir == 'q') {
				//Print menu and wait for user to hit 'q' again to close
				std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
				menu(player, floorNum);
				while (true) {
					std::cin >> dir;
					if (dir == 'q') {
						//Close menu
						std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
						break;
					}
					else if (dir == 'z'){
						std::cout << "Are you sure? Y/N" << endl;
						while(true){
							std::cin >> dir;
							if(dir == 'Y' || dir == 'y'){
								return 0;
							}
							else if(dir == 'N' || dir == 'n'){
								std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
								menu(player, floorNum);
								break;
							}
							cin.clear();
							cin.ignore(1024, '\n');
						}
					}
					cin.clear();
					cin.ignore(1024, '\n');
				}
				continue;
			}
			else if (dir == 'e') {
				//Open minimap and wait for user to hit 'e' again to close
				std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
				currFloor->printMap();
				std::cout << "Enter 'e' to close" << endl;
				while (true) {
					std::cin >> dir;
					if (dir == 'e') {
						//Close minimap
						std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
						break;
					}
					cin.clear();
					cin.ignore(1024, '\n');
				}
				continue;
			}
			else if (dir == '/'){
				//Toggle cheats
				cheat = toggle(cheat);
				std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
				(cheat) ? (std::cout << "Cheats enabled" << endl) : (std::cout << "Cheats disabled" << endl);
				continue;
			}
			else if(dir == 'p' && cheat){
				//Toggles godmode
				player->setHealth(player->getMaxHealth());
				godmode = toggle(godmode);
				std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
				(godmode) ? (std::cout << "Godmode enabled" << endl) : (std::cout << "Godmode disabled" << endl);
				continue;
			}
			else if (dir != 'w' && dir != 'a' && dir != 's' && dir != 'd' && dir != 'f' && !cheat){
				//Tell user invalid input was received
				std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
				std::cout << "Invalid input!" << endl;
				cin.clear();
				cin.ignore(1024, '\n');
				continue;
			}
			if(godmode && cheat){
				//Restore health if godmode and cheats are on
				player->setHealth(player->getMaxHealth());
			}
			//Changes players location based on direction moved
			player->move(dir, currFloor->getCurrRoom()->getMap());
			//Sync player location with floor's knowledge of player location
			currFloor->getCurrRoom()->setPlayerX(player->getXLocation());
			currFloor->getCurrRoom()->setPlayerY(player->getYLocation());
			//Move monsters
			currFloor->getCurrRoom()->moveAllMonsters();
			if (currFloor->getCurrRoom()->playerAtMonster()) {
				//Initiate battle if player runs into monster
				std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
				cin.clear();
				cin.ignore(1024, '\n');
				Battle newBattle;
				newBattle.battleScreen(player, player->getLevel(), floorNum, currFloor->getCurrRoom()->isBoss(), cheat, godmode);
				currFloor->getCurrRoom()->killMonster(currFloor->getCurrRoom()->getPlayerLoc());
				continue;
			}
			//Check if player is at door
			int door = currFloor->getCurrRoom()->atDoor();
			//Change room if player is at door
			if (door != 0) {
				//Check if door leads to new room. Change room and move player to opposite door if it does.
				if (currFloor->changeRoom(door)) {
					currFloor->getCurrRoom()->spawnPlayerAtDoor(-1*door);
				}
				int* tempPlayerLoc = currFloor->getCurrRoom()->getPlayerLoc();
				player->setLocation(tempPlayerLoc[0], tempPlayerLoc[1]);
			}
			if (currFloor->getCurrRoom()->atStairs()) {
				//Check if player is at stairs. Go up a floor if they are.
				floorNum += 1;
				break;
			}
			//Clear screen
			std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
		}
	}
	//Print victory message
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
	std::cout << "Congratulations!!! You won!!!" << std::endl;

	return 0;
}
