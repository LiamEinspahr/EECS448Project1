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
        numShips = 10;
				for(int i=0; i<numRows; i++)
				{
					for(int j=0; j<numCols; j++)
					{
						m_boardXL[i][j] = '-';
						m_board_shipsXL[i][j] = 0;
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
					m_board_ships[i][j] = 0;
				}
			}
		}

	}

Board::~Board() {}

void Board::printBoard()
{
	bool big = checkBig();
	if(big)
	{
		numRows = 20;
		numCols = 20;
	}
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

void Board::updateBoard(int row, int col, char c, int shipnum)
{
	bool big = checkBig();
	if(big) {
		if(c == 'S') {
			m_board_shipsXL[row][col] = shipnum;
			m_boardXL[row][col] = c;
		}
	}
	else {
    if (c == 'S') {
        m_board_ships[row][col] = shipnum;
				m_board[row][col] = c;
    }

	}
}

void Board::updateNumShips(int numships)
{
    numShips = numships;
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

int Board::getShipNum(int row, int col)
{
	return m_board_ships[row][col];
}

bool Board::shipNumIsSunk(int shipNum)
{
    for (int row=0; row < numRows; row++) {
        for (int col=0; col < numCols; col++) {
            if (m_board_ships[row][col] == shipNum && m_board[row][col] == 'S') {
                // Part of ship remains
                return false;
            }
        }
    }

    return true;
}
bool Board::shipIsSunk(int row, int col)
{
    return shipNumIsSunk(getShipNum(row, col));
}
bool Board::allShipsSunk()
{
    for (int shipnum = 1; shipnum <= numShips; shipnum++) {
        if (!shipNumIsSunk(shipnum)) {
            return false;
        }
    }
    return true;
}

int Board::getNumRows() {
    return numRows;
}

int Board::getNumCols() {
    return numCols;
}

int Board::getNumHits() {
    int hits = 0;
    for (int row=0; row < numRows; row++) {
        for (int col=0; col < numCols; col++) {
            if (m_board[row][col] == 'X') {
                hits++;
            }
        }
    }
    return hits;
}
