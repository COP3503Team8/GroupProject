#ifndef PRINT_h
#define PRINT_h

#include <iostream>

using namespace std;

public:
    void pauseMenu(){
        cout << "Player 1's Stats";
        printInventory();
        printPlayerStats();
    }

    void printPlayerStats(){
        cout << "Health: " << getCurrentUserHealth << "/" << getMaxHealth() << endl;
        cout << "Level: " << getLevel << endl;
    }


#endif
