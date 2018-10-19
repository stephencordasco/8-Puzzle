/*********************************************************************************
author:		Stephen Cordasco
project:	AI Project - 8-puzzle with BFS AI and A* AI
class:		CS 481 - AI
instructor:	Dr. Han
date:		18 October 2018
*********************************************************************************/
#pragma once

#include "BFS_Queue.h"
#include "Piece.h"

class State
{
	friend class BFS_Queue;
	private:
		// private member variables
		Piece *state;
		State *next;
	public:
		// constructor
		State();
		State(Piece arr[]);
};