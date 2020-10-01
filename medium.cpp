//MEDIUM CPP


#include "medium.h"

Medium::Medium(){
    row = 0;
    col = 0;
}

int Medium::charToInt(char c) {return ((toupper(c) - 65));}

int Medium:: randomNum(){
    //add more conditions if they choose the xl board
    row = (rand() % 9) + 1;
    return(row);
}

int Medium:: randomChar(){
    char c;
    int r;
    int key;

    srand (time(NULL));
    r = rand() % 9;
    c = 'a' + r;
    key = charToInt(c);
    col = key;
    return(col);
}

int Medium::getRow(){
    return(row);
}

int Medium:: getCol(){
    return(col);
}

void Medium::checkSpace(int row, int col){
  if (otherPlayer.CheckHit(row, col))
  {
      otherShip.setHit();
      currentPlayer.UpdateEnemyBoard(row, col, true);
      otherPlayer.my_ships.updateBoard(row, col, 'X'); //checking
      if (otherShip.isSunk()){
          cout << "The machine Wins!\n";
          //break;
      }
      //if that singular ship isnt sunk then:
          //attackShip = true;
          //hitRow = row;
          //hitCol = col;
          //break;
      //else if that singular ship is sunk but you still have another ship then:
          //attackShip = false;
          //break;
      //break;
  }
  else
  {
      currentPlayer.UpdateEnemyBoard(row, col, false);
      otherPlayer.my_ships.updateBoard(row, col, 'O');
      //break;
  }
}


void Medium::solve(Player &currentPlayer, Player &otherPlayer, Ship &currentShip, Ship &otherShip){

    if(!attackShip){

        while(true){

            row = machine.randomNum();
            col = machine.randomChar();
            row --;

            if (otherPlayer.CheckHit(row, col))
            {
                otherShip.setHit();
                currentPlayer.UpdateEnemyBoard(row, col, true);
                otherPlayer.my_ships.updateBoard(row, col, 'X'); //checking
                if (otherShip.isSunk()){
                    cout << "The machine Wins!\n";
                    break;
                }
                //if that singular ship isnt sunk then:
                    //attackShip = true;
                    //hitRow = row;
                    //hitCol = col;
                    //break;
                //else if that singular ship is sunk but you still have another ship then:
                    //break;
                break;
            }
            else if(otherPlayer.my_ships.getValue(row, col) == 'X' || currentPlayer.enemy_ships.getValue(row, col) == 'O')
            {
                cout << " ";
            }
            else
            {
                currentPlayer.UpdateEnemyBoard(row, col, false);
                otherPlayer.my_ships.updateBoard(row, col, 'O');
                break;
            }
        }

    }
    else if (attackShip){
      if(isValidMove(row-1, col)){ //--- CHECKING UP
        //then you can move there
        checkSpace(row-1,col);
      }
      else if(isValidMove(row, col+1)){ //--- CHECKING RIGHT
        //then you can move there
      }
      else if(isValidMove(row+1, col)){ //--- CHECKING DOWN
        //then you can move
      }
      else if(isValidMove(row, col-1)){ //--- CHECKING LEFT
        //then you can move there
      }

        /*
            --check if is not filled with 'X' 'O' OR is off the board
                --then that is your spot to guess.
            -- if spot is an 'X'
        */

    }
}

void Medium::move(int row, int col){

}


bool Medium:: isValidMove(int row, char col){
  if(machine.getGameMode() == 'N'){
    if((row < 0) || (row > 8)){
      return false;
    }
    else if((col < 0) || (col > 8){
      return false;
    }
    else if(otherPlayer.my_ships.getValue(row, col) == 'X' || currentPlayer.enemy_ships.getValue(row, col) == 'O'){
      return false;
    }
    else{
      return true;
  }
}

/*bool Medium::Coordinates(int row, int col){
    if()
}*/
