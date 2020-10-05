#ifndef BOARD_H
#define BOARD_H

#include <iostream>
using namespace std;

class Board
{
	public:
		/**
 		* @breif: initializes a blank 9x9 board and a 20x20 board with '-' values
 		**/
		Board();
        /** 
         * @breif: Delete the board.
        **/
		~Board();

        /**
         * @brief Set the board size to big
         * 
         */
        void setBig();

		/**
 		* @post: prints the board characters
		**/
		void printBoard();

        /**
         * @brief Update the board with the given character
         * 
         * @param row The row in which to insert the character
         * @param col The column in which to insert the character
         * @param c The character to insert
         * @param shipsize The size of the associated ship if relevant
         */
		void updateBoard(int row, int col, char c, int shipsize=0);


        /**
         * @brief Update the number of ships which are on this board
         * 
         * @param numships The number of ships
         */
        void updateNumShips(int numships);

		/**
 		* @brief Return the value at the given coordinates
        * 
		* @post returns the value at a certain coordinate on the board
		* @param row row to get value at
        * @param col column to get value at
		* @return returns the character at the specified value
 		**/
		char getValue(int row, int col);
        /**
         * @brief Return whether the board is size XL
         * 
         * @return true The board is size XL
         * @return false The board is not size XL
         */
        bool checkBig();
        /**
         * @brief Get the Ship Num at the given coordinates
         * 
         * @param row The row to check
         * @param col The column to chekc
         * @return int The number of the ship at the given coordinates
         */
        int getShipNum(int row, int col);
        /**
         * @brief Check whether a ship of a given number is fully sunk
         * 
         * @param shipNum The shipnumber to check
         * @return true Every tile of the associated ship has been hit
         * @return false At least one tile remains to be hit
         */
        bool shipNumIsSunk(int shipNum);
        /**
         * @brief Check whether a ship at a given coordinate is fully sunk
         * 
         * @param row The row to check
         * @param col The column to check
         * @return true Every tile of the associated ship has been hit
         * @return false At least one tile remains to be hit
         */
        bool shipIsSunk(int row, int col);
        /**
         * @brief Check if any ships remain to be sunk
         * 
         * @return true All ships have been sunk
         * @return false At least one ship remains floating
         */
        bool allShipsSunk();

		char m_board[9][9];
		char m_boardXL[20][20];
		int m_board_ships[9][9];
		int m_board_shipsXL[20][20];
        /**
         * @brief Get the number of rows
         * 
         * @return int The number of rows
         */
        int getNumRows();
        /**
         * @brief Get the number of columns
         * 
         * @return int The number of columns
         */
        int getNumCols();

        /**
         * @brief Get the number of hits on the board
         * 
         * @return int The number of hits on the board
         */
        int getNumHits();

	private:
		int numRows = 9;
		int numCols = 9;  // Letters (A-I)
        int numShips = 5;
};


#endif
