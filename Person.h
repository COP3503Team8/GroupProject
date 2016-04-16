#ifndef PERSON_H
#define PERSON_H

class Person {
	//Person object intended to be extended to other objects
protected:
	int health;
	int xLocation;
	int yLocation;
public:
	Person(int health) :health(health),xLocation(0),yLocation(0){} //Constructors
	Person(int health, int xLocation, int yLocation):health(health),xLocation(xLocation),yLocation(yLocation){} //Constructors
	virtual void setHealth(int health); //Sets health value
	int getHealth(); //Returns health value
	void setLocation(int *loc); //Sets location from array
	void setxLocation(int x); //Sets x location
	void setyLocation(int y); //Set y location
	int getxLocation(); //Returns x location
	int getyLocation(); //Return y location
};

void Person::setHealth(int health) {
	//set health value
	this->health = health;
	return;
}

int Person::getHealth() {
	//return health value
	return this->health;
}

void Person::setLocation(int *loc) {
	//sets location using an array
	this->xLocation = loc[0];
	this->yLocation = loc[1];
	return;
}

void Person::setxLocation(int x){
	//sets x location
	this->xLocation = x;
	return;
}

void Person::setyLocation(int y) {
	//sets y location
	this->yLocation = y;
	return;
}

int Person::getxLocation() {
	//Returns x location
	return this->xLocation;
}

int Person::getyLocation() {
	//Return y location
	return this->yLocation;
}

// int* Person::getLocation(){
// 	int location[2] = { xLocation, yLocation };
// 	int* ptr = location;
// 	return ptr;
// }

#endif // !PERSON_H
