#ifndef BATTLECLASS_H
#define BATTLECLASS_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "User.h"
#include "Print.h"
#include "Inventory.h"

using namespace std;


class Battle
{

public:
	bool inBattle;//tells whether or not player is still in battle
	string battleChoice;//The choice the user makes in the battle menu
	int attackChance;//tells whether or not the user's attack hits
	int runChance;//tells whether the user successfully runs away from battle or not
	int damageDone;//calculates the damage an attack does
	int baseDamage;//the base amount of damage all attacks do
	int enemyHealth;//the health of the enemy based on their floor and type
	int tempUserHealth;//used to help manipulate the the user's health
	int potionChance;//tells whether or not the user gets a potion from winning a battle
	bool ranAway; //tells whether the play had run away

	Battle()
	{
		inBattle = true;
		attackChance = 0;
		runChance = 0;
		damageDone = 0;
		baseDamage = 5;
		enemyHealth = 0;
		tempUserHealth = 0;
		potionChance = 0;

	}

		void battleScreen(User* user, int userLevel, int floorNum, bool enemyType, bool cheat, bool godmode)
	{
		if(floorNum == 4){
			printLiu();
		}
		if(!enemyType){
			//Print out message for ordinary enemy
			cout<<"You have encountered an enemy!"<<endl << endl;
		}
		else{
			//Print out bosses
			if(floorNum == 1){
				cout<<"You must beat Fatemeh!"<<endl<<endl;
			}
			else if(floorNum == 2){
				cout<<"You must beat Julian!"<<endl<<endl;
			}
			else if(floorNum == 3){
				cout<<"You must beat Todd Best!" <<endl<<endl;
			}
			else if(floorNum == 4){
				cout<<"You must defeat the almighty Liu!!!"<<endl<<endl;
			}
		}
		//Initiate battle
		createEnemy(floorNum, enemyType);
		inBattle = true;
		while(inBattle)
		{
			//The menu shown to the user while they are in battle
			cout<<"You are in battle"<<endl;
			cout<<"1. Attack"<<endl;
			cout<<"2. Use Smokin' Notes"<<endl;
			cout<<"3. Display Stats"<<endl;
			cout<<"4. Run"<<endl;
			cout<<"Choice: ";
			cin>>battleChoice;
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
			if(battleChoice.compare("1") != 0 && battleChoice.compare("2") != 0 && battleChoice.compare("3") != 0 && battleChoice.compare("4") != 0)
			{
				//checks if the given input is a valid battle choice
				cout<<"Not an option!"<<endl;
				cout<<endl;
			}
			else if(battleChoice.compare("1") == 0)
			{
				//The user will attack the enemy and the enemy will have a chance to attack the user back if it's still alive
				userAttack(userLevel);
				if(enemyHealth > 0)
				{
					//if the user's attack doesn't kill the enemy the enemy can attack back
					enemyAttack(user, floorNum, enemyType);
					if(user->getHealth() <= 0)
					{
						//if the enemy's attack kills the user the battle is over
						inBattle = false;
					}
				}
				else
				{
					//if the user's attack kills the enemy the nattle is over
					inBattle = false;
				}
			}
			else if(battleChoice.compare("2") == 0)
			{
				//The user uses a potion which brings them to full health and then gives the enemy a chance to attack
				if (!user->hasPotion()){
					cout << "You don't have any Smokin' Notes!" << endl << endl;
				}
				else if(user->getHealth() == user->getMaxHealth()){
					cout << "You already have full health!" << endl << endl;
				}
				else{
					UsePotion(user);
					cout << "Your Smokin' Notes have restored your strength!" << endl;
					enemyAttack(user, floorNum, enemyType);
					if(user->getHealth() <= 0)
					{
						//if the enemy's attack kills the user the battle is over
						inBattle = false;
					}
				}
			}
			else if(battleChoice.compare("3") == 0)
			{
				//displays user stats and then gives the user a chance to attack again
				displayStats(user);
				printInventory(user);
				cout << endl;
			}
			else if(battleChoice.compare("4") == 0)
			{
				//attempts to run, if it works the battle ends and if not the enemy can attack
				run(user, floorNum, enemyType);
				if(user->getHealth() <= 0)
				{
					//if the run is unsuccessful and the enemy's attack kills the user the battle is over
					inBattle = false;
				}
			}
			if(!inBattle)
			{
				clearScreen();
				if(ranAway){
					ranAway = false;
					cout << "You ran away successfully!" << endl;
				}
				else{
					cout<<"Battle over!!"<<endl;
				}
				if(user->getHealth() <= 0)
					{
						clearScreen();
						cout<<"You failed!!! You must retake COP3503 again!!!"<<endl;
					}
				else if(enemyHealth <= 0)
				{
					if(!enemyType)
					{
						//if the enemy was a regular enemy it will have a 10% chance of dropping a potion (call potion increment from Michael)
						potionChance = (rand () % 10) + 1;
						if(potionChance == 1)
						{
							cout<<"You earned a packet of Smokin' Notes for defeating your opponent!"<<endl;
							user->addPotion();
							//you gain xp from defeating a regular enemy
							cout<<"You gained 10 XP from defeating your enemy!"<<endl;
							user->xpEnemy();
							user->checkLevelUp();
							cout<<endl;
						}
						else
						{
							cout<<"Your opponent did not drop any Smokin' Notes"<<endl;
							user->xpEnemy();
							cout<<"You gained 10 XP from defeating your enemy!"<<endl;
							user->checkLevelUp();
							cout<<endl;
						}
					}
					else if(enemyType)
					{
						//if the enemy is a boss it will always drop a potion (call potion increments potion from Michael)
						cout<<"You earned a packet of Smokin' Notes for defeating your opponent!"<<endl;
						user->addPotion();
						//you gain xp from beating a boss
						cout<<"You earned 50 XP from defeating your opponent!"<<endl;
						user->xpBoss();
						user->checkLevelUp();
						cout<<endl;
					}
				}
				return;
			}
			battleChoice = "0";
			if(cheat && godmode){
				user->setHealth(user->getMaxHealth());
			}
		}
	}

	//"creates" the enemy which the user is battling by givng it a set amount of health based on floor and bool (boos or not)
	void createEnemy(int floorNum, bool enemyType)
	{
		if(!enemyType)
		{
			//if the enemy is a regular enemy they their health is their floor number times 10
			enemyHealth = (floorNum * 10);
		}
		else if(enemyType)
		{
			//if enemy is a boss their health will be 20 times the floor number
			enemyHealth = (floorNum * 20);
		}
		else
		{
			//Validation (probaby shouldn't be a problem but just in case)
			cout<<"Invalid enemy type!"<<endl;
			return;
		}

	}

	void userDamage(int userLevel)
	{
		//calculates the user's attack damage for an attack based on level and a base damage
		damageDone = baseDamage + (rand () % (5 + userLevel)) + userLevel;
		enemyHealth = enemyHealth - damageDone;
	}

	void userAttack(int userLevel)
	{
		//calculates whether or not the user's attack hits
		attackChance = (rand () % 10) + 1;
		if(attackChance == 1)
		{
			//If your attack attempt is a critical fail, you will miss
			cout<<"Your attack missed!!"<<endl;
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

	void enemyDamage(User* user, int floorNum, bool enemyType)
	{
		tempUserHealth = user->getHealth();
		if(!enemyType)
		{
			//calcualtes the damage of a regular enemy's attack based on floor number and base damage
			damageDone = baseDamage + (rand () % (3 + floorNum)) + floorNum;
		}
		if(enemyType)
		{
			//calculates the damage of a boss enemy's attack based on floor number and base damage
			damageDone = baseDamage + (rand () % (6 + floorNum)) + floorNum;
		}
		tempUserHealth = (tempUserHealth - damageDone);
		user->setHealth(tempUserHealth);
	}

	void enemyAttack(User* user, int floorNum, bool enemyType)
	{
		//calculates whether or not the enemy's attack hits
		attackChance = (rand () % 10) + 1;
		if(attackChance == 1)
		{
			//if the chance is a critcal fail the enemy's attack misses
			cout<<"The enemy's attack missed!"<<endl;
		}
		else if(attackChance == 10)
		{
			//if attack chance is 10 it does critical damage to the user(damage is run twice)
			cout<<"Critical hit!"<<endl;
			enemyDamage(user, floorNum, enemyType);
			enemyDamage(user, floorNum, enemyType);
		}
		else
		{
			//does regular damage to the user
			cout<<"Your enemy's attack hit!"<<endl;
			enemyDamage(user, floorNum, enemyType);
		}
		cout << endl;
	}


	void UsePotion(User* user)
	{
		//User uses a potion and then enemy gets a chance to atttack
		user->usePotion();
	}


	void displayStats(User* user)
	{
		//Lets the user see their stats
		printPlayerStats(user);
	}

	void run(User* user, int floorNum, bool enemyType)
	{
		//calculates the user's chance of running away from the battle successfully
		runChance = (rand () %  3) + 1;
		if(enemyType){
			if(floorNum < 4){
				cout<<"You cannot run from bosses!"<<endl<<endl;
			}
			else{
				cout<<"You cannot escape the great Liu!"<<endl<<endl;
			}
		}
		else if(runChance == 1)
		{
			inBattle = 0;
			ranAway = true;
		}
		else
		{
			cout<<"You were unable to run away!"<<endl;
			enemyAttack(user, floorNum, enemyType);
		}
		runChance = 0;
	}
};

#endif
