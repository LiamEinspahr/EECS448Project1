#ifndef MACHINE_H
#define MACHINE_H

#include<ctime>
#include<iostream>
using namespace std;

class Machine
{

    public:

        /**
         * @brief Construct a new Machine to handle AI gameplay
         * 
         */
        Machine();

        /**
         * @brief Convert a character to the int it represents
         * 
         * @param c The character to convert
         * @return int The int which is represented by c
         */
        int charToInt(char c);

        /**
         * @brief Generate a random number 0-8 for normal boards and 0-19 for big boards
         * 
         * @return int The generated number
         */
        int randomNum();

        /**
         * @brief Generate a random number 0-8 for normal boards and 0-19 for big boards
         * 
         * @return int The generated number
         */
        int randomChar();

        /**
         * @brief Choose a random character in {'U','D','R','L'}
         * 
         * @return char The direction chosen
         */
        char getRandomDirection();

        /**
         * @brief Set the game mode (either 'X' or 'N')
         * 
         * @param foo The game mode (either 'X' or 'N')
         */
        void setGameMode(char foo);

        /**
         * @brief Return the set game mode
         * 
         * @return char The game mode (either 'X' or 'N')
         */
        char getGameMode();

        /**
         * @brief Set the Difficulty Level (either 'E', 'M', or 'H')
         * 
         * @param foo The difficulty level to set the game to (either 'E', 'M', or 'H')
         */
        void setDifficultyLevel(char foo);
        /**
         * @brief Get the Difficulty Level (either 'E', 'M', or 'H')
         * 
         * @return char The difficulty level the game is set to (either 'E', 'M', or 'H')
         */
        char getDifficultyLevel();

    private:
        char gamemode;
        char difficultyLevel;
    
};
#endif