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

	/**
	 * @pre: board must use 'X' and 'O' to denote hits and misses, respectively.
	 * @post: prints state of enemy board
	 * @param: board, 9x9 array marked with 'X's and/or 'O's,
	 * playerID: either 1 or 2 (to differentiate players)
	 **/
	//display state of enemy board
	void enemyBoard(Board &board, int playerID) const;

	public:

	/**
	 * @post: constructs display obj.
	 **/
	Display(bool big);

	/**
	 * @pre: none
	 * @post: none
	 **/
	~Display();

	/**
	 * @pre: board must use 'X' and 'S' to denote hits and ships, respectively.
	 * @post: prints state of player's ships
	 * @param: board, 9x9 array marked with 'X's and/or 'S's
	 **/
	//in-game visual elements
	void friendlyBoard(Board &board) const;

	/**
	 * @pre: boards must use 'X's, 'O's, and 'S's to denote hits, misses, and ships, respectively
	 * @post: prints state of playerID's enemy board and their ships
	 * @param: playerID, either 1 or 2 (to differentiate players), enemyBrd: 9x9 array marked with 'X's and/or 'O's,
	   friendlyBrd: 9x9 array marked with 'X's and/or 'S's
	 **/
	void matchFrame(int playerID, Board &enemyBrd, Board &friendlyBrd) const;

	/**
	 * @post: prints hit message
	 **/
	void hit() const;

	/**
	 * @post: prints miss message
	 **/
	void miss() const;
};
#endif
