//MEDIUM CPP

#include "medium.h"

Medium::Medium(){
    row = 0;
    col = 0;
}

void Medium::guessSpot(int row, int col){
    if (otherPlayer.CheckHit(row, col)){
        currentPlayer.UpdateEnemyBoard(row, col, true);
        if (otherPlayer.my_ships.allShipsSunk()){
            cout << "The Machine wins!\n";
        }
        else{
            if(otherPlayer.my_ships.shipIsSunk(row,col)){
                hits = 0;
                haveGuesses = false;
                tracking = 0; 
                attackShip = false;
            }
        }
    }
    else{
        cout<<"You messed up again\n";
    }

}

bool Medium::move(int row, int col){
  
    if(checkCoords(row-1,col)){ 
        if(otherPlayer.my_ships.getValue(row-1, col) == 'X'){
            hitGuess[hits][row-1];
            hitGuess[hits][col];
            hits++;
            move(row-1,col);
            return true;
        }
    }
    if(checkCoords(row,col+1)){ 
        if(otherPlayer.my_ships.getValue(row, col+1) == 'X'){
            hitGuess[hits][row];
            hitGuess[hits][col+1];
            hits++;
            move(row,col+1);
            return true;
        }
    }
    if(checkCoords(row+1,col)){ 
        if(otherPlayer.my_ships.getValue(row+1, col) == 'X'){
            hitGuess[hits][row+1];
            hitGuess[hits][col];
            hits++;
            move(row+1,col);
            return true;
        }
    }
    if(checkCoords(row,col-1)){ 
        if(otherPlayer.my_ships.getValue(row, col-1) == 'X'){
            hitGuess[hits][row];
            hitGuess[hits][col-1];
            hits++;
            move(row,col-1);
            return true;
        }
    }
    return false;
}


void Medium::solve(Player &currentPlayer1, Player &otherPlayer1){
    currentPlayer = currentPlayer1;
    otherPlayer = otherPlayer1;
    cout<<"here med 79\n";
    if(!attackShip){
        row = machine.randomNum();
        col = machine.randomChar();
        cout<<"here med 79\n";
        //check to see if you have already guess that spot before
        while(true){
            if(otherPlayer.my_ships.getValue(row, col) == 'X' || currentPlayer.enemy_ships.getValue(row, col) == 'O'){
                row = machine.randomNum();
                col = machine.randomChar();
            }
            else{
                break;
            }
        }

        if (otherPlayer.CheckHit(row, col)){
            currentPlayer.UpdateEnemyBoard(row, col, true);
            if (otherPlayer.my_ships.allShipsSunk()){
                cout << "The Machine wins!\n";
            }
            else{
                if(!(otherPlayer.my_ships.shipIsSunk(row,col))){
                    attackShip = true;
                    hitRow = row; 
                    hitCol = col;
                }
            }
        }
        else{
            currentPlayer.UpdateEnemyBoard(row, col, false);
            otherPlayer.my_ships.updateBoard(row, col, 'O');
        } 
        
    }
    else{
        if(!haveGuesses){
            haveGuesses = true;
            int value = otherPlayer.my_ships.getShipNum(hitRow,hitCol) - 1;
            hitGuess = new int*[value];
            for(int i = 0; i < value; i++){
                hitGuess[i] = new int[2];
            } 

            if(move(row,col)){
                row = hitGuess[tracking][0];
                col = hitGuess[tracking][1];
                tracking++;
                guessSpot(row,col);
            }
        }

        row = hitGuess[tracking][0];
        col = hitGuess[tracking][1];
        tracking++;
        guessSpot(row,col);
    }     
}

bool Medium::checkCoords(int row, int col){
    if((row < 0) || (row > 8)){
        return false;
    }
    else if((col < 0) || (col > 8)){
        return false;
    }
    else if((otherPlayer.my_ships.getValue(row -1, col) == 'X' || currentPlayer.enemy_ships.getValue(row-1, col) == 'O')){
        return false;
    }
    return true;
}