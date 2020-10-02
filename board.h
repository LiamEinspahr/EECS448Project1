#ifndef BOARD_H
#define BOARD_H

#include <iostream>
using namespace std;

class Board 
{
	public:
		/**
 		* @pre: initializes a blank 9x9 board with '-' values
 		**/
	 	Board();				//Constructor
		Board(bool big);   	    // Constructor
		~Board();  	    // Destructor

		/**
 		* @pre: function to print a board, used as a test
 		* @post: prints the 9x9 board specific to the class
		**/
		void printBoard();

		/**
 		* @pre: function to place a hit on the board
		* @post: updates the board with whatever value is passed in
		* @param: int row: row to update, int col: column to update, char c: character to update row/col with
 		**/
		void updateBoard(int row, int col, char c, int shipsize=0); // Function to update board

        void updateNumShips(int numships); // Update number of ships on board

		/**
 		* @pre: function to return the value at some coordinates
		* @post: returns the value at a certain coordinate on the board
		* @param: int row: row to get value at, int col: column to get value at
		* @return: returns the character at the specified value
 		**/
		char getValue(int row, int col); // gets value at coordinates
		int getShipNum(int row, int col); // gets shipnum at coordinates
        bool shipNumIsSunk(int shipNum); // Check if a shipnum has sunk
        bool shipIsSunk(int row, int col); // Check if a ship at a location has sunk
        bool allShipsSunk(); // Check if all ships have sunk

		char m_board[9][9];  
		int m_board_ships[9][9];  
        int getNumRows(); // Return numRows
        int getNumCols(); // Return numCols

        int getNumHits(); // Get the number of hits on my ships

	private:  
		int numRows = 9;
		int numCols = 9;  // Letters (A-I)
        int numShips = 5;
};


#endif
