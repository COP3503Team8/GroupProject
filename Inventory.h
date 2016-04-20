#ifndef INVENTORY_h
#define INVENTORY_h

#include "User.h"
#include <iostream>

using namespace std;

void printInventory(User* user){
    //Prints inventory contents
    int potions = 0;
    potions = user->getPotions();
    cout << "Inventory:" << endl;
    if (potions < 1){
      return;
    }
    else{
      cout << "Smokin' Notes COP3503 X " << i << ": Heals to full health" << endl;
    }
}

#endif
