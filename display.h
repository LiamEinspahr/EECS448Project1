/*------------------------------------------------------------
 * @Filename: display.h
 * @Description: pretty prints game elements
 ------------------------------------------------------------*/

#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>
#include "board.h"

using namespace std;

class Display
{
	private:
        //board elements
        string m_borderSpace;
        string m_playeriBanner;
        string m_enemyBanner;
        string m_colLabel;
        string m_borderLineTop;
        string m_rowiLabel;
        string m_gridLine;
        string m_borderLineBottom;
        string m_friendlyBanner;

        //shot feed-back elements
        string m_hit0;
        string m_hit1;
        string m_hit2;
        string m_hit3;
        string m_hit4;
        string m_hit5;
        string m_miss;

	public:

        /**
         * @brief Display the enemy's board according to what is known by the player
         * 
         * @param board The board to display
         * @param playerID The player to display
         */
        void enemyBoard(Board &board, int playerID) const;

        /**
         * @brief Construct a new Display
         * 
         * @param big The user has requested an XL board
         */
        Display(bool big);

        /**
         * @brief Display the player's ships and the enemy's shots
         * 
         * @param board The board to display
         */
        void friendlyBoard(Board &board) const;

        /**
         * @brief Call both the friendlyBoard and the enemyBoard methods to display the current game state 
         * 
         * @param playerID The current player's ID
         * @param enemyBrd The enemy player's board
         * @param friendlyBrd The current player's board
         */
        void matchFrame(int playerID, Board &enemyBrd, Board &friendlyBrd) const;

        /**
         * @brief Display the hit message
         * 
         */
        void hit() const;

        /**
         * @brief Display the miss message
         * 
         */
        void miss() const;

        /**
         * @brief Destroy the Display
         * 
         */
        ~Display();
 

};
#endif
