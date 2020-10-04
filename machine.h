#ifndef MACHINE_H
#define MACHINE_H

#include<ctime>
#include<iostream>
using namespace std;

class Machine
{

    public:

        Machine();

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