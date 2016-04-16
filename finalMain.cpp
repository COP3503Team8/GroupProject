#include <iostream>
#include "room.h"
#include "User.h"
#include "floor.h"
#include "BattleClass.h"
#include "Print.h"

int main() {
	User* player = new User();
    int floorNum = 1;
    char dir;
    
    while (floorNum <= 6) {
        Floor* currFloor = new Floor(floorNum);
        while (true) {
            currFloor->getCurrRoom()->printMap();
            std::cin>>dir;
            
            //input validation
            if(dir == 'q') {
                menu(player, currFloor);
                continue;
            }

            player->move(dir, currFloor->getCurrRoom()->getMap());
            currFloor->getCurrRoom()->setPlayerX(player->getXLocation());
            currFloor->getCurrRoom()->setPlayerY(player->getYLocation());


            currFloor->getCurrRoom()->moveAllMonsters();

            if (currFloor->getCurrRoom()->playerAtMonster()) {
                battle(player, floorNum, currFloor->getCurrRoom()->isBoss());
            }

            int door = currFloor->getCurrRoom()->atDoor();
            if (door != 0) {
            	currFloor->changeRoom(door);
            	currFloor->getCurrRoom()->spawnPlayerAtDoor(-1*door);
            	int* tempPlayerLoc = currFloor->getCurrRoom()->getPlayerLoc();
            	player->setLocation(tempPlayerLoc[0], tempPlayerLoc[1])
            }
            if (currFloor->getCurrRoom()->atStairs()) {
            	floorNum += 1;
            	break;
            }
            

            
        }
    }
    
    return 0;
}
}
