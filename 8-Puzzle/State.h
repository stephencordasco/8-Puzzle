/*********************************************************************************
author:		Stephen Cordasco
project:	AI Project - 8-puzzle with BFS AI and A* AI
class:		CS 481 - AI
instructor:	Dr. Han
date:		11 October 2018
*********************************************************************************/
#pragma once
#include <iostream>
#include <vector>
using namespace std;

#include "Piece.h"

class State
{
	private:
		// member variables
		Piece *state;
		vector<State *> parents;
		vector<State *> children;
	public:
		// constructor
		State(Piece arr[]);
		// destructor
		~State();
		
		// member functions
		void findChildStates();
		void displayState() const;
};