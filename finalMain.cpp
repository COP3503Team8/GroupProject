#include <iostream>
#include "room.h"
#include "User.h"
#include "floor.h"
#include "BattleClass.h"
#include "Print.h"

int main() {
	srand(time(0));
	User* player = new User();
    int floorNum = 1;
    char dir;
    
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
                menu(player, floorNum);
                while (true) {
                    std::cin >> dir;
                    if (dir == 'q') {
                        break;
                    }
                }
                continue;
            }
            
            if (dir == 'e') {
				currFloor->printMap();
                while (true) {
                    std::cin >> dir;
                    if (dir == 'e') {
                        break;
                    }
                }
		continue;
			}

            player->move(dir, currFloor->getCurrRoom()->getMap());
            currFloor->getCurrRoom()->setPlayerX(player->getXLocation());
            currFloor->getCurrRoom()->setPlayerY(player->getYLocation());


            currFloor->getCurrRoom()->moveAllMonsters();

            if (currFloor->getCurrRoom()->playerAtMonster()) {
				Battle newBattle;
                newBattle.battleScreen(player, player->getLevel(), floorNum, currFloor->getCurrRoom()->isBoss());
                currFloor->getCurrRoom()->killMonster(currFloor->getCurrRoom()->getPlayerLoc());
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
            

           std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl; 
        }
    }
    std::cout << "Congratulations!!! You won!!!" << std::endl;
    
    return 0;
}

