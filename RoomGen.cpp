#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "RoomGen.h"

using namespace std;

int main(){

	srand(time(NULL));
	RoomGen r;

	r.spawnVertSep();
	r.spawnVertSep();
	r.spawnVertSep();
	r.spawnVertSep();
	r.spawnAI();
	r.spawnRock4by4();
	r.spawnRock4by4();
	r.spawnRock4by4();
	r.spawnRock4by4();
	r.spawnRock4by4();
	r.spawnRock4by4();
	r.spawnRock2by2();
	r.spawnRock2by2();
	r.spawnRock2by2();
	r.spawnAI();
	r.spawnAI();

	r.print();

}
