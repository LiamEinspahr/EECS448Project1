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
        /**
         * @brief Choose where to fire a shot
         * 
         * @param currentPlayer The player's board
         * @param otherPlayer The AI's board
         */
        void solve(Player &currentPlayer, Player &otherPlayer); // calls recursive function but does not recurse itself
        /**
         * @brief Construct a new Medium AI
         * 
         */
        Medium();

    private:

        /**
         * @brief Check if the given coordinate is valid placement
         * 
         * @param row The row to check
         * @param col The column to check
         * @return true The coordinate is valid
         * @return false The coordinate is invalid
         */
        bool checkCoords(int row, int col);
        /**
         * @brief Check if the player's ship is at the given spot
         * 
         * @param row The row to check
         * @param col The column to check 
         */
        void guessSpot(int row, int col);
        /**
         * @brief Check around the given spot for another spot to shoot at
         * 
         * @param row The row to check near
         * @param col The column to check near
         * @return true A spot was found
         * @return false A spot could not be found
         */
        bool move(int row, int col);
        /**
         * @brief Check if a given coordinate is in the current array
         * 
         * @param row The row to check
         * @param col The column to check
         * @return true The coordinate matches
         * @return false The coordinate does not match
         */
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
