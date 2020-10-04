#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"

class Player
{
	public:
		Player();   	    // Constructor
		~Player();  	    // Destructor;
		Board my_ships = Board(false);
		Board enemy_ships = Board(false);
		Board my_shipsXL = Board(true);
		Board enemy_shipsXL = Board(true);


		/**
 		* @pre: Ships parameter must be Int between 1 & 5, inclusive
		* @post: Both players will be limited to the ships parameter
		* @param: int ships: how many ships each player will be able to place
 		**/
		void SetNumShips(int ships); // updates number of ships variable


		/**
 		* @pre: 'Row' and 'col' between 0 & 8 inclusive, 'direction' must be 'U', 'D', 'R', or 'L'
		* @post: returns the value at a certain coordinate on the board
		* @param: size: length of ship; row: starting row of pivot; col: starting col of pivot; direction: the orientation of the ship around the pivot
		* @return: returns whether the placement was successful or not
 		**/
		bool PlaceShip(int size, int row, int col, char direction); // will try to place a ship with upper left point at row, col; returns false if it cant
		bool PlaceShipAI(int size, int row, int col, char direction);

		/**
 		* @pre: None
		* @post: None
 		**/
		void PrintMyShips(); // prints board with players ships


		/**
 		* @pre: None
		* @post: None
 		**/
		void PrintEnemyShips(); // prints board with hits/misses of enemy ships


		/**
 		* @pre: None
		* @post: my_ships & enemy_ships will be reverted to 9x9 boards with '-' in each index
 		**/
		void ClearBoards();


		/**
 		* @pre: 'row' & 'col' must be between 0 & 8, inclusive
		* @post: None
		* @param: row: which row to check; col: which column to check
		* @return: returns true if a ship has been hit, false if not
 		**/
		bool CheckHit(int row, int col);

		/**
 		* @pre: row and col must be between 0 & 8, inclusive
		* @post: enemy_ships member variable will be updated with new state
		* @param: row: which row to check; col: which column to check; hit: whether there was a hit or miss
 		**/
		void UpdateEnemyBoard(int row, int col, bool hit);

		bool checkPlayerBig();

	private:
		int numShips;
};


#endif
