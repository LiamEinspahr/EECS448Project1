
#include "Executive.h"
#include "player.h"
#include "display.h"
#include "Ship.h"
#include <iostream>
#include <limits>
#include <string>
using namespace std;

/**
 * @brief Get an int from a user between the given bounds. Repeat until successful.
 *
 * @param message A message to give the user before attempting.
 * @param lowerBound The minimum bound which the user may input.
 * @param upperBound The maximum bound the user may input.
 * @return int The integer the user selected.
 */
int getInt(string message, int lowerBound, int upperBound) {

    bool inputSuccess;
    int userInt = 0;
    string boundMsg = " (" + std::to_string(lowerBound) + " : " + std::to_string(upperBound) + ")";
    cout << message << boundMsg << ": ";

    while (true) {
        cin >> userInt;
        inputSuccess = !cin.fail();
        if (!inputSuccess) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if (!inputSuccess || userInt < lowerBound || userInt > upperBound) {
            cout << "Please enter a number in" << boundMsg << ":";
        } else {
            break;
        }
    }

    return userInt;
}

/**
 * @brief Get a char from a user between the given bounds. Repeat until successful. Only allows uppercase characters.
 *
 * @param message A message to give the user before attempting.
 * @param lowerBound The minimum character bound which the user may input.
 * @param upperBound The maximum character bound the user may input.
 * @return char The character the user selected.
 */
char getChar(string message, char lowerBound, char upperBound) {

    string lowerStr(1, lowerBound);
    string upperStr(1, upperBound);

    bool inputSuccess;
    char userChar = 0;
    string boundMsg = " (" + lowerStr + " : " + upperStr + ")";
    cout << message << boundMsg << ": ";

    while (true) {
        cin >> userChar;
        inputSuccess = !cin.fail();
        if (!inputSuccess) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            userChar = toupper(userChar);
        }
        if (!inputSuccess || userChar < lowerBound || userChar > upperBound) {
            cout << "Please enter a character in" << boundMsg << ":";
        } else {
            break;
        }
    }

    return userChar;
}

/**
 * @brief Get a char from a user from the options in the given string. Repeat until successful.
 *
 * @param message A message to give the user before attempting.
 * @param options A string of characters for the user to choose between.
 * @return char The character the user selected.
 */
char getCharInOptions(string message, string options) {

    bool inputSuccess;
    char userChar = 0;
    string boundMsg = " (" + options + ")";
    cout << message << boundMsg << ": ";

    while (true) {
        cin >> userChar;
        inputSuccess = !cin.fail();
        if (!inputSuccess) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Please enter a character in" << boundMsg << ":";
            continue;
        } else {
            userChar = toupper(userChar);
        }

        bool found = false;
        for (int checkChar = 0; checkChar < static_cast<int>(options.length()); checkChar++) {
            if (userChar == options[checkChar]) {
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Please enter a character in" << boundMsg << ":";
        } else {
            break;
        }
    }

    return userChar;
}

int Executive::charToInt(char c) {return ((toupper(c) - 65));}

int Executive::numShipCoords(int shipNum)
{
	int n = 0;

	for(int i = 1; i <= shipNum; i++)
	{
		n = n+i;
	}

	return n;
}

void Executive::WaitEnter()
{
	cin.ignore();
	cout << "Press ENTER to end turn...";
	cin.get();
	for (int i = 0; i <= 50; i++) cout << endl;
}

bool Executive::validColumn(bool big, char c)
{
  if(big){
	if (!isalpha(c) || (toupper(c) < 65 || toupper(c) > 84))
	{
		cout << "Invalid input! Column must be A-T!: ";
		return false;
	}
	else
	{
		return true;
	}
  }
  else{
    if (!isalpha(c) || (toupper(c) < 65 || toupper(c) > 73))
  	{
  		cout << "Invalid input! Column must be A-I!: ";
  		return false;
  	}
  	else
  	{
  		return true;
  	}
  }
}

void Executive::run()
{
	int shipnum = 0;

	Display display;
	Player player1;
	Player player2;

	int row, col;
	char c_col; // char version of the column
	Ship shipofplayer1;
	Ship shipofplayer2;

    int maxShips = 5;

	char gamemode = getCharInOptions("Would you like to play normal Battleship or BattleshipXL?", "NX");
    bool big;
    if (gamemode == 'X') {
        maxShips = 10;
        big = true;
    }
    else
    {
      big = false;
    }


    shipnum = getInt("How many ships do you want to place in the grid?", 1, maxShips);

	shipofplayer1.setShipNumber(numShipCoords(shipnum));
	shipofplayer2.setShipNumber(numShipCoords(shipnum));

    Player* currentPlayer = &player1;
    for (int currentPlayerNum = 1; currentPlayerNum <= 2; currentPlayerNum++) {
        cout << "Player " << currentPlayerNum << "\n";

        for (int currentShip = 1; currentShip <= shipnum; currentShip++)
        {
            while (true) {

                //blank regular Board
                if(big == false) {

                display.friendlyBoard(currentPlayer->my_ships.m_board);

                char direction = 'u'; //default direction is up

                if (currentShip == 1)
                {
                    row = getInt("Input the row in which you wish to place your 1x" + std::to_string(currentShip) + " ship", 1, 9);
                    c_col = getChar("Input the column in which you wish to place your 1x" + std::to_string(currentShip) + " ship", 'A', 'I');
                }
                else
                {
                    row = getInt("Input the row in which you wish to place your 1x" + std::to_string(currentShip) + " ship's pivot point", 1, 9);
                    c_col = getChar("Input the column in which you wish to place your 1x" + std::to_string(currentShip) + " ship's pivot point", 'A', 'I');
                    direction = getCharInOptions("Up, Down, Left, or Right from pivot? (U, D, L, R): ", "UDLR");
                }
                col = charToInt(c_col); // convert char to int
                row--; // decrement row by 1 for indexing array
                direction = toupper(direction);

                if (!currentPlayer->PlaceShip(big, currentShip, row, col, direction))
                {
                    cout << "Ship could not be placed there. \n";
                } else {
                    break;
                }
            }
            //blank XL Board
            else {
              display.friendlyBoard(currentPlayer->my_ships.m_boardXL);

              char direction = 'u'; //default direction is up

              if (currentShip == 1)
              {
                  row = getInt("Input the row in which you wish to place your 1x" + std::to_string(currentShip) + " ship", 1, 20);
                  c_col = getChar("Input the column in which you wish to place your 1x" + std::to_string(currentShip) + " ship", 'A', 'T');
              }
              else
              {
                  row = getInt("Input the row in which you wish to place your 1x" + std::to_string(currentShip) + " ship's pivot point", 1, 20);
                  c_col = getChar("Input the column in which you wish to place your 1x" + std::to_string(currentShip) + " ship's pivot point", 'A', 'T');
                  direction = getCharInOptions("Up, Down, Left, or Right from pivot? (U, D, L, R): ", "UDLR");
              }
              col = charToInt(c_col); // convert char to int
              row--; // decrement row by 1 for indexing array
              direction = toupper(direction);

              if (!currentPlayer->PlaceShip(big, currentShip, row, col, direction))
              {
                  cout << "Ship could not be placed there. \n";
              } else {
                  break;
              }
            }
            }
        }

        //print last time so player can see 1x5 ship placed
        display.friendlyBoard(currentPlayer->my_ships.m_boardXL);

        cout <<"Switch to next Player!\n";
        WaitEnter();

        currentPlayer = &player2;
    }


//      Playing part
	cout << "\nNow play battleship!\n";

	int round = 0;

    currentPlayer = &player1;
    Player* otherPlayer = &player2;
    Ship* currentShip = &shipofplayer1;
    Ship* otherShip = &shipofplayer2;

	while (!shipofplayer1.isSunk() && !shipofplayer2.isSunk())
	{
        if (round % 2) {
            currentPlayer = &player2;
            otherPlayer = &player1;
            currentShip = &shipofplayer2;
            otherShip = &shipofplayer1;
        } else {
            currentPlayer = &player1;
            otherPlayer = &player2;
            currentShip = &shipofplayer1;
            otherShip = &shipofplayer2;
        }
        int playerNum = (round % 2) + 1;

        cout << "Player " << playerNum << "'s turn!\n";
        cout << "You have been hit " << currentShip->getHit() << " times\n";
        //Print boards before fire
        if(big) {
        display.matchFrame(playerNum, currentPlayer->enemy_ships.m_boardXL, currentPlayer->my_ships.m_boardXL);
        }
        else {
          display.matchFrame(playerNum, currentPlayer->enemy_ships.m_board, currentPlayer->my_ships.m_board);
        }

        while (true) {
            if(big) {
            row = getInt("Input the row into which you wish to fire", 1, 20);
            c_col = getChar("Input the column into which you wish to fire", 'A', 'T');
            }
            else {
              row = getInt("Input the row into which you wish to fire", 1, 9);
              c_col = getChar("Input the column into which you wish to fire", 'A', 'I');
            }
            col = charToInt(c_col);
            row --;

            if (otherPlayer->CheckHit(big, row, col))
            {
                display.hit();
                otherShip->setHit();
                currentPlayer->UpdateEnemyBoard(big, row, col, true);
                if (otherShip->isSunk()){
                    cout << "Player " << playerNum << " wins!\n";
                }
                break;
            }
            else if(otherPlayer->my_ships.getValue(big, row, col) == 'X' || currentPlayer->enemy_ships.getValue(big, row, col) == 'O')
            {
                cout << "\n\nYou've already fired at that spot!\n";
            }
            else
            {
                display.miss();
                currentPlayer->UpdateEnemyBoard(big, row, col, false);
                otherPlayer->my_ships.updateBoard(big, row, col, 'O');
                break;
            }
        }
		round++;
		WaitEnter();
	}
}
