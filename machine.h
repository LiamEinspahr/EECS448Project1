#ifndef MACHINE_H
#define MACHINE_H

#include "Executive.cpp"

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

    private:
        Executive exec;
    
};
#endif