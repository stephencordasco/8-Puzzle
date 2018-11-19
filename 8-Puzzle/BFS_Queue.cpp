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

BFS_Queue::BFS_Queue()
{
	front = nullptr;
	end = nullptr;
}

BFS_Queue::~BFS_Queue()
{
	clear();
}

void BFS_Queue::enqueue(Piece *nState)
{
	if (isEmpty())
	{
		front = new State(nState);
		end = front;
	}
	else
	{
		end->next = new State(nState);
		end = end->next;
	}
}

void BFS_Queue::dequeue()
{
	State *temp;
	if (isEmpty())
	{
		cout << "Queue is empty.\n";
		return;
	}
	else
	{
		temp = front;
		front = front->next;
		//cout << "freeing memory\n";
		delete temp;
	}
}

bool BFS_Queue::isEmpty() const
{
	if (front == nullptr)
		return true;
	else
		return false;
}

void BFS_Queue::clear()
{
	while (!isEmpty())
	{
		dequeue();
	}
}

void BFS_Queue::BFS(Piece *initialState, Piece *goalState)
{
	// add the initial state to the front of the queue
	enqueue(initialState);
	// stores the current state; used to check for new states and goal state found
	Piece *prev = new Piece[9];

	while (isNewState(prev, goalState))
	{
		// pointer to the front of the queue
		Piece *next = front->state;
		// store the value returned by the try functions: memory leak potential? need solution
		Piece *left = new Piece[9];
		Piece *up = new Piece[9];
		Piece *right = new Piece[9];
		Piece *down = new Piece[9];
		// deep copy on the piece pointers storing the "current" value of next pointer
		copy(next, next + 9, prev);
		copy(next, next + 9, left);
		copy(next, next + 9, up);
		copy(next, next + 9, right);
		copy(next, next + 9, down);
		// print the state
		//Sleep(100);
		printState(next);
		// pop the front node
		dequeue();

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
	cout << "Goal state found!\n\n\n";
	clear();
}

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

void BFS_Queue::printState(Piece *current) const
{
	// helper variable
	int count = 0;

	// display the initial state
	cout << "-------\n";
	for (int i = 0; i < 9; i++)
	{
		cout << "|" << current[i].getValue();
		count++;
		if (count == 3)
		{
			cout << "|\n";
			count = 0;
		}
	}
	cout << "-------\n";
}

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