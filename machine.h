#ifndef MACHINE_H
#define MACHINE_H


#include<iostream>
using namespace std;

class machine
{

    public:

        machine();

        int charToInt(char c);

        int randomNum();
        
        int randomChar();

        char getRandomDirection();

        void setGameMode(char foo);

        char getGameMode();

        void setDifficultyLevel(char foo);

        char getDifficultyLevel();

    private:
        char gamemode;
        char difficultyLevel;
    
};
#endif