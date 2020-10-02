//MEDIUM H

#ifndef MEDIUM_H
#define MEDIUM_H

//#include "board.h"
#include "player.h"
#include "display.h"
#include "Ship.h"
#include "machine.h"

#include<iostream>
using namespace std;

class Medium{

    public:
        void solve(Player &currentPlayer, Player &otherPlayer, Ship &currentShip, Ship &otherShip); // calls recursive function but does not recurse itself
        int getRow();
        int getCol();
        int randomNum();
        int randomChar();
        Medium();

    private:
        
        bool isValidMove(int row, char col);
        bool Coordinates(int row, int col); // recursive function
        int charToInt(char c);
        int row;
        int col;
        int hitRow;
        int hitCol;
        bool attackShip = false;
        machine machine;
        Player player;
        Display display;
        Ship ship;

};
#endif
