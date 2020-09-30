//MEDIUM H

#ifndef MEDIUM_H
#define MEDIUM_H

#include "board.h"
#include "player.h"

#include<iostream>
using namespace std;

class Medium{

    public:
        void solve(); // calls recursive function but does not recurse itself
        int getRow();
        int getCol();
        int randomNum();
        int randomChar();
        Medium();

    private:
        
        bool isValidMove(int row, char col);
        bool move(int row, int col); // recursive function
        int charToInt(char c);
        int row;
        int col;

};
#endif
