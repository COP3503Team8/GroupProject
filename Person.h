#ifndef PERSON_H
#define PERSON_H

class Person {
protected:
	int health;
	int xLocation;
	int yLocation;
public:
	Person(int health) :health(health),xLocation(0),yLocation(0){} //TODO set default value
	Person(int health, int xLocation, int yLocation):health(health),xLocation(xLocation),yLocation(yLocation){}
	virtual void setHealth(int health);
	int getHealth();
	void setLocation(int *loc);
	void setxLocation(int x);
	void setyLocation(int y);
	int getxLocation();
	int getyLocation();
	int* getLocation();
};

void Person::setHealth(int health) {
	//set health
	this->health = health;
	return;
}

int Person::getHealth() {
	//get health
	return this->health;
}

void Person::setLocation(int *loc) {
	this->xLocation = loc[0];
	this->yLocation = loc[1];
	return;
}

void Person::setxLocation(int x){
	this->xLocation = x;
	return;
}

void Person::setyLocation(int y) {
	this->yLocation = y;
	return;
}

int Person::getxLocation() {
	return this->xLocation;
}

int Person::getyLocation() {
	return this->yLocation;
}

int* Person::getLocation(){
	int location[2] = { xLocation, yLocation };
	int* ptr = location;
	return ptr;
}

#endif // !PERSON_H
