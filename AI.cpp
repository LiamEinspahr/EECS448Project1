
#include "AI.h"


int AI::charToInt(char c) {return ((toupper(c) - 65));}

int AI::randomNum(){
	//add more conditions if they choose the xl board
	int randInt;
	if(exec.getGameMode() == 'X'){
		randInt = (rand() % 20) + 1;
	}
	else{
		randInt = (rand() % 9) + 1;
	}
    return(randInt);
}

int AI::randomChar(){
	char c;
    int r;
    int charInt;
	srand (time(NULL));  

	if(exec.getGameMode() == 'X'){
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

char AI::getRandomDirection(){
	srand (time(NULL));
	char directionArray[4] = {'U','D','R','L'};
	int position = rand() % 4;
	char randDirection = directionArray[position];
	return(randDirection);
}