//Player.cpp

#include "Executive.h"
#include "board.h"
#include <iostream>

Player::Player() {

}

Player::~Player() {}

void Player::SetNumShips(int ships) {numShips = ships; }

void Player::PrintMyShips()
{
  bool big = checkPlayerBig();
  if(big)
  {
   my_shipsXL.printBoard();
  }
  else
  {
    my_ships.printBoard();
  }
}

void Player::PrintEnemyShips()
{
  bool big = checkPlayerBig();
  if(big)
  {
    enemy_shipsXL.printBoard();
  }
  else
  {
    enemy_ships.printBoard();
  }
}

void Player::UpdateEnemyBoard(int row, int col, bool hit)
{
  bool big = checkPlayerBig();
  if(big)
  {
    if (hit) enemy_shipsXL.updateBoard(row, col, 'X');
    else enemy_shipsXL.updateBoard(row, col, 'O');
  }
  else
  {
    if (hit) enemy_ships.updateBoard(row, col, 'X');
    else enemy_ships.updateBoard(row, col, 'O');
  }
}

bool Player::PlaceShip(int size, int row, int col, char direction)
{

  bool big = checkPlayerBig();
  int boardSize;
  Board fake_board = Board(true);
  Board* my_board = &fake_board;
  //my_board->printBoard();
  if(big) {
    boardSize = 20;
    my_board = &my_shipsXL;
  }
  else {
    boardSize = 9;
    my_board = &my_ships;
  }

  //my_board->printBoard();
  /*for(int i = 0; i < 20; i++)
  {
    for(int j = 0; j < 20; j++)
    {
      cout<<my_board->getValue(i, j);
    }
    cout << "\n";
  }*/

    if (direction == 'R') // try to place ship right of pivot coordinates row, col
    {
        if ((boardSize - col) >= size) // make sure there are enough indices to place ship
        {
            for (int j = col; j < col + size; j++) // make sure no ships have already been placed in each spot
            {
                if (my_board->getValue(row, j) != '-')
                {
                  return false;
                }  // fails to place if something is already there
            }
            for (int j = col; j < col + size; j++)
            {
                my_board->updateBoard(row, j, 'S', size); // if not returned by now, place ship
            }
        }
        else return false; // fails to place if not enoguh space
    }
    else if (direction == 'L') // Left
    {
        if (col - size + 1 >= 0)
        {
            for (int j = col; j >= col - size + 1; j--)
            {
                if (my_board->getValue(row, j) != '-') return false;
            }
            for (int j = col; j >= col - size + 1; j--)
            {
                my_board->updateBoard(row, j, 'S', size);
            }
        }
        else return false;
    }
    else if (direction == 'D') // Down
    {
        if ((boardSize - row) >= size)
        {
            for (int i = row; i < row + size; i++)
            {
                if (my_board->getValue(i, col) != '-') return false;
            }
            for (int i = row; i < row + size; i++)
            {
                my_board->updateBoard(i, col, 'S', size);
            }
        }
        else return false;
    }
    else if (direction == 'U') // Up
    {
        if ((row - size) + 1 >= 0)
        {
            for (int i = row; i >= row - size + 1; i--)
            {
                if (my_board->getValue(i, col) != '-')
                {
                  cout << "in u statement";
                    //cout << '>' + my_board.getValue(i, col) + '<';
                    //cout << "nope because " << my_ships.getValue(i, col);
                    return false;
                }
            }
            for (int i = row; i >= row - size + 1; i--)
            {
                my_board->updateBoard(i, col, 'S', size);
            }
        }

        else {
          return false;
        }
    }

    else if (direction == 'V') // L-shaped ship
    {
        if(9-row >= 4 && 9-col>=4)
        {
            for (int i = row; i < row + 4; i++)
            {
                 if (my_board->getValue(i, col) != '-') return false;
            }
            for (int i = row; i < row + 4; i++)
            {
                my_board->updateBoard(i, col, 'S', 7);
            }
                        for (int j = col+1; j < col + 4; j++) // make sure no ships have already been placed in each spot
            {
                if (my_board->getValue(row, j) != '-') return false; // fails to place if something is already there
            }
            for (int j = col+1; j < col + 4; j++)
            {
                 my_board->updateBoard(row, j, 'S', 7); // if not returned by now, place ship
            }
        }
        else return false;
    }

    else if (direction == 'N') // L-shaped ship
    {
        if(9-row >= 2 && 9-col>=3)
        {
            for (int i = row; i < row + 2; i++)
            {
                 if (my_board->getValue(i, col) != '-') return false;
            }
            for (int i = row; i < row + 2; i++)
            {
                my_board->updateBoard(i, col, 'S', 5);
            }
            for (int j = col+1; j < col + 3; j++) // make sure no ships have already been placed in each spot
            {
                if (my_board->getValue(row, j) != '-') return false; // fails to place if something is already there
            }
            for (int j = col+1; j < col + 3; j++)
            {
                 my_board->updateBoard(row, j, 'S', 5); // if not returned by now, place ship
            }
            if(my_board->getValue(row+1, col+2) != '-') return false;
            else my_board->updateBoard(row+1, col+2, 'S', 5);
        }
        else return false;
    }

    return true;

}

bool Player::PlaceShipAI(int size, int row, int col, char direction)
{
    if (direction == 'R') // try to place ship right of pivot coordinates row, col
    {
        if (9 - col >= size) // make sure there are enough indices to place ship
        {
            for (int j = col; j < col + size; j++) // make sure no ships have already been placed in each spot
            {
                if (my_ships.getValue(row, j) != '-') return false; // fails to place if something is already there
            }
            for (int j = col; j < col + size; j++)
            {
                my_ships.updateBoard(row, j, 'S', size); // if not returned by now, place ship
            }
        }
        else return false; // fails to place if not enoguh space
    }
    else if (direction == 'L') // Left
    {
        if (col - size + 1 >= 0)
        {
            for (int j = col; j >= col - size + 1; j--)
            {
                if (my_ships.getValue(row, j) != '-') return false;
            }
            for (int j = col; j >= col - size + 1; j--)
            {
                my_ships.updateBoard(row, j, 'S', size);
            }
        }
        else return false;
    }
    else if (direction == 'D') // Down
    {
        if (9 - row >= size)
        {
            for (int i = row; i < row + size; i++)
            {
                if (my_ships.getValue(i, col) != '-') return false;
            }
            for (int i = row; i < row + size; i++)
            {
                my_ships.updateBoard(i, col, 'S', size);
            }
        }
        else return false;
    }
    else if (direction == 'U') // Up
    {
        if (row - size + 1 >= 0)
        {
            for (int i = row; i >= row - size + 1; i--)
            {
                if (my_ships.getValue(i, col) != '-')
                {
                    //cout << "nope because " << my_ships.getValue(i, col);
                    return false;
                }
            }
            for (int i = row; i >= row - size + 1; i--)
            {
                my_ships.updateBoard(i, col, 'S', size);
            }
        }
        else return false;
    }
    return true;

}

bool Player::CheckHit(int row, int col)
{
    bool big = checkPlayerBig();
    if(big){
      if (row > 19 || row < 0 || col > 19 || col < 0 || my_shipsXL.getValue(row, col) == 'X') return false;
      else{
        my_shipsXL.updateBoard(row, col, 'X');
        return true;
      }
      return false;
      }
    else {
      if (row > 8 || row < 0 || col > 8 || col < 0 || my_ships.getValue(row, col) == 'X') return false;
      else
      {
          my_ships.updateBoard(row, col, 'X');
          return true;
      }
      return false;
    }
  }

  bool Player::checkPlayerBig()
  {
    Executive exec;
    bool big = exec.checkForBig();
    cout << big;
    return big;

  }
