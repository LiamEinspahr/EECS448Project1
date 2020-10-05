
#include "machine.h"
#include <ctime>

Machine::Machine(){
	srand (time(NULL));  
}

void Machine::setGameMode(char foo){
    gamemode = foo;
}

char Machine::getGameMode(){
    return(gamemode);
}

void Machine::setDifficultyLevel(char foo){
    difficultyLevel = foo;
}

char Machine::getDifficultyLevel(){
    return(difficultyLevel);
}

int Machine::charToInt(char c) {return ((toupper(c) - 65));}

int Machine::randomNum(){
	//add more conditions if they choose the xl board
    //srand (time(NULL)); 
	int randInt;
	if(gamemode == 'X'){
		randInt = (rand() % 20);
	}
	else{
		randInt = (rand() % 9);
	}
    randInt--;
    return(randInt);
}

int Machine::randomChar(){
	char c;
    int r;
    int charInt;

	if(gamemode == 'X'){
		r = rand() % 20;   
    	c = 'a' + r-1;
    	charInt = charToInt(c);
	}
	else{
		r = rand() % 9;   
    	c = 'a' + r-1;
    	charInt = charToInt(c);
	}
	return(charInt);
}

char Machine::getRandomDirection(){
	char directionArray[4] = {'U','D','R','L'};
	int position = rand() % 4;
	char randDirection = directionArray[position];
	return(randDirection);
}