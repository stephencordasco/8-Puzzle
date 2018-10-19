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
	displayStateSpace();
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

void BFS_Queue::displayStateSpace()
{
	Piece *aState = nullptr;
	while (!isEmpty())
		dequeue(aState);
}

void BFS_Queue::BFS()
{

}