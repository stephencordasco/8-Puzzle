/*********************************************************************************
author:		Stephen Cordasco
project:	AI Project - 8-puzzle with BFS AI and A* AI
class:		CS 481 - AI
instructor:	Dr. Han
date:		18 October 2018
*********************************************************************************/
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
	cout << "deallocating memory\n";
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

void BFS_Queue::dequeue(Piece *nState)
{
	State *temp;
	if (isEmpty())
	{
		cout << "Queue is empty.\n";
		return;
	}
	else
	{
		nState = front->state;
		temp = front;
		front = front->next;
		temp->printState(temp->state);
		cout << "deleting a node\n";
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
	Piece *aState = nullptr;
	while (!isEmpty())
	{
		cout << "deleting a node\n";
		dequeue(aState);
	}
}

void BFS_Queue::BFS(Piece *initialState, Piece *goalState)
{
	// add the initial state to the front of the queue
	enqueue(initialState);
	dequeue(initialState);

	State *current = new State(initialState);
	current->state = tryUp(current->state);
	enqueue(current->state);
	dequeue(current->state);
	clear();
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