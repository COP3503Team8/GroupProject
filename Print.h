#ifndef PRINT_h
#define PRINT_h

#include <iostream>
#include "Inventory.h"

using namespace std;

void printPlayerStats(User* user){
    cout << "Player 1's Stats";
    cout << "Health: " << user->getHealth() << "/" << user->getMaxHealth() << endl;
    cout << "Level: " << user->getLevel() << endl;
    cout << "Needed EXP to Level Up: " << user->getNeededEXP() << endl;

void menu(User* user, int currentFloor){
    cout << "Current Floor: " << currentFloor << endl;
    printPlayerStats(user);
    printInventory(user);
    }

}


#endif
