#ifndef aiEasy_H
#define aiEasy_H

#include "board.h"

class aiEasy
{
	public:
		aiEasy();   	    // Constructor
		~aiEasy();  	    // Destructor;
		Board my_ships;
		Board enemy_ships;



		void SetNumShips(int ships); // updates number of ships variable


		bool PlaceShip(int size); // will try to place a ship with upper left point at row, col; returns false if it cant

		void PrintMyShips(); // prints board with aiEasys ships


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

	private:
		int numShips;
};


#endif
