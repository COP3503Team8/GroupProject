#ifndef INVENTORY_h
#define INVENTORY_h

#include "User.h"
#include <iostream>

using namespace std;

void printInventory(User* user){
    int potions = 0;
    potions = user->getPotions();
    cout << "Inventory:" << endl;
    for(int i = 1; i <= potions; i++){
        cout << "Smokin' Notes COP3503 " << i << ": Heals to full health" << endl;
    }
}

#endif
