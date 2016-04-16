#ifndef BATTLECLASS_H
#define BATTLECLASS_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "User.h"
#include "Print.h"

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

	Battle()
	{
		bool inBattle = true;
		string battleChoice;
		int attackChance = 0;
		int runChance = 0;
		int damageDone = 0;
		int baseDamage = 5;
		int enemyHealth = 0;
		int tempUserHealth = 0;
		int potionChacne = 0;

	}

		void battleScreen(User* user, int userLevel, int floorNum, char enemyType)
	{
		cout<<"You have encountered an enemy!"<<endl;
		createEnemy(floorNum, enemyType);
		inBattle = true;
		while(inBattle)
		{
			//The menu shown to the user while they are in battle
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
				//The user will attack the enemy and the enemy will have a chance to attack the user back if it's still alive
				userAttack(userLevel);
				if(enemyHealth > 0)
				{
					//if the user's attack doesn't kill the enemy the enemy can attack back
					enemyAttack(floorNum, enemyType);
					if(User.getHealth() <= 0)
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
				usePotion();
				enemyAttck(floorNum, enemyType);
				if(User.getHealth <= 0)
				{
					//if the enemy's attack kills the user the battle is over
					inBattle = false;
				}
			}
			else if(battleChoice.compare("3") == 0)
			{
				//displays user stats and then gives the user a chacne to attack again
				displayStats(user);
			}
			else if(battleChoice.compare("4") == 0)
			{
				//attempts to run, if it works the battle ends and if not the enemy can attack
				run();
				if(User.getHealth() <= 0)
				{
					//if the run is unsuccessful and the enemy's attack kills the user the battle is over
					inBattle = false;
				}
			}
			if(!inBattle)
			{
				cout<<endl;
				cout<<"Battle over!!"<<endl;
				if(Person.getHealth() <= 0)
					{
						cout<<"You Lose!!"<<endl;
					}
				else if(enemyHealth <= 0)
				{
					if(enemyType == '!')
					{
						//if the enemy was a regular enemy it will have a 10% chance of dropping a potion (call potion increment from Michael)
						potionChance = (rand () % 4) + 1
						if(potionChance == 1)
						{
							cout<<"You earned a potion for defeating your opponent!"<<endl;
							User.addPotion();
							//you gain xp from defeating a regular enemy
							cout<<"You gained 10 XP from defeating your enemy!"<<endl;
							User.xpEnemy();
							cout<<endl;
						}
						else
						{
							cout<<"Your opponent did not drop a potion"<<endl;
						}
					}
					else if(enemyType == 'B')
					{
						//if the enemy is a boss it will always drop a potion (call potion increments potion from Michael)
						cout<<"You earned a potion for defeating you opponent!"<<endl;
						User.addPotion();
						//you gain xp from beating a boss
						cout<<"You earned 50 XP from defeating your opponent!"<<endl;
						User.xpBoss();
						cout<<endl;
					}
				}
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
			//if the enemy is a regular enemy they their health is their floor number times 10
			enemyHealth = (floorNum * 10);
		}
		else if(enemyType == 'B')
		{
			//if enemy is a boss their health will be 20 times the floor number
			enemyHealth = (floorNum * 20)
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
		tempUserHealth = User->getHealth();
		if(enemyType = '!')
		{
			//calcualtes the damage of a regular enemy's attack based on floor number and base damage
			damageDone = baseDamage + (rand () % (3 + floorNum)) + floorNum;
		}
		if(enemyType = 'B')
		{
			//calculates the damage of a boss enemy's attack based on floor number and base damage
			damageDone = baseDamage + (rand () % (6 + floorNum)) + floorNum;
		}
		tempUSerHealth = (tempUserHealth - damageDone);
		User.setHealth(tempUserHealth);
	}

	void enemyAttack(int floorNum, char enemyType)
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
		//User uses a potion and then enemy gets a chance to atttack
		User.usePotion();
	}
	

	void displayStats(User* user)
	{
		//Lets the user see their stats
		Print.printPlayerStats(user);
	}

	void run()
	{
		//calculates the user's cahcne of running away from the battle successfully
		runChance = (rand () %  3) + 1;
		if(runChance == 1)
		{
			inBattle = 0;
			cout<<"You ran away succesfully!"<<endl;
		}
		else
		{
			cout<<"You were unable to run away!"<<endl;
			cout<<endl;
			enemyAttack(floorNum, enemyType);
		}
		runChance = 0;
	}
};

#endif

