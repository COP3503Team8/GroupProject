#ifndef PRINT_h
#define PRINT_h

#include <iostream>
#include "Inventory.h"

using namespace std;

void menu(User* user, int currentFloor){
    cout << "Current Floor: " << currentFloor << endl;
    cout << "Player 1's Stats";
    printPlayerStats(user);
    printInventory(user);
    }

void printPlayerStats(User* user){
    cout << "Health: " << user->getHealth() << "/" << user->getMaxHealth() << endl;
    cout << "Level: " << user->getLevel << endl;
    cout << "Needed EXP to Level Up: " << user->getNeededEXP() << endl;
}


#endif
