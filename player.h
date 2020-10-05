#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"

class Player
{
	public:
        /**
         * @brief Construct a new Player
         * 
         * @param big If the user has requested a XL board
         */
		Player(bool big);
        /**
         * @brief Destroy the Player
         * 
         */
		~Player();
		Board my_ships;
		Board enemy_ships;


        /**
         * @brief Set the number of ships per player
         * 
         * @param ships The number of ships per player
         */
		void SetNumShips(int ships);


        /**
         * @brief Attempt to place the ship at the given point
         * 
         * @param size The size of the ship
         * @param row The row in which to place the ship
         * @param col The column in which to place the ship
         * @param direction The direction to face the ship
         * @return true Placement succeded
         * @return false Placement failed
         */
		bool PlaceShip(int size, int row, int col, char direction); // will try to place a ship with upper left point at row, col; returns false if it cant
        /**
         * @brief Attempt to place the ship at the given point for the AI
         * 
         * @param size The size of the ship
         * @param row The row in which to place the ship
         * @param col The column in which to place the ship
         * @param direction The direction to face the ship
         * @return true Placement succeded
         * @return false Placement failed
         */
        bool PlaceShipAI(int size, int row, int col, char direction);

        /**
         * @brief Print the player's board showing ships and enemy shots
         * 
         */
		void PrintMyShips();

        /**
         * @brief Print the enemy's board hits and misses
         * 
         */
		void PrintEnemyShips();

        /**
         * @brief Check if a shot at the given coordinate hits a ship
         * 
         * @param row The row to check 
         * @param col The column to check
         * @return true The shot was a hit
         * @return false The shot was a miss
         */
		bool CheckHit(int row, int col);

        /**
         * @brief Update the enemy board with a hit or miss at the given location
         * 
         * @param row The row to update
         * @param col The column to update
         * @param hit Whether the shot was a hit
         */
		void UpdateEnemyBoard(int row, int col, bool hit);

	private:
		int numShips;
};


#endif
