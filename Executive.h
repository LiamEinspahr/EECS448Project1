#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "board.h"
#include "player.h"

#include <iostream>
using namespace std;

class Executive
{
public:

    /**
     * @brief Construct a new Executive to handle gameplay
     * 
     */
	Executive(){};
    /**
     * @brief Destroy the Executive
     * 
     */
	~Executive(){};

    /**
     * @brief Output several newlines to clear the terminal screen and then wait for enter 
     * 
     */
	void WaitEnter();


    /**
     * @brief Run a game of battleship
     * 
     */
	void run();

    /**
     * @brief Convert a character to the int it represents
     * 
     * @param c The character to convert
     * @return int The int which is represented by c
     */
	int charToInt(char c);

    /**
     * @brief Check if a given column letter is valid
     * 
     * @param big Whether the current board is XL
     * @param c The character to check
     * @return true The character is a valid column
     * @return false The character is not a valid column
     */
	bool validColumn(bool big, char c);

    /**
     * @brief Calculate a termial to determine the number of ship coords based on the number of ships
     * 
     * @param shipNum The number of ships per player
     * @return int The number of ship tiles per player
     */
  	int numShipCoords(int shipNum);

};
#endif // EXECUTIVE_H
