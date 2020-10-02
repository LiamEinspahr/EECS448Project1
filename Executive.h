#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "board.h"
#include "player.h"

#include <iostream>
using namespace std;

class Executive
{
public:

	Executive(){};		//Constructor
	~Executive(){};		//Destructor

	/**
 	* @pre:	None
 	* @post: function to hide player info when switch player1 to 2 or player2 to 1
 	* @param: print 50 blank line when need to switch player
 	**/
	void WaitEnter();


	/**
 	* @post: run the program
	* @param: play the Battleship game, the prog gets ship info from players
	* 		  player will fire the enemy ship until there is a winner
 	**/
	void run();

	/**
 	* @pre: input the correct char type
 	* @post: convert letters to corresponding numbers
	* @param: get the letter from the player, then use the formula to convert letter to numbers
	* @return: return ((toupper(c) - 65))
 	**/
	int charToInt(char c);

	/**
 	* @pre: input the correct char type
 	* @post: verifying user input if it's within the range of A-I
	* @param: get the letter from the player, then check the range
	* @return: return true when the letter is within the range of A-I
 	**/
	bool validColumn(bool big, char c);

	/**
 	* @pre: input the correct int type
 	* @post: add the number of grids occupied by all ships
	* @param: get the ship number from the player, then calculate the number of grids occupied by the ship
	* @return: return n, the number of grids occupied by all ships
 	**/
  	int numShipCoords(int shipNum);

	bool checkForBig();




private:
	bool big;


};
#endif // EXECUTIVE_H
