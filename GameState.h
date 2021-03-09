// File Name : GameState.h
// Author: Jaswanth reddy matta
// Date: 11/15/2020
//class file for Tic Tac Toe

#ifndef LAB6_PART1_GAMESTATE_H
#define LAB6_PART1_GAMESTATE_H
#include <iostream>
#include "MoveStack.h"


class GameState {
    char boardState[3][3];
    MoveStack moveStack;
public:
    explicit GameState();
    int getCurrentPlayer();
    int addMove(Move move);
    bool undoLast();
    void displayBoardState(std::ostream& out);
    bool checkLastPlayerWin();
};



#endif //LAB6_PART1_GAMESTATE_H
