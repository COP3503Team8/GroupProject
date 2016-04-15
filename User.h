#ifndef USER_H
#define USER_H
#include "Person.h"

class User : public Person {
	friend Inventory;
private:
	bool inBattle;
	int level;
	int maxHealth;
	int xp;
	int potion;
public:
	User(int health, int x, int y);
	User(int x, int y);
	void setMaxHealth(int maxHealth);
	int getMaxHealth();
	void setHealth(int health);
	int getHealth();
	int getLevel();
	void setLocation(int x, int y);
	int getXLocation();
	int getYLocation();
	void move(char dir, char **map);
	void levelUp();
	bool getInBattle();
	void toggleInBattle();
	void killEnemy();
	void killBoss();
	void addPotion();
	void usePotion();
};

User::User(int health, int x, int y){
	this->health = health;
	this->xLocation = x;
	this->yLocation = y;
}

User::User(int x, int y){
	this->health = 100;
	this->xLocation = x;
	this->yLocation = y;
}

User::User(){
	this->health = 100;
	this->xLocation = 40;
	this->yLocation = 10;
}

int User::getMaxHealth() {
	return this->maxHealth;
}

void User::setHealth(int health) {
	if (health > maxHealth) {
		return;
	}
	else {
		this->health = health;
	}
	return;
}

int User::getHealth() {
	return health;
}

int User::getLevel(){
	return level;
}

void User::setLocation(int x, int y){
	xLocation = x;
	yLocation = y;
	return;
}

int User::getXLocation(){
	return xLocation;
}

int User::getYLocation(){
	return yLocation;
}

void User::move(char dir, char **map) {
	//TODO figure out location system
	if (dir == 'w') {
		if(map[xLocation][yLocation - 1] != '#' || map[xLocation][yLocation - 1] != '*'){
			return;
		}
		this->yLocation -= 1;
		return;
	}
	else if(dir == 'a') {
		if(map[xLocation - 1][yLocation] != '#' || map[xLocation - 1][yLocation] != '*'){
			return;
		}
		this->xLocation -= 1;
		return;
	}
	else if (dir == 's') {
		if(map[xLocation][yLocation + 1] != '#' || map[xLocation][yLocation + 1] != '*'){
			return;
		}
		this->yLocation += 1;
		return;
	}
	else if (dir == 'd') {
		if(map[xLocation + 1][yLocation] != '#' || map[xLocation + 1][yLocation] != '*'){
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
	this->level += 1;
	return;
}
bool User::getInBattle() {
	return inBattle;
}
void User::toggleInBattle() {
	if (this->inBattle) {
		this->inBattle = false;
	}
	else {
		this->inBattle = true;
	}
	return;
}
void User::xpEnemy(){
	xp += 10;
	return;
}
void User::killBoss(){
	xp += 50;
	return;
}
void User::addPotion(){
	potion++;
	return;
}
void User::usePotion(){
	potion--;
	health = 100;
}
#endif // !USER_H
