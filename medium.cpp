//MEDIUM CPP

#include "board.h"
#include "medium.h"

int Medium:: randomNum(){
    //add more conditions if they choose the xl board
    return((rand() % 9) + 1);
}

char Medium:: randomChar(){
    char c;
    int r;

    srand (time(NULL));    
    r = rand() % 9;   
    c = 'a' + r;           
    return(c);
}

bool Medium:: isValidMove(int row, int col){

}