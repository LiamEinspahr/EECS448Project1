#include "board.h"

Board::Board()
{
	Board(false);
}

Board::Board(bool big)
{
	if(big) {
		numRows = 20;
		numCols = 20;
		for(int i=0; i<numRows; i++)
		{
			for(int j=0; j<numCols; j++)
			{
				m_boardXL[i][j] = '-';
			}
		}
		}
		else {
			numRows = 9;
			numCols = 9;
			for(int i=0; i<numRows; i++)
			{
				for(int j=0; j<numCols; j++)
				{
					m_board[i][j] = '-';
				}
			}
		}

	}

Board::~Board() {}

void Board::printBoard()
{
	bool big = checkBig();
	int sideNum = 1;
	for(int i=0; i<numRows; i++)
	{
		for(int j=0; j<numCols; j++)
		{
			if(i == 0 && j == 0)
			{
				cout << "  ";
				for(char c = 'A'; c <= 'A' + numCols; c++)
				{
					cout << c << " ";
				}
				cout << "\n";
			}
			if(j == 0)
			{
				cout << sideNum << " ";
			}
			if(big)
			{
			cout << m_boardXL[i][j] << " ";
			}
			else
			{
				cout << m_board[i][j] << " ";
			}
		}
		sideNum++;
		cout << "\n";
	}
}



void Board::updateBoard(int row, int col, char c)
{
	bool big = checkBig(); 
	if(big) {
	m_boardXL[row][col] = c;
	}
	else {
	m_board[row][col] = c;
	}
}

char Board::getValue(int row, int col)
{
	bool big = checkBig();
	if(big) {
	return m_boardXL[row][col];
	}
	else {
	return m_board[row][col];
	}
}

bool Board::checkBig()
{
	if(numRows == 20)
	{
		return true;
	}
	else { return false; }
}
