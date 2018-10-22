/*********************************************************************************
author:		Stephen Cordasco
project:	AI Project - 8-puzzle with BFS AI and A* AI
class:		CS 481 - AI
instructor:	Dr. Han
date:		18 October 2018
*********************************************************************************/
#pragma once

#include <iostream>
#include <Windows.h>
using namespace std;

#include "State.h"
#include "Piece.h"

class BFS_Queue
{
	private:
		// private member variables
		State *front;
		State *end;
	public:
		// constructor
		BFS_Queue();
		// destructor
		~BFS_Queue();

		// public member functions
		void enqueue(Piece *);
		void dequeue();
		bool isEmpty() const;
		void clear();
		void BFS(Piece *, Piece *);
		Piece *tryLeft(Piece *);
		Piece *tryUp(Piece *);
		Piece *tryRight(Piece *);
		Piece *tryDown(Piece *);
		bool isNewState(Piece *, Piece *);
		void printState(Piece *) const;
};