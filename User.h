#ifndef USER_H
#define USER_H
#include "Person.h"

class User : public Person {
private:
	bool inBattle;
	int level;
	int maxHealth;
public:
	User(int health, int x, int y);
	User(int x, int y);
	void setMaxHealth(int maxHealth);
	int getMaxHealth();
	void setHealth(int health);
	void move(char dir, char **map);
	void levelUp();
	bool getInBattle();
	void toggleInBattle();
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

void User::setMaxHealth(int maxHealth) {
	this->maxHealth = maxHealth;
	return;
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

void User::move(char dir, char **map) {
	//TODO figure out location system
	if (dir == 'w') {
		if(map[xLocation][yLocation - 1] != '#'){
			return;
		}
		this->yLocation -= 1;
		return;
	}
	else if(dir == 'a') {
		if(map[xLocation - 1][yLocation] != '#'){
			return;
		}
		this->xLocation -= 1;
		return;
	}
	else if (dir == 's') {
		if(map[xLocation][yLocation + 1] != '#'){
			return;
		}
		this->yLocation += 1;
		return;
	}
	else if (dir == 'd') {
		if(map[xLocation + 1][yLocation] != '#'){
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
#endif // !USER_H
