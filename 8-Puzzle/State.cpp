/*********************************************************************************
author:		Stephen Cordasco
project:	AI Project - 8-puzzle with BFS AI and A* AI
class:		CS 481 - AI
instructor:	Dr. Han
date:		18 October 2018
*********************************************************************************/
#include "State.h"

/*********************************************************************************
name:		State
parameters:	Piece object array
purpose:	default constructor
*********************************************************************************/
State::State(Piece arr[])
{
	state = arr;
	next = nullptr;
}

void State::printState(Piece *nState)
{
	// helper variable
	int count = 0;

	// display the initial state
	cout << "-------\n";
	for (int i = 0; i < 9; i++)
	{
		cout << "|" << nState[i].getValue();
		count++;
		if (count == 3)
		{
			cout << "|\n";
			count = 0;
		}
	}
	cout << "-------\n";
}