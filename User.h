#ifndef USER_H
#define USER_H
#include <iostream>
#include "Person.h"

class Inventory;

class User : public Person {
	friend Inventory;
private:
	bool inBattle;
	int level;
	int maxHealth;
	int xp;
	int potion;
	int requiredXP;
public:
	User(int health, int x, int y):Person(health, x, y),inBattle(false),level(1),maxHealth(100),xp(0),potion(0),requiredXP(100){}; //Constructor
	User(int x, int y):Person(100, x, y),inBattle(false),level(1),maxHealth(100),xp(0),potion(0),requiredXP(100){}; //Constructor with health 100
	User():Person(100, 11, 11),inBattle(false),level(1),maxHealth(100),xp(0),potion(0),requiredXP(100){}; //Constructor with health 100, x location 11, and y location 11
	void setMaxHealth(int maxHealth); //Sets maximum health value
	int getMaxHealth(); //Returns maximum health value
	void setHealth(int health); //Sets health value
	int getHealth(); //Returns health value
	int getLevel(); //Returns player's level
	void setLocation(int x, int y); //Sets location using two values
	int getXLocation(); //Returns x location
	int getYLocation(); //Return y location
	void move(char dir, int **map); //Moves the player. Checks for wall collision
	void checkLevelUp(); //Check to see if player levels up, and levels up the player if so
	bool getInBattle(); //Returns a bool whether the player is in battle
	void toggleInBattle(); //Changes the bool saying whether the user is in battle
	void xpEnemy(); //Increases XP after killing an enemy
	void xpBoss(); //Increases XP after killing a boss
	void addPotion(); //Gives player a potion
	void usePotion(); //Uses a potion to restore to full health
	int getPotions(); //Returns amount of potions
	int getNeededEXP(); //Returns needed XP
};

int User::getMaxHealth() {
	//Returns maximum health value
	return this->maxHealth;
}

void User::setHealth(int health) {
	//Sets health value
	if (health > maxHealth) {
		return;
	}
	else {
		this->health = health;
	}
	return;
}

int User::getHealth() {
	 //Returns health value
	return health;
}

int User::getLevel(){
	//Returns player's level
	return level;
}

void User::setLocation(int x, int y){
	//Sets location using two values
	xLocation = x;
	yLocation = y;
	return;
}

int User::getXLocation(){
	//Returns x location
	return xLocation;
}

int User::getYLocation(){
	//Return y location
	return yLocation;
}

void User::move(char dir, int **map) {
	 //Moves the player. Checks for wall collision
	if (dir == 'w') {
		if(map[xLocation][yLocation - 1] != 1){
			return;
		}
		this->yLocation -= 1;
		return;
	}
	else if(dir == 'a') {
		if(map[xLocation - 1][yLocation] != 1){
			return;
		}
		this->xLocation -= 1;
		return;
	}
	else if (dir == 's') {
		if(map[xLocation][yLocation + 1] != 1){
			return;
		}
		this->yLocation += 1;
		return;
	}
	else if (dir == 'd') {
		if(map[xLocation + 1][yLocation] != 1){
			return;
		}
		this->xLocation += 1;
		return;
	}
	else {
		std::cout << "Not correct letter!" << std::endl;
		return;
	}
}
void User::checkLevelUp() {
	//Levels up the player if they have enough XP
	if(xp >= requiredXP){
		xp -= requiredXP;
		requiredXP += 10;
		this->level += 1;
		maxHealth += 10;
		health = maxHealth;
	}
	return;
}
bool User::getInBattle() {
	//Returns a bool whether the player is in battle
	return inBattle;
}
void User::toggleInBattle() {
	//Changes the bool saying whether the user is in battle
	if (this->inBattle) {
		this->inBattle = false;
	}
	else {
		this->inBattle = true;
	}
	return;
}
void User::xpEnemy(){
	//Increases XP after killing an enemy
	xp += 10;
	return;
}
void User::xpBoss(){
	//Increases XP after killing a boss
	xp += 50;
	return;
}
void User::addPotion(){
	//Gives player a potion
	potion++;
	return;
}
void User::usePotion(){
	//Uses a potion to restore to full health
	potion--;
	health = maxHealth;
}
int User::getPotions(){
	 //Returns amount of potions
	 return potion;
}
int User::getNeededEXP(){
	//Returns needed XP
	return (requiredXP - xp);
}
#endif // !USER_H
