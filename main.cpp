// File Name : main.cpp
// Author: Jaswanth reddy matta
// Date: 11/15/2020
// Driver program for Tic Tac Toe.
//Contains the main game loop

#include<stdio.h>
#include <iostream>
#include "GameState.h"

using namespace std;

int main(){
	GameState gameState;
    string input ="";
    int x,y;
    gameState.displayBoardState(cout);

    while(true) {
        int currentPlayer = gameState.getCurrentPlayer();
        cout << "Player "<< currentPlayer << " make a turn." << endl;
        getline(cin,input);
		if(input.rfind("move", 0) == 0){   //checking if the 1st word is move
			x = input.at(5) - '0';
			y = input.at(7) - '0';
			int returnCode = gameState.addMove(Move(x, y));
			if (returnCode == 0) {
				gameState.displayBoardState(cout);
				cout << "It's a draw!" << endl;
                break;
            }
			else if (returnCode == -1) {
                cout << "Incorrect move. Please try again." << endl;
                continue;
            }
        }
		else if (input == "undo"){
			if (!gameState.undoLast()) {
				cout << "No moves to undo." << endl;
                continue;
            }
        }
		gameState.displayBoardState(cout);
		if (gameState.checkLastPlayerWin()) {
			cout << "Player " << currentPlayer << " won!" << endl;
            break;
        }
    }
    return 0;
}
