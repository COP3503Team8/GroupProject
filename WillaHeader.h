//Michelle Qu
//Section Number: 19F2

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <locale>

using namespace std;


#ifndef WILLAHEADER_h
#define WILLAHEADER_h

namespace willa_functions{
    public:
        void pauseMenu(){
            //clearScreen();
            //cout << getPlayerName() << "'s Menu:" << end;
            printInventory();
            printPlayerStats();
        }
        void printPlayerStats(){
            //cout << "Health: " << getCurrentUserHealth << "/" << getMaxHealth() << endl;
            //cout << "Level: " << getLevel << endl;
            //cout << "Attack: " << getAttack << endl;
            //defense?
        }
        void printInventory(){
            //string[] items = getItems(); gets name of items
            int freeSpace = 10; //arbitrary number for now
            //for(int i = 0; i < (int)(items.size()); i++){
                //if(items[i].exists){
                    //cout << items[i].getName() << "\t"; //make a boolean function to check if there is an item there
                    //freeSpace--;
                //}
                //else if(i == 4 || i == 9){
                    //cout << endl;
                //}
            //}
            //cout << "Free space: " << freeSpace << endl;
                
            //insert code for dropping an item
        }
}

#endif
