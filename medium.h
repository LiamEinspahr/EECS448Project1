//MEDIUM H

#ifndef MEDIUM_H
#define MEDIUM_H

//#include "board.h"
#include "player.h"
#include "machine.h"

#include<iostream>
using namespace std;

class Medium{

    public:
        void solve(Player &currentPlayer, Player &otherPlayer); // calls recursive function but does not recurse itself
        Medium();

    private:

        bool checkCoords(int row, int col); // recursive function
        void guessSpot(int row, int col);
        bool move(int row, int col);
        bool notInArray(int row, int col);

        int row;
        int col;
        int hitRow;
        int hitCol;
        bool attackShip = false;
        Machine machine;
        Player* currentPlayer;
        Player* otherPlayer;

        int hits = 0;
        int** hitGuess;
        bool haveGuesses = false;
        int tracking = 0;
        int shipKey;
        int value;



};
#endif
