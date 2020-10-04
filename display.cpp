#include "display.h"
#include "Executive.h"
#include <iostream>

using namespace std;

Display::Display(bool big)
{
	m_big = big;

	if(big){
		m_borderSpace = "\n\n";
		m_playeriBanner = "                 PLAYER i\n\n\n";
		m_enemyBanner =   "               SHOTS FIRED\n\n\n";
		m_colLabel = "      A   B   C   D   E   F   G   H   I   J   K   L   M   N   O   P   Q   R   S\n";
		m_borderLineTop = "    +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+\n";
		m_rowiLabel = "  i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |    |\n";
		m_gridLine = "    +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---|\n";
		m_borderLineBottom = "    +------------------------------------------------------------------------------+";
		m_friendlyBanner = "\n\n                YOUR SHIPS\n\n\n";
	}
	else {
	//board elements
	m_borderSpace = "\n\n";
	m_playeriBanner = "                 PLAYER i\n\n\n";
	m_enemyBanner =   "               SHOTS FIRED\n\n\n";
	m_colLabel = "      A   B   C   D   E   F   G   H   I\n";
	m_borderLineTop = "    +---+---+---+---+---+---+---+---+---+\n";
	m_rowiLabel = "  i |   |   |   |   |   |   |   |   |   |\n";
	m_gridLine = "    +---+---+---+---+---+---+---+---+---|\n";
	m_borderLineBottom = "    +-----------------------------------+";
	m_friendlyBanner = "\n\n                YOUR SHIPS\n\n\n";
	}

	//shot-feedback elements
	m_hit0 = "\n            _           _       _\n";
	m_hit1 = "             ',       ,'      ,'\n";
	m_hit2 = "               `,    '      ,'\n";
	m_hit3 = "\n            ~.,'__  HIT! __',.~\n";
	m_hit4 = "\n               ,'  ,'   ',\n";
	m_hit5 = "          ,,.'` _,'       `'.,,\n\n\n";
	m_miss = "\n\n                   MISS...\n\n\n";

}

Display::~Display()
{}

void Display::matchFrame(int playerID, Board &enemyBrd, Board &friendlyBrd) const
{
	enemyBoard(enemyBrd, playerID);
	cout << m_borderSpace;
	friendlyBoard(friendlyBrd);
}

void Display::enemyBoard(Board &board, int playerID) const
{
	string playeriBanner = m_playeriBanner;
	string enemyBanner = m_enemyBanner;
	string rowiLabel = m_rowiLabel;

	playeriBanner.replace(24, 1, to_string(playerID));

	cout << m_borderSpace;
	cout << playeriBanner;
	cout << enemyBanner;
	cout << m_colLabel;
	cout << m_borderLineTop;

	for(int i = 0; i < board.getNumRows(); i++)
	{
		rowiLabel.replace(2, 1, to_string(i+1));

		for(int j = 0; j < board.getNumCols(); j++)
		{
			if(board.getValue(i, j) == 'X')
			{
				rowiLabel.replace(4*j+6, 1, "X");
			}
			else if(board.getValue(i, j) == 'O')
			{
				rowiLabel.replace(4*j+6, 1, "O");
			}
		}

		cout << rowiLabel;
		rowiLabel = m_rowiLabel;

		if((m_big==false)&&(i < 8))
		{
			cout << m_gridLine;
		}
		else if((m_big==true)&&(i<19))
		{
			cout << m_borderLineBottom;
		}
	}
}

void Display::friendlyBoard(Board &board) const
{
	string rowiLabel = m_rowiLabel;

	cout << m_friendlyBanner;
	cout << m_colLabel;
	cout << m_borderLineTop;

	for(int i = 0; i < board.getNumRows(); i++)
	{
		rowiLabel.replace(2, 1, to_string(i+1));

		for(int j = 0; j < board.getNumCols(); j++)
		{
			if(board.getValue(i, j) == 'X')
			{
				rowiLabel.replace(4*j+5, 1, ">");
				rowiLabel.replace(4*j+6, 1, string(1, '0' + board.getShipNum(i, j)));
				rowiLabel.replace(4*j+7, 1, "<");
			}
			else if(board.getValue(i, j) == 'S')
			{
				rowiLabel.replace(4*j+5, 1, "(");
                rowiLabel.replace(4*j+6, 1, string(1, '0' + board.getShipNum(i, j)));
				rowiLabel.replace(4*j+7, 1, ")");
			}
			else if(board.getValue(i, j) == 'O')
			{
				rowiLabel.replace(4*j+6, 1, "O");
			}
		}

		cout << rowiLabel;
		rowiLabel = m_rowiLabel;

		if(i < 8)
		{
			cout << m_gridLine;
		}
		else
		{
			cout << m_borderLineBottom;
		}
	}
	cout << m_borderSpace;
}

void Display::hit() const
{
	cout << m_hit0;
	cout << m_hit1;
	cout << m_hit2;
	cout << m_hit3;
	cout << m_hit4;
	cout << m_hit5;
}

void Display::miss() const
{
	cout << m_miss;
}
