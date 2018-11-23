/*********************************************************************************
author:		Stephen Cordasco
project:	AI Project - 8-puzzle with BFS AI and A* AI
class:		CS 481 - AI
instructor:	Dr. Han
date:		18 October 2018
*********************************************************************************/
#ifndef BFS_QUEUE_H
#define BFS_QUEUE_H

#include <iostream>
#include <Windows.h>

#include "State.h"
#include "Piece.h"

class BFS_Queue
{
	private:
		State *front;			// pointer to the front of the queue
		State *end;				// pointer to the end of the queue

	public:
		BFS_Queue();			// default constructor
		~BFS_Queue();			// destructor

		// public member functions
		void enqueue(Piece *);
		void dequeue();
		bool isEmpty() const;
		void clear();
		void bruteForceSearch(Piece *, Piece *);

		// helper functions
		Piece *tryLeft(Piece *);
		Piece *tryUp(Piece *);
		Piece *tryRight(Piece *);
		Piece *tryDown(Piece *);
		bool isNewState(Piece *, Piece *);
		void printState(Piece *) const;
};

#endif