#ifndef PRINT_h
#define PRINT_h

#include <iostream>
#include "Inventory.h"

using namespace std;

void printPlayerStats(User* user){
    //Print player's stats
    cout << "Harrison's Stats" << endl;
    cout << "Health: " << user->getHealth() << "/" << user->getMaxHealth() << endl;
    cout << "Level: " << user->getLevel() << endl;
    cout << "Needed EXP to Level Up: " << user->getNeededEXP() << endl;
}

void menu(User* user, int currentFloor){
    //Prints pause menu
    cout << "Current Floor: " << currentFloor << endl;
    printPlayerStats(user);
    printInventory(user);
    cout << "Enter 'q' to close" << endl;
    cout << "Enter 'z' to quit" << endl;
    }

void clearScreen(){
  //Clears screen with new lines
  cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
}

void printStory(){
  //Prints intro story to screen
  cout << "The Legend of Liu" << endl << endl << "There once was a student named Harrison who had trouble in COP3503.\nThe only way he would be able to pass the course would be to fight Dr. Liu in a one-on-one programming battle.\nHarrison decided to embark on the journey to Dr. Liu's office to confront him one and for all.\nOn his way, he encountered the ghosts of Liu's past, failed student, who were determined to make him one of them.\nGuarding each entrance to the next floor were numerous authorities such as the TAs and the advisors.\nWith packets of Smokin' Notes in hand, can Harrison succeed in taking down the almighty Liu?" << endl << endl;
  cout << "Enter in any key to continue." << endl;
}

#endif
