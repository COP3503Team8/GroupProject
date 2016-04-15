#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Print.h"
#include "User.h"
//include moving library

using namespace std;

int main() {
    srand(time(NULL));
    User* player = new User();
    int floorNum = 1;
    char dir;
    
    while (floorNum <= 6 && (player->getHealth() != 0)) {
        Floor* currFloor = new Floor(floorNum);
        while (true && (player->getHealth() != 0)) {
            currFloor->getCurrRoom()->printRoom();
            cin>>dir;
            
            //input validation
            player->move(dir, currFloor);
            if (player->getLocation() == /*enemy location*/) {
                battle(player, floorNum, /*enemy type*/);
            }
            for (each enemy in currFloor->currRoom->getEnemies()) {
                enemy->move(currRoom); }
            if (at a door) {
                move(dir);
            }
            if (atStairs){
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
