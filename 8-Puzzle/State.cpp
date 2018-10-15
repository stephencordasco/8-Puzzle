/*********************************************************************************
author:		Stephen Cordasco
project:	AI Project - 8-puzzle with BFS AI and A* AI
class:		CS 481 - AI
instructor:	Dr. Han
date:		11 October 2018
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
}

/*********************************************************************************
name:		~State
parameters:	none
purpose:	default constructor
*********************************************************************************/
State::~State()
{

}

/*********************************************************************************
name:		findChildStates
parameters:	none
purpose:	moves the blank piece in order left, up, right, down to find child
			states and adds child states to the children vector
*********************************************************************************/
void State::findChildStates()
{

}

/*********************************************************************************
name:		displayState
parameters:	none
purpose:	displays the current state (Piece object array)
*********************************************************************************/
void State::displayState() const
{
	// helper variable
	int count = 0;

	// display the initial state
	cout << "-------\n";
	for (int i = 0; i < 9; i++)
	{
		cout << "|" << state[i].getValue();
		count++;
		if (count == 3)
		{
			cout << "|\n";
			count = 0;
		}
	}
	cout << "-------\n";
}