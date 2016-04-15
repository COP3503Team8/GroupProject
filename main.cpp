#include<iostream>
//and other stuff

int main() {
    user* player = new User();
    int floorNum = 1;
    char dir;
    
    while (floorNum <= 6) {
        Floor* currFloor = newFloor(floorNum);
        while (true) {
            currFloor->getCurrRoom()->printRoom();
            std::cin>>dir;
            
            //input validation
            player->move(dir);
            if (player->getLocation() == /*enemy location*/) {
                battle(player, floorNum, /*enemy type*/);
            }
            for (each enemy in currFloor->currRoom->getEnemies()) {
                enemy->move(currRoom); }
            if (at a door) {
                move(dir);
            }
            if (at stairs) break;
            florNum += 1;
            break;
            
            if(dir == q) {
                openMenu(player, currFloor);
            }
            
        }
    }
    
    return 0;
}
