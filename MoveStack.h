// File Name : MoveStack.h
// Author: Jaswanth reddy matta
// Date: 11/15/2020
// Driver program for Tic Tac Toe.
/*class file consists of function to find which is on top
    of the stack, inserting a move , deleting a move.*/

#ifndef LAB6_PART1_STACK_H
#define LAB6_PART1_STACK_H
#include <cassert>
#include<stdio.h>

struct Move{
	Move() : x(0), y(0){}
	Move(int x, int y) : x(x), y(y){}
	int x;
	int y;
};

class MoveStack
{
private:
	const static int STACKSIZE = 9;
	Move stackArray[STACKSIZE];
	int topp;		   //top

public:
	MoveStack() { topp = -1; }
	~MoveStack(){}
	int getSize() { return topp + 1; }
	Move top(){
		assert(getSize());
		return stackArray[topp];
    }
    void push(Move move){
		if (topp == (STACKSIZE - 1)) {
        }
		else{
			topp++;
			stackArray[topp] = move;
        }
    }
	void pop(){
		if (topp == -1){
        }
        else{
			topp--;
        }
    }
};

#endif //LAB6_PART1_STACK_H
