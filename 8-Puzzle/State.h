/*********************************************************************************
author:		Stephen Cordasco
project:	AI Project - 8-puzzle with BFS AI and A* AI
class:		CS 481 - AI
instructor:	Dr. Han
date:		18 October 2018
*********************************************************************************/
#ifndef STATE_H
#define STATE_H

#include "BFS_Queue.h"
#include "Piece.h"

class State
{
	private:
		friend class BFS_Queue;			// forward declaration
		Piece *state;					// pointer to piece array
		State *next;					// pointer to the next node

	public:
		State(Piece arr[]);				// constructor
};

#endif