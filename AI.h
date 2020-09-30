#ifndef AI_H
#define AI_H

#include "Executive.cpp"

#include<iostream>
using namespace std;

class AI{

public:

    AI(){ };

    int charToInt(char c);

    int randomNum();
	
    int randomChar();

	char getRandomDirection();

private:
    Executive exec;
    
};
#endif