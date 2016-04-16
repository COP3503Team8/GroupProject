#ifndef BATTLECLASS_h
#define BATTLECLASS_h

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "User.h"
#include "Print.h"

using namespace std;

//Blah


class Battle
{
    
public:
    bool inBattle;//tells whether or not player is still in battle
    string battleChoice;
    int attackChance;
    int runChance;
    int damageDone;
    int baseDamage;
    int enemyHealth;
    
    Battle()
    {
        bool inBattle = true;
        string battleChoice;
        int attackChance = 0;
        int runChance = 0;
        int damageDone = 0;
        int baseDamage = 5;
        int enemyHealth = 0;
        
    }
    
    void battleScreen(int userLevel, int floorNum, char enemyType)
    {
        cout<<"You have encountered an enemy!"<<endl;
        createEnemy(floorNum, enemyType);
        inBattle = true;
        while(inBattle)
        {
            cout<<"You are in battle"<<endl;
            cout<<"1. Attack"<<endl;
            cout<<"2. Use Potion"<<endl;
            cout<<"3. Display Stats"<<endl;
            cout<<"4. Run"<<endl;
            cout<<"Choice: ";
            cin>>battleChoice;
            cout<<endl;
            if(battleChoice.compare("1") != 0 && battleChoice.compare("2") != 0 && battleChoice.compare("3") != 0 && battleChoice.compare("4") != 0)
            {
                //checks if the given input is a valid battle choice
                cout<<"Not an option!"<<endl;
                cout<<endl;
            }
            else if(battleChoice.compare("1") == 0)
            {
                //The user will attack the enemy and the enemy will have a chance to attack the user back
                userAttack(userLevel);
                enemyAttack(floorNum, enemyType);
            }
            else if(battleChoice.compare("2") == 0)
            {
                //The user uses a potion which brings them to full health
                cout<<"You chose use potion"<<endl;
                //all use a potion fucntion from mihcael and then gives the enemy a chance to attack you
            }
            else if(battleChoice.compare("3") == 0)
            {
                //displays stats from Willa and then gives user a chance to move again
            }
            else if(battleChoice.compare("4") == 0)
            {
                //attempts to run, if it works the battle ends and if not the enemy can attack
                run();
            }
            if(!inBattle)
            {
                //if the enemy was a regular enemy it will have a 10% chance of dropping a potion (call potion increment from Michael)
                //if the enemy is a boss it will always drop a potion (call potion increments potion from Michael)
                cout<<endl;
                cout<<"Battle over!!"<<endl;
                /*if(user.getCurrentHealth() == 0)
                 {
                 cout<<"You Lose!!"<<endl;
                 }
                 */
                return;
            }
            battleChoice = "0";
        }
    }
    
    //"creates" the enemy which the user is battling by givng it a set amount of health based on floor and char type
    void createEnemy(int floorNum, char enemyType)
    {
        if(enemyType == '!')
        {
            enemyHealth = (floorNum * 10);
        }
        else if(enemyType == 'B')
        {
            enemyHealth = (floorNum * 20)
        }
        else
        {
            cout<<"Invalid enemy type!"<<endl;
            return;
        }
        
    }
    
    void userDamage(int userLevel)
    {
        damageDone = baseDamage + (rand () % (5 + userLevel)) + userLevel;
        enemyHealth = enemyHealth - damageDone;
    }
    
    void userAttack(int userLevel)
    {
        attackChance = (rand () % 10) + 1;
        if(attackChance == 1)
        {
            cout<<"Your attack missed!!"<<endl;
            cout<<endl;
        }
        else if(attackChance == 10)
        {
            //if attack is 10 it does critical damage to target(damage is run on target twice)
            cout<<"Critical hit!!"<<endl;
            userDamage(userLevel);
            userDamage(userLevel);
        }
        else
        {
            //does regular damage to the target if the attack is 2-9
            cout<<"Your attack hit!"<<endl;
            userDamage(userLevel);
        }
    }
    
    void enemyDamage(int floorNum, char enemyType)
    {
        if(enemyType = '!')
        {
            damageDone = baseDamage + (rand () % (3 + floorNum)) + floorNum;
            //set user health to be (currentUserHealth - damageDone) from Michael
        }
        if(enemyType = 'B')
        {
            damageDone = baseDamage + (rand () % (6 + floorNum)) + floorNum;
            //set user health to be (curentUserHealth - damageDone) from Michael
        }
    }
    
    void enemyAttack(int floorNum, char enemyType)
    {
        attackChance = (rand () % 10) + 1;
        if(attackChance == 1)
        {
            cout<<"The enemy's attack missed!"<<endl;
        }
        else if(attackChance == 10)
        {
            //if attack chance is 10 it does critical damage to the user(damage is run twice)
            cout<<"Critical hit!"<<endl;
            enemyDamage(floorNum, enemyType);
            enemyDamage(floorNum, enemyType);
        }
        else
        {
            //does regular damage to the user
            cout<<"Your enemy's attack hit!"<<endl;
            enemyDamage(floorNum, enemyType);
        }
    }
    
    
    void UsePotion()
    {
        player->UsePotion();
    }
    
    
    void displayStats()
    {
        printPlayerStats(player);
    }
    
    void run()
    {
        runChance = (rand () %  5) + 1;
        if(runChance == 1)
        {
            inBattle = 0;
            cout<<"You ran away succesfully!"<<endl;
        }
        else
        {
            cout<<"You were unable to run away!"<<endl;
            cout<<endl;
        }
        runChance = 0;
    }
};

#endif
