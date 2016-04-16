#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "Battleclass.h"
#include "floor.h"
#include "monster.h"
#include "Print.h"
#include "User.h"
//include moving library

using namespace std;

bool locationsMatch(User* player, vector<Monster> monsters){
    bool match = false;
    for(int i = 0; i < monsters.size(); i++){
        if(monsters[i]->getLocation == player.getLocation()){ //locations need to be matched up (either monster needs to return X coordinate and Y coordinate or player needs to return a pointer to an array
            match = true;
        }
    }
    return match;
}

int main() {
    srand(time(NULL));
    User* player = new User();
    int floorNum = 1;
    char dir;
    Battle* battlePointer = new Battle();
    
    while (floorNum <= 6 && (player->getHealth() != 0)) {
        Floor* currFloor = new Floor(floorNum);
        while (true && (player->getHealth() != 0)) {
            currFloor->getCurrRoom()->printRoom(); //ANDREW
            vector<Monster> monsters = currFloor->getMonsters(); //Correct call?
            cin>>dir;
            
            //input validation
            player->move(dir, currFloor);
            if (locationsMatch(player, monsters)) {
                //need a function to tell if it is end room (boss) or not
                battlePointer->battleScreen(player, floorNum, /*enemy type*/);
            }
            for (each enemy in currFloor->currRoom->getEnemies()) {
                enemy->move(currRoom);
            }
            if (at a door) { //ANDREW
                move(dir);
            }
            if (atStairs){ //maybe make this automatic after the boss is defeated?
                floorNum += 1;
                break;
            }
            if(dir == q) {
                menu(player, floorNum);
            }
        }
    }
    
    cout << "Game Over" << endl;
    
    if(floorNum == 6 && (player->getHealth() != 0)){
        cout << "You Win!!!! YAYYYYYY!!!! (Now play again)";
    }
    return 0;
}
