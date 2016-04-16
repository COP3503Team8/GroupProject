#ifndef USER_H
#define USER_H
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
public:
	User(int health, int x, int y):Person(health, x, y){}; //Constructor
	User(int x, int y):Person(100, x, y){}; //Constructor with health 100
	User():Person(100, 11, 11){}; //Constructor with health 100, x location 11, and y location 11
	void setMaxHealth(int maxHealth); //Sets maximum health value
	int getMaxHealth(); //Returns maximum health value
	void setHealth(int health); //Sets health value
	int getHealth(); //Returns health value
	int getLevel(); //Returns player's level
	void setLocation(int x, int y); //Sets location using two values
	int getXLocation(); //Returns x location
	int getYLocation(); //Return y location
	void move(char dir, int **map); //Moves the player. Checks for wall collision
	void levelUp(); //Levels up the player
	bool getInBattle(); //Returns a bool whether the player is in battle
	void toggleInBattle(); //Changes the bool saying whether the user is in battle
	void xpEnemy(); //Increases XP after killing an enemy
	void xpBoss(); //Increases XP after killing a boss
	void addPotion(); //Gives player a potion
	void usePotion(); //Uses a potion to restore to full health
	int getPotion(); //Returns amount of potions
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
		return;
	}
}
void User::levelUp() {
	//Levels up the player
	this->level += 1;
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
	health = 100;
}
int User::getPotion(){
	 //Returns amount of potions
	 return potions;
}
#endif // !USER_H
