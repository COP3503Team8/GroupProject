#ifndef USER_H
#define USER_H
#include "Person.h"

class User : public Person {
private:
	bool inBattle;
	int level;
	int maxHealth;
public:
	void setMaxHealth(int maxHealth);
	int getMaxHealth();
	void setHealth(int health);
	void move(char dir);
	void levelUp();
	bool getInBattle();
	void toggleInBattle();
};

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

void User::move(char dir) {
	//TODO figure out location system
	if (dir == 'w') {
		this->yLocation -= 1;
		return;
	}
	else if(dir == 'a') {
		this->xLocation -= 1;
		return;
	}
	else if (dir == 's') {
		this->yLocation += 1;
		return;
	}
	else if (dir == 'd') {
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
