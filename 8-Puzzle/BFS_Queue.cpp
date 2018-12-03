/*********************************************************************************
author:		Stephen Cordasco
project:	AI Project - 8-puzzle with BFS AI and A* AI
class:		CS 481 - AI
instructor:	Dr. Han
date:		18 October 2018
*********************************************************************************/
#include <iostream>
#include "BFS_Queue.h"
#include "State.h"
#include "Piece.h"

/*********************************************************************************
name:		BFS_Queue
parameters:	none
purpose:	default constructor for queue class; initializes front and end
			pointers to null
*********************************************************************************/
BFS_Queue::BFS_Queue()
{
	front = nullptr;
	end = nullptr;
}

/*********************************************************************************
name:		~BFS_Queue
parameters:	none
purpose:	deallocates memory used by queue
*********************************************************************************/
BFS_Queue::~BFS_Queue()
{
	// pop all nodes off queue
	clear();
}

/*********************************************************************************
name:		enqueue
parameters:	Pointer to Piece object array
purpose:	adds a node to front of queue if empty else adds a node to end of
			queue
*********************************************************************************/
void BFS_Queue::enqueue(Piece *nState)
{
	// queue is empty
	if (isEmpty())
	{
		front = new State(nState);
		end = front;
	}
	// queue is not empty, addd node to end
	else
	{
		end->next = new State(nState);
		end = end->next;
	}
}

/*********************************************************************************
name:		dequeue
parameters:	none
purpose:	pops a node off front of queue; returns if queue is empty
*********************************************************************************/
void BFS_Queue::dequeue()
{
	// temp pointer
	State *temp;

	// queue is empty
	if (isEmpty())
	{
		std::cout << "\nQueue is empty\n";
		return;
	}
	// queue is not empty
	else
	{
		// temp points to front
		temp = front;
		// front pointer points to next node in queue
		front = front->next;
		// delete temp pointer
		delete temp;
	}
}

/*********************************************************************************
name:		isEmpty
parameters:	none
purpose:	returns true if queue is empty otherwise returns false
*********************************************************************************/
bool BFS_Queue::isEmpty() const
{
	if (front == nullptr)
		return true;
	else
		return false;
}

/*********************************************************************************
name:		clear
parameters:	none
purpose:	pops off nodes off queue
*********************************************************************************/
void BFS_Queue::clear()
{
	while (!isEmpty())
	{
		dequeue();
	}
}

/*********************************************************************************
name:		bruteForceSearch
parameters:	Pointer to Piece object array (2x)
purpose:	custom brute force search algorithm, creates state space while
			searching for goal state
*********************************************************************************/
void BFS_Queue::bruteForceSearch(Piece *initialState, Piece *goalState)
{
	// variable used to count number of states searched
	int numStates = 0;
	// add the initial state to the front of the queue
	enqueue(initialState);
	// stores current state; used to check for new states and goal state found
	Piece *prev = new Piece[9];
	// pointers to legal moves that can be made from current state
	Piece *left, *up, *right, *down;

	while (isNewState(prev, goalState))
	{
		// pointer to the front of the queue
		Piece *next = front->state;
		// store value returned by try functions
		left = new Piece[9];
		up = new Piece[9];
		right = new Piece[9];
		down = new Piece[9];
		// deep copy on piece pointers storing the "current" value of next pointer
		std::copy(next, next + 9, prev);
		std::copy(next, next + 9, left);
		std::copy(next, next + 9, up);
		std::copy(next, next + 9, right);
		std::copy(next, next + 9, down);
		// print state
		printState(next);
		// pop front node
		dequeue();
		// increment number of states searched
		numStates++;

		// try moves
		left = tryLeft(left);
		// check if move creates new state
		if (isNewState(left, prev))
		{
			enqueue(left);
		}
		up = tryUp(up);
		if (isNewState(up, prev))
		{
			enqueue(up);
		}
		right = tryRight(right);
		if (isNewState(right, prev))
		{
			enqueue(right);
		}
		down = tryDown(down);
		if (isNewState(down, prev))
		{
			enqueue(down);
		}
	}
	// print message to screen
	std::cout << "\nGoal state found!\n";
	// print number of states searched
	std::cout << "States searched: " << numStates << "\n";
	std::cout << "Press ENTER to continue...";
	std::cin.get();
	std::cin.get();
}

/*********************************************************************************
name:		isNewState
parameters:	Pointer to Piece object array (2x)
purpose:	compares to states; returns true if different otherwise returns false
*********************************************************************************/
bool BFS_Queue::isNewState(Piece *current, Piece *prev)
{
	for (int i = 0; i < 9; i++)
	{
		if (current[i].getValue() != prev[i].getValue())
		{
			return true;
		}
	}
	return false;
}

/*********************************************************************************
name:		printState
parameters:	Pointer to Piece object array
purpose:	prints the state passed as parameter
*********************************************************************************/
void BFS_Queue::printState(Piece *current) const
{
	// helper variable
	int count = 0;

	// display state
	std::cout << "-------\n";
	for (int i = 0; i < 9; i++)
	{
		std::cout << "|" << current[i].getValue();
		count++;
		if (count == 3)
		{
			std::cout << "|\n";
			count = 0;
		}
	}
	std::cout << "-------\n";
}

/*********************************************************************************
name:		tryLeft
parameters:	Pointer to Piece object array
purpose:	performs a legal left move
*********************************************************************************/
Piece *BFS_Queue::tryLeft(Piece *arr)
{
	for (int i = 0; i < 9; i++)
	{
		// check for blank piece
		if (arr[i].getValue() == 0)
		{
			// check for invalid move
			if (i == 0 || i == 3 || i == 6)
			{
				return arr;
			}
			// move the piece
			Piece temp = arr[i - 1];
			arr[i - 1].setValue(0);
			arr[i - 1].setBlank(true);
			arr[i].setValue(temp.getValue());
			arr[i].setBlank(temp.isBlank());
		}
	}
	return arr;
}

/*********************************************************************************
name:		tryUp
parameters:	Pointer to Piece object array
purpose:	performs a legal up move
*********************************************************************************/
Piece *BFS_Queue::tryUp(Piece *arr)
{
	for (int i = 0; i < 9; i++)
	{
		// check for blank piece
		if (arr[i].getValue() == 0)
		{
			// check for invalid move
			if (i == 0 || i == 1 || i == 2)
			{
				return arr;
			}
			// move the piece
			Piece temp = arr[i - 3];
			arr[i - 3].setValue(0);
			arr[i - 3].setBlank(true);
			arr[i].setValue(temp.getValue());
			arr[i].setBlank(temp.isBlank());
		}
	}
	return arr;
}

/*********************************************************************************
name:		tryRight
parameters:	Pointer to Piece object array
purpose:	performs a legal right move
*********************************************************************************/
Piece *BFS_Queue::tryRight(Piece *arr)
{
	for (int i = 0; i < 9; i++)
	{
		// check for blank piece
		if (arr[i].getValue() == 0)
		{
			// check for invalid move
			if (i == 2 || i == 5 || i == 8)
			{
				return arr;
			}
			// move the piece
			Piece temp = arr[i + 1];
			arr[i + 1].setValue(0);
			arr[i + 1].setBlank(true);
			arr[i].setValue(temp.getValue());
			arr[i].setBlank(temp.isBlank());
			// return to function call to prevent continued execution
			return arr;
		}
	}
	return arr;
}

/*********************************************************************************
name:		tryDown
parameters:	Pointer to Piece object array
purpose:	performs a legal down move
*********************************************************************************/
Piece *BFS_Queue::tryDown(Piece *arr)
{
	for (int i = 0; i < 9; i++)
	{
		// check for blank piece
		if (arr[i].getValue() == 0)
		{
			// check for invalid move
			if (i == 6 || i == 7 || i == 8)
			{
				return arr;
			}
			// move the piece
			Piece temp = arr[i + 3];
			arr[i + 3].setValue(0);
			arr[i + 3].setBlank(true);
			arr[i].setValue(temp.getValue());
			arr[i].setBlank(temp.isBlank());
			// return to main to prevent continued execution
			return arr;
		}
	}
	return arr;
}