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
	//cout << "allocating memory\n";
	state = arr;
	next = nullptr;
}