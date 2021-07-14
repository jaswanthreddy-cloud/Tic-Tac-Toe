// File Name : GameState.cpp
// Author: Jaswanth reddy matta
// Date: 11/15/2020
//
// Contains memeber functios which have a capability of
// generating current player, adding and removing a
// move to the board, displaying the current board state
// and checks which player has won.

#include "GameState.h"
#include<stdio.h>

using namespace std;

//***********************************************************
// GameState: intializes '_' at every index on the board
//***********************************************************
GameState::GameState(){
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			boardState[i][j] = '_';
        }
    }
}

//***********************************************************
//getCurrentPlayer: gives out the player that has to make the next turn.
//Return : player '0 ' or '1'
//***********************************************************
int GameState::getCurrentPlayer(){
	if (moveStack.getSize() % 2 == 0){
		return 0;
	}
	else{
		return 1;
	}
}

//***********************************************************
//addMove:  Updates the state of the board and stack of the past
//          moves given a move of the current player.
//Return :
//If the turn is invalid (the target position is not empty)
//       it returns -1.
//If all positions are filled, it returns 0.
//If the move was successfully done and there are moves available,
//       it returns 1.
//***********************************************************
int GameState::addMove(Move move){
	char player = this->getCurrentPlayer() ? 'o' : 'x';
	if (moveStack.getSize() == 9){
		return 0;
	}
	else if (boardState[move.x][move.y] != '_'){
		return -1;
	}
	else{
		boardState[move.x][move.y] = player;
		moveStack.push(move);
		if (moveStack.getSize() == 9){
			return 0;
		}
		else{
			return 1;
		}
	}
}

//***********************************************************
//undoLast: Undoes the last turn by changing the board state to the
//          previous one and removing the last move from the stack.
//Returns : Returns true if the move was removed,
//            false if there are no moves to undo
//***********************************************************
bool GameState::undoLast() {
	if (moveStack.getSize() == 0){
		return false;
    }
	Move value = moveStack.top();
	moveStack.pop();
	boardState[value.x][value.y] = '_';
	return true;
}

//***********************************************************
//displayBoardState: Prints the board state to the "out" stream.
//***********************************************************
void GameState::displayBoardState(std::ostream& out){
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			out << boardState[i][j];
        }
		out << endl;
	}
}

//***********************************************************
//checkLastPlayerWin: gives out the winner.
//***********************************************************
bool GameState::checkLastPlayerWin() {
	char targetSymbol = this->getCurrentPlayer() ? 'x' : 'o';
	int sumHorizontal, sumVertical;
	for (int i = 0; i < 3; ++i){
		sumHorizontal = 0;
		sumVertical = 0;
		for (int j = 0; j < 3; ++j){
			sumHorizontal += this->boardState[i][j] == targetSymbol;
			sumVertical += this->boardState[j][i] == targetSymbol;
        }
		if (sumHorizontal == 3 || sumVertical == 3)
			return true;
    }
	int sumDiagonal1 = 0, sumDiagonal2 = 0;
	for (int i = 0; i < 3; ++i){
		sumDiagonal1 += this->boardState[i][i] == targetSymbol;
		sumDiagonal2 += this->boardState[i][2 - i] == targetSymbol;
    }
	if (sumDiagonal1 == 3 || sumDiagonal2 == 3)
		return true;

	return false;
}
