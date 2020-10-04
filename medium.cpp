//MEDIUM CPP

#include "medium.h"

Medium::Medium() {
    row = 0;
    col = 0;
}

bool Medium::notInArray(int row, int col){
    if((row == hitRow) && (col == hitCol)){
        return false;
    }
    for(int i = 0; i< value; i++){
        if((hitGuess[i][0] == row) && (hitGuess[i][1] == col)){
            return false;
        }
    }
    return true;
}



void Medium::guessSpot(int row, int col){
    if (otherPlayer->CheckHit(row, col)){
        currentPlayer->enemy_ships.updateBoard(row, col, 'X');
        otherPlayer->my_ships.updateBoard(row,col, 'X');
        if (otherPlayer->my_ships.allShipsSunk()){
            cout << "The Machine wins!\n";
        }
        else{
            if(otherPlayer->my_ships.shipIsSunk(row,col)){
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

    if(hits == value){
        return true;
    }

    if(checkCoords(row-1,col)){

        if((otherPlayer->my_ships.getValue(row-1, col) == 'S') && (otherPlayer->my_ships.getShipNum(row-1,col) == shipKey))
        {
            if(notInArray(row-1,col)){
                hitGuess[hits][0] = row -1;
                hitGuess[hits][1] = col;
                hits++;
                if(move(row-1,col)){
                    return true;
                }
            }
        }
    }
    if(checkCoords(row,col+1)){
        if((otherPlayer->my_ships.getValue(row, col+1) == 'S') && (otherPlayer->my_ships.getShipNum(row,col+1) == shipKey)){
            if(notInArray(row,col+1)){
                hitGuess[hits][0] = row;
                hitGuess[hits][1] = col+1;
                hits++;
                if(move(row,col+1)){
                    return true;
                }
            }
        }
    }
    if(checkCoords(row+1,col)){
        if((otherPlayer->my_ships.getValue(row+1, col) == 'S') && (otherPlayer->my_ships.getShipNum(row+1,col) == shipKey)){
            if(notInArray(row+1,col)){
                hitGuess[hits][0] = row + 1;
                hitGuess[hits][1] = col;
                hits++;
                if(move(row+1,col)){
                    return(true);
                }
            }
        }
    }
    if(checkCoords(row,col-1)){
        if((otherPlayer->my_ships.getValue(row, col-1) == 'S') && (otherPlayer->my_ships.getShipNum(row,col-1) == shipKey)){
            if(notInArray(row,col-1)){
                hitGuess[hits][0] = row;
                hitGuess[hits][1] = col - 1;
                hits++;
                if(move(row,col-1)){
                    return true;
                }
            }
        }
    }
    return false;
}


void Medium::solve(Player &currentPlayer1, Player &otherPlayer1){
    currentPlayer = &otherPlayer1;
    otherPlayer = &currentPlayer1;
    if(!attackShip){
        row = machine.randomNum();
        col = machine.randomChar();

        while(currentPlayer->enemy_ships.getValue(row, col) == 'X' || currentPlayer->enemy_ships.getValue(row, col) == 'O'){
            row = machine.randomNum();
            col = machine.randomChar();
        }

        if (otherPlayer->CheckHit(row, col)){
            currentPlayer->enemy_ships.updateBoard(row, col, 'X');
            otherPlayer->my_ships.updateBoard(row,col, 'X');
            if (otherPlayer->my_ships.allShipsSunk()){
                cout << "The Machine wins!\n";
            }
            else{
                if(!(otherPlayer->my_ships.shipIsSunk(row,col))){

                    attackShip = true;
                    hitRow = row;
                    hitCol = col;
                }
                else{
                    cout<<"we just sunk a ship\n";
                    attackShip = false;
                }
            }
        }
        else{
            currentPlayer->enemy_ships.updateBoard(row, col, 'O');
            otherPlayer->my_ships.updateBoard(row,col,'O');
        }

    }
    else{
        if(!haveGuesses){
            haveGuesses = true;
            value = otherPlayer->my_ships.getShipNum(hitRow,hitCol) - 1;
            shipKey = otherPlayer->my_ships.getShipNum(hitRow,hitCol);
            if(value == 0){
                cout<<"issue\n";
            }
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
            else{
                cout<<"your move is returning FALSE\n";
            }
        }
        else{
            row = hitGuess[tracking][0];
            col = hitGuess[tracking][1];
            tracking++;
            guessSpot(row,col);
        }

    }
}

bool Medium::checkCoords(int row, int col){
    if((row < 0) || (row > 8)){
        return false;
    }
    else if((col < 0) || (col > 8)){
        return false;
    }
    else if((currentPlayer->enemy_ships.getValue(row, col) == 'X' || currentPlayer->enemy_ships.getValue(row, col) == 'O')){
        return false;
    }
    return true;
}
