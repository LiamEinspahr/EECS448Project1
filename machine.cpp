
#include "machine.h"
#include <ctime>

machine::machine(){
    
}

void machine::setGameMode(char foo){
    gamemode = foo;
}

char machine::getGameMode(){
    return(gamemode);
}

void machine::setDifficultyLevel(char foo){
    difficultyLevel = foo;
}

char machine::getDifficultyLevel(){
    return(difficultyLevel);
}

int machine::charToInt(char c) {return ((toupper(c) - 65));}

int machine::randomNum(){
	//add more conditions if they choose the xl board
	int randInt;
	if(gamemode == 'X'){
		randInt = (rand() % 20) + 1;
	}
	else{
		randInt = (rand() % 9) + 1;
	}
    return(randInt);
}

int machine::randomChar(){
	char c;
    int r;
    int charInt;
	srand (time(NULL));  

	if(gamemode == 'X'){
		r = rand() % 20;   
    	c = 'a' + r;
    	charInt = charToInt(c);
	}
	else{
		r = rand() % 9;   
    	c = 'a' + r;
    	charInt = charToInt(c);
	}
	return(charInt);
}

char machine::getRandomDirection(){
	srand (time(NULL));
	char directionArray[4] = {'U','D','R','L'};
	int position = rand() % 4;
	char randDirection = directionArray[position];
	return(randDirection);
}