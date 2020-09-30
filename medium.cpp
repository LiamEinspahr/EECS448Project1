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
                if (otherShip.isSunk()){
                    cout << "The machine Wins!\n";
                }
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

    }
}

/*bool Medium::Coordinates(int row, int col){
    if()
}*/

bool Medium:: isValidMove(int row, char col){

}