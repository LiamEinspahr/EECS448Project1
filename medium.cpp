//MEDIUM CPP

#include "board.h"
#include "medium.h"

Medium::Medium(){
    row = 0;
    col = 0;
}

int Medium::charToInt(char c) {return ((toupper(c) - 65));}

int Medium:: randomNum(){
    //add more conditions if they choose the xl board
    row = (rand() % 9) + 1;
    return(row);
}

int Medium:: randomChar(){
    char c;
    int r;
    int key;

    srand (time(NULL));    
    r = rand() % 9;   
    c = 'a' + r;
    key = charToInt(c);
    col = key;
    return(col);
}

int Medium::getRow(){
    return(row);
}

int Medium:: getCol(){
    return(col);
}

void Medium::solve(){
    
}

bool Medium::move(int row, int col){

}

bool Medium:: isValidMove(int row, char col){

}