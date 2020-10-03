//MEDIUM CPP

#include "medium.h"

Medium::Medium(){
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
        //currentPlayer->UpdateEnemyBoard(row, col, true);
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
    //cout<<"made it inside move\n";

    if(hits == value){
        //cout<<"We have "<<hits<<" many guesses\n";
        return true;
    }
  
    if(checkCoords(row-1,col)){ 

        //cout<<"CHECKING IS THIS SPOT IS A HIT & RIGHT SHIP: \n";
        //cout<<"THE VALUE OF "<< row -1 << " "<< col <<" is: "<<otherPlayer->my_ships.getValue(row-1, col)<<'\n';
        //cout<<"THE SHIP NUMBER IS "<<otherPlayer->my_ships.getShipNum(row-1,col)<<" AND SHIPKEY IS: "<< shipKey<<"\n\n";

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

        //cout<<"CHECKING IS THIS SPOT IS A HIT & RIGHT SHIP: \n";
        //cout<<"THE VALUE OF "<< row  << " "<< col+1 <<" is: "<<otherPlayer->my_ships.getValue(row, col+1)<<'\n';
        //cout<<"THE SHIP NUMBER IS "<<otherPlayer->my_ships.getShipNum(row,col+1)<<" AND SHIPKEY IS: "<< shipKey<<"\n\n";

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

        //cout<<"CHECKING IS THIS SPOT IS A HIT & RIGHT SHIP: \n";
        //cout<<"THE VALUE OF "<< row +1 << " "<< col <<" is: "<<otherPlayer->my_ships.getValue(row+1, col)<<'\n';
        //cout<<"THE SHIP NUMBER IS "<<otherPlayer->my_ships.getShipNum(row+1,col)<<" AND SHIPKEY IS: "<< shipKey<<"\n\n";

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

        //cout<<"CHECKING IS THIS SPOT IS A HIT & RIGHT SHIP: \n";
        //cout<<"THE VALUE OF "<< row << " "<< col-1 <<" is: "<<otherPlayer->my_ships.getValue(row, col-1)<<'\n';
        //cout<<"THE SHIP NUMBER IS "<<otherPlayer->my_ships.getShipNum(row,col-1)<<" AND SHIPKEY IS: "<< shipKey<<"\n\n"; 

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
    //cout<<"!!!!!returning false for end of the line!!!!\n";
    return false;
}


void Medium::solve(Player &currentPlayer1, Player &otherPlayer1){
    currentPlayer = &otherPlayer1;
    otherPlayer = &currentPlayer1;
    if(!attackShip){
        //cout<<"THIS IS WHAT YOUR LOOKING FOR : "<< currentPlayer->my_ships.getValue(0,0)<<'\n';
        row = machine.randomNum();
        col = machine.randomChar();
        //cout<<"Row: "<<row<<'\n';
        //cout<<"Col: "<<col<<'\n';
        //cout<<"current player enery ships value at row col: "<<currentPlayer->enemy_ships.getValue(row, col)<<'\n';
        //cout<<"other player enemey ships value at row col: "<<otherPlayer->enemy_ships.getValue(row,col)<<'\n';
        //cout<<"other player myships value at row col: "<<otherPlayer->my_ships.getValue(row,col)<<'\n';
        //cout<<"current player myships ships value at row col: "<<currentPlayer->my_ships.getValue(row, col)<<'\n';
        while(true){
            if(currentPlayer->enemy_ships.getValue(row, col) == 'X' || currentPlayer->enemy_ships.getValue(row, col) == 'O'){//change to current play enermy ships
                row = machine.randomNum();
                col = machine.randomChar();
            }
            else{
                break;
            }
        }

        if (otherPlayer->CheckHit(row, col)){
            //cout<<"AI hit your board at: "<<row<<" "<<col<<"\n";
            //currentPlayer->UpdateEnemyBoard(row, col, true);
            currentPlayer->enemy_ships.updateBoard(row, col, 'X');
            otherPlayer->my_ships.updateBoard(row,col, 'X');
            if (otherPlayer->my_ships.allShipsSunk()){
                cout << "The Machine wins!\n";
            }
            else{
                if(!(otherPlayer->my_ships.shipIsSunk(row,col))){
                    //cout<<"109\n";
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
            //cout<<"AI missed your board at "<< row <<" "<< col<<"\n";
            //currentPlayer->UpdateEnemyBoard(row, col, false);
            currentPlayer->enemy_ships.updateBoard(row, col, 'O');
            otherPlayer->my_ships.updateBoard(row,col,'O');
            //cout<<"value at row col: "<< otherPlayer->my_ships.getValue(row,col)<<'\n';
        } 
        
    }
    else{
        if(!haveGuesses){
            //cout<<"131\n";
            haveGuesses = true;
            value = otherPlayer->my_ships.getShipNum(hitRow,hitCol) - 1;
            //cout<<"value: "<<value<<'\n';
            shipKey = otherPlayer->my_ships.getShipNum(hitRow,hitCol);
            //cout<<"shipkey: "<<shipKey<<'\n';
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

                //cout<<"THIS IS THE HIT ARRAY FOR GUESSES:\n";
                //int temp = 
                //for(int i = 0; i < value; i++){
                   // cout<<hitGuess[i][0]<< " "<< hitGuess[i][1]<<'\n';
               // }
                //cout<<'\n';
                
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
    //cout<<"WE ARE IN CHECK COORDS VIEWING LAST REQUIRMENT:\n";
    //cout<<"CurrentPlayer enemy ships at spot "<< row<<" "<< col<< " = "<<currentPlayer->enemy_ships.getValue(row, col)<<'\n';
    if((row < 0) || (row > 8)){
        //cout<<"returning false...\n";
        return false;
    }
    else if((col < 0) || (col > 8)){
        //cout<<"returning false...\n";
        return false;
    }
    else if((currentPlayer->enemy_ships.getValue(row, col) == 'X' || currentPlayer->enemy_ships.getValue(row, col) == 'O')){
        //cout<<"returning false..\n";
        return false;
    }
   // cout<<"returning true...\n";
    return true;
}