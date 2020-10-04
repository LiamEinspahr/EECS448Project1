
#include "Executive.h"
#include "player.h"
#include "display.h"
#include "machine.h"
#include "medium.h"
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
int getInt(string message, int lowerBound, int upperBound)
{

    bool inputSuccess;
    int userInt = 0;
    string boundMsg = " (" + std::to_string(lowerBound) + " : " + std::to_string(upperBound) + ")";
    cout << message << boundMsg << ": ";

    while (true)
    {
        cin >> userInt;
        inputSuccess = !cin.fail();
        if (!inputSuccess)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if (!inputSuccess || userInt < lowerBound || userInt > upperBound)
        {
            cout << "Please enter a number in" << boundMsg << ":";
        }
        else
        {
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
char getChar(string message, char lowerBound, char upperBound)
{

    string lowerStr(1, lowerBound);
    string upperStr(1, upperBound);

    bool inputSuccess;
    char userChar = 0;
    string boundMsg = " (" + lowerStr + " : " + upperStr + ")";
    cout << message << boundMsg << ": ";

    while (true)
    {
        cin >> userChar;
        inputSuccess = !cin.fail();
        if (!inputSuccess)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            userChar = toupper(userChar);
        }
        if (!inputSuccess || userChar < lowerBound || userChar > upperBound)
        {
            cout << "Please enter a character in" << boundMsg << ":";
        }
        else
        {
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
char getCharInOptions(string message, string options)
{

    bool inputSuccess;
    char userChar = 0;
    int numOptions = static_cast<int>(options.length());
    string boundMsg = " (";
    for (int optionNum = 0; optionNum < numOptions; optionNum++)
    {
        boundMsg += options.substr(optionNum, 1);
        if (optionNum < numOptions - 1)
        {
            boundMsg += ", ";
        }
    }
    boundMsg += ")";
    cout << message << boundMsg << ": ";

    while (true)
    {
        cin >> userChar;
        inputSuccess = !cin.fail();
        if (!inputSuccess)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Please enter a character in" << boundMsg << ":";
            continue;
        }
        else
        {
            userChar = toupper(userChar);
        }

        bool found = false;
        for (int checkChar = 0; checkChar < numOptions; checkChar++)
        {
            if (userChar == options[checkChar])
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Please enter a character in" << boundMsg << ":";
        }
        else
        {
            break;
        }
    }

    return userChar;
}

int Executive::charToInt(char c) { return ((toupper(c) - 65)); }

int Executive::numShipCoords(int shipNum)
{
    int n = 0;

    for (int i = 1; i <= shipNum; i++)
    {
        n = n + i;
    }

    return n;
}

void Executive::WaitEnter()
{
    cin.ignore();
    cout << "Press ENTER to end turn...";
    cin.get();
    for (int i = 0; i <= 50; i++)
        cout << endl;
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
  Player player1;
  Player player2;
  int row, col;
  char c_col; // char version of the column
  Machine machine;
  bool humanOpponent = true;
  int maxShips = 5;

  Board& my_ships_p1 = player1.my_shipsXL;
  Board& enemy_ships_p1 = player1.enemy_shipsXL;
  Board& my_ships_p2 = player2.my_shipsXL;
  Board& enemy_ships_p2 = player2.enemy_shipsXL;
  //Board* big_board = &m_board;



  //char diff = getCharInOptions("What level of difficulty do you want to play: Easy, Medium, Hard?", "EMH");
	//machine.setDifficultyLevel(diff);

  char gamemode = getCharInOptions("Would you like to play normal Battleship or BattleshipXL?", "NX");
    if (gamemode == 'X')
    {
        maxShips = 10;
        m_big = true;
        my_ships_p1 = player1.my_shipsXL;
        enemy_ships_p1 = player1.enemy_shipsXL;
        my_ships_p2 = player2.my_shipsXL;
        enemy_ships_p2 = player2.enemy_shipsXL;
           //big_board = &m_boardXL;
    }
    else
    {
      m_big = false;
      my_ships_p1 = player1.my_ships;
      enemy_ships_p1 = player1.enemy_ships;
      my_ships_p2 = player2.my_ships;
      enemy_ships_p2 = player2.enemy_ships;
    }

    bool big = m_big;
    Display display = Display(big);

    char humanInput = getCharInOptions("Would you like to play against a Human or AI?", "HA");
    humanOpponent = (humanInput == 'H');

    //my_ships_p1.printBoard();

    /*Board& my_ships_p1 = my_ref_p1;
    Board& my_ships_p2 = my_ref_p2;
    Board& enemy_ships_p1 = enemy_ref_p1;
    Board& enemy_ships_p2 = enemy_ref_p2;*/

    if (!humanOpponent)
    {
        char diff = getCharInOptions("What level of difficulty do you want to play: Easy, Medium, Hard?", "EMH");
        machine.setDifficultyLevel(diff);
        machine.setGameMode(gamemode);
    }

    //shipnum = getInt("How many ships do you want to place in the grid?", 1, maxShips);
    if(big)
    {
      cout << "How many ships do you want to place in the grid (choose from 1 to 10)? ";
    }
    else
    {
      cout << "How many ships do you want to place in the grid (choose from 1 to 5)? ";
    }
    cin >> shipnum;
    player1.SetNumShips(shipnum);
    //shipofplayer1.SetNumShips(numShipCoords(shipnum));

    if (shipnum < 1 || shipnum > maxShips)
  	{
  		while (!(cin >> shipnum))
  		{
  			cout << "Invalid! Out of range!: ";
  			cin.clear();
  			cin.ignore(123, '\n');
  		}
    }

    my_ships_p1.updateNumShips(shipnum);
    enemy_ships_p1.updateNumShips(shipnum);
    my_ships_p2.updateNumShips(shipnum);
    enemy_ships_p2.updateNumShips(shipnum);

    int maxRow;
    char maxCol;

    if(big)
    {
      maxRow = 20;
      maxCol = 'T';
    }
    else
    {
      maxRow = 9;
      maxCol = 'I';
    }

    for (int i = 1; i <= shipnum; i++)
    {
      chooseShipPosition1:

    //blank Board
    char direction = 'u'; //default direction is up

    if(big)
    {
      display.friendlyBoardXL(my_ships_p1.m_boardXL);//now what about .m_board?!


    if (i == 1)
    {
      cout << "\nPlayer 1, Where do you want to place 1X" << i << " on the grid (row(1-20) col(A-T))? ";
      while(!(cin >> row)||row < 1 || row > 20)
      {
        cout << "Invalid input! Row must be 1-20!: ";
        cin.clear();
        cin.ignore(123, '\n');
      }
      cout << "Now enter a column A-T: ";
      cin >> c_col;
      cout << "\n";
      while(!validColumn(big, c_col))
      {
        cin >> c_col;
      }
      col = charToInt(c_col);
    }
    else
    {
      cout << "\nChoose a pivot coordinate for 1X" << i << " ship on the grid (row(1-20) col(A-T)): ";
      while (!(cin >> row)||row < 1 || row > 20)
      {
        cout << "Invalid input! Row must be 1-20!: ";
        cin.clear();
        cin.ignore(123, '\n');
      }
      cout << "Now enter a column A-T: ";
      cin >> c_col;
      while (!validColumn(big, c_col))
      {
        cin >> c_col;
      }
    }
    }
  else{ //if not big
    display.friendlyBoard(my_ships_p1.m_board);//now what about .m_board?!
  //char direction = 'u'; //default direction is up

  if (i == 1)
  {
    cout << "\nPlayer 1, Where do you want to place 1X" << i << " on the grid (row(1-9) col(A-I))? ";
    while(!(cin >> row)||row < 1 || row > 9)
    {
      cout << "Invalid input! Row must be 1-9!: ";
      cin.clear();
      cin.ignore(123, '\n');
    }
    cout << "Now enter a column A-I: ";
    cin >> c_col;
    cout << "\n";
    while(!validColumn(big, c_col))
    {
      cin >> c_col;
    }
    col = charToInt(c_col);
  }
  else
  {
    cout << "\nChoose a pivot coordinate for 1X" << i << " ship on the grid (row(1-9) col(A-I)): ";
    while (!(cin >> row)||row < 1 || row > 9)
    {
      cout << "Invalid input! Row must be 1-9!: ";
      cin.clear();
      cin.ignore(123, '\n');
    }
    cout << "Now enter a column A-I: ";
    cin >> c_col;
    while (!validColumn(big, c_col))
    {
      cin >> c_col;
    }
  }
  }

    chooseShipDirection1:
      cout << "Up, Down, Left, or Right from pivot? (U, D, L, R): ";
      cin >> direction;

    col = charToInt(c_col); // convert char to int
    row--; // decrement row by 1 for indexing array
    direction = toupper(direction);

    if (direction != 'U' && direction != 'D' && direction != 'L' && direction != 'R')
    {
      cout << "Invalid direction input!\n";
      goto chooseShipDirection1;
    }
    if (!player1.PlaceShip(i, row, col, direction)) //this should update it
    {
      cout << "Ship could not be placed there. \n";
      goto chooseShipPosition1;
    }
    /*else
    {
      if(big)
      {
      my_ships_p1.m_boardXL.updateBoard(row, col, 'S', i);
      }
      else
      {
      my_ships_p1.m_board.updateBoard(row, col, 'S', i);
      }
    }*/
  }

//print last time so player can see 1x5 ship placed
if(big){
  display.friendlyBoardXL(my_ships_p1.m_boardXL); //.m_board ??
}
else{
  display.friendlyBoard(my_ships_p1.m_board);
}


cout <<" Switch to Player 2 Setting!\n";
WaitEnter();

char direction = 'u'; //default direction is up
if(humanOpponent)
{
  if(big)
  {
    display.friendlyBoardXL(my_ships_p2.m_boardXL);//now what about .m_board?!
  }
  for (int i = 1; i <= shipnum; i++)
  {
    chooseShipPosition2:
  //blank Board
  if(big) {
  if (i == 1)
  {
    cout << "\nPlayer 2, Where do you want to place 1X" << i << " on the grid (row(1-20) col(A-T))? ";
    while(!(cin >> row)||row < 1 || row > 20)
    {
      cout << "Invalid input! Row must be 1-20!: ";
      cin.clear();
      cin.ignore(123, '\n');
    }
    cout << "Now enter a column A-T: ";
    cin >> c_col;
    cout << "\n";
    while(!validColumn(big, c_col))
    {
      cin >> c_col;
    }
    col = charToInt(c_col);
  }
  else //if i != 1
  {
    cout << "\nChoose a pivot coordinate for 1X" << i << " ship on the grid (row(1-20) col(A-T)): ";
    while (!(cin >> row)||row < 1 || row > 20)
    {
      cout << "Invalid input! Row must be 1-20!: ";
      cin.clear();
      cin.ignore(123, '\n');
    }
    cout << "Now enter a column A-T: ";
    cin >> c_col;
    while (!validColumn(big, c_col))
    {
      cin >> c_col;
    }
  }
  //display.friendlyBoard(my_ships_p2.m_boardXL);
  }
  else{ //if not big
  display.friendlyBoard(my_ships_p2.m_board);//now what about .m_board?!

if (i == 1)
{
  cout << "\nPlayer 2, Where do you want to place 1X" << i << " on the grid (row(1-9) col(A-I))? ";
  while(!(cin >> row)||row < 1 || row > 9)
  {
    cout << "Invalid input! Row must be 1-9!: ";
    cin.clear();
    cin.ignore(123, '\n');
  }
  cout << "Now enter a column A-I: ";
  cin >> c_col;
  cout << "\n";
  while(!validColumn(big, c_col))
  {
    cin >> c_col;
  }
  col = charToInt(c_col);
}
else
{
  cout << "\nChoose a pivot coordinate for 1X" << i << " ship on the grid (row(1-9) col(A-I)): ";
  while (!(cin >> row)||row < 1 || row > 9)
  {
    cout << "Invalid input! Row must be 1-9!: ";
    cin.clear();
    cin.ignore(123, '\n');
  }
  cout << "Now enter a column A-I: ";
  cin >> c_col;
  while (!validColumn(big, c_col))
  {
    cin >> c_col;
  }
}
    }

  chooseShipDirection2:
    cout << "Up, Down, Left, or Right from pivot? (U, D, L, R): ";
    cin >> direction;
  col = charToInt(c_col); // convert char to int
  row--; // decrement row by 1 for indexing array
  direction = toupper(direction);

  if (direction != 'U' && direction != 'D' && direction != 'L' && direction != 'R')
  {
    cout << "Invalid direction input!\n";
    goto chooseShipDirection2;
  }
  if (!player2.PlaceShip(i, row, col, direction))
  {
    cout << "Ship could not be placed there. \n";
    goto chooseShipPosition2;
  }
}

//print last time so player can see 1x5 ship placed
if(big){
display.friendlyBoardXL(my_ships_p2.m_boardXL); //.m_board ??
my_ships_p1.printBoard();
}
else{
display.friendlyBoard(my_ships_p2.m_board);
}
}
}
