#ifndef ROOMGEN_H
#define ROOMGEN_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

class RoomGen{

	//data fields

	//methods
	//constructor

	public:
		RoomGen();
		void createWalls(char wallChar);
		void createDoors();

		void spawnRock2by2();
		void spawnRock4by4();

		void spawnPlayer(int x, int y);
		void spawnVertSep();

		//spawns and enemy bot at a random locations
		void spawnAI();

		//spawns the bot at x,y coords. MAKE SURE x,y are within matrix limits
		void spawnAI(int x, int y);
		//add get map()
		//add
		void print();
	private:
		char map[80][20];

};

RoomGen::RoomGen(){
	//srand(time(NULL));

	for(int i = 0; i < 80; i++){
		for(int j = 0; j < 20; j++){
			map[i][j] = ' ';
		}
	}
	createWalls('*');

}


void RoomGen::createWalls(char wallChar){

	for(int i = 0; i < 80; i ++){
		if(i != 37 && i != 38 && i != 39 && i != 40){
			map[i][0] = wallChar;
			map[i][1] = wallChar;

			map[i][18] = wallChar;
			map[i][19] = wallChar;
		}
	}

	for(int i = 0; i < 20; i ++){
		if(i != 8 && i != 9 && i != 10 && i != 11){
			map[0][i] = wallChar;
			map[1][i] = wallChar;

			map[78][i] = wallChar;
			map[79][i] = wallChar;
		}
	}

}



void RoomGen::spawnAI(){

	int x; int y;
	do{
		x = rand()%76 + 2;
		y = rand()%16 + 2;
	}while(map[x][y] != ' ');

	map[x][y] = '!';

}

void RoomGen::spawnRock2by2(){

	int x; int y;
	do{
		x = rand()%75 + 2;
		y = rand()%15 + 2;
	}while(map[x][y] != ' ' || map[x+1][y] != ' ' || map[x][y+1] != ' '|| map[x+1][y+1] != ' ');

	map[x][y] = '#';
	map[x+1][y] = '#';
	map[x][y+1] = '#';
	map[x+1][y+1] = '#';

}

void RoomGen::spawnRock4by4(){

	int x; int y;
	do{
		x = rand()%73 + 2;
		y = rand()%13 + 2;
	}while(map[x][y] != ' ' || map[x][y+1] != ' ' || map[x][y+2] != ' ' || map[x][y+3] != ' '
			|| map[x+1][y] != ' ' || map[x+1][y+1] != ' ' || map[x+1][y+2] != ' ' || map[x+1][y+3] != ' '
			|| map[x+2][y] != ' ' || map[x+2][y+1] != ' ' || map[x+2][y+2] != ' ' || map[x+2][y+3] != ' '
			|| map[x+3][y] != ' ' || map[x+3][y+1] != ' ' || map[x+3][y+2] != ' ' || map[x+3][y+3] != ' ');

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			map[x+i][y+j] = '#';
		}
	}

}

void RoomGen::print(){
	for(int i = 0; i < 20; i++){
		for(int j = 0; j < 80; j++){
			if(map[j][i] == 'e')
				cout << ' ';
			else
				cout << map[j][i];

		}
	}
}

void RoomGen::spawnPlayer(int x, int y){
	if(map[x][y] != ' '){
		cout << "Object in the way! can't spawn here";
	}else{
		map[x][y] = 'Q';
	}

}

void RoomGen::spawnVertSep(){


	bool error = 1;
	int rnd = 0;

	while(error){
		rnd = rand()%66 + 7;
		error = 0;

		for(int i = 2; i < 18; i++){
			if(map[rnd][i] == '!' || map[rnd][i] == 'Q'){
				error = 1;

			}
		}
	}

	for(int i = 2; i < 18; i ++){
		map[rnd][i] = '#';
	}


	int temp = rand()%15 + 2;
	map[rnd][temp] = ' ';
	map[rnd][temp+1] = ' ';

	map[rnd+1][temp] = 'e';
	map[rnd+1][temp+1] = 'e';

	map[rnd-1][temp] = 'e';
	map[rnd-1][temp+1] = 'e';
}

#endif
