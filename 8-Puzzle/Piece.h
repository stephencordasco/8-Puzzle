/*********************************************************************************
author:		Stephen Cordasco
project:	AI Project - 8-puzzle with BFS AI and A* AI
class:		CS 481 - AI
instructor:	Dr. Han
date:		11 October 2018
*********************************************************************************/
#pragma once

class Piece
{
	friend class State;
	private:
		// every piece has a value
		int value;
		// every piece has a boolean; true for blank false for other
		bool blank;
	public:
		// constructors
		Piece();
		Piece(int aValue, bool aBlank);
		// destructor
		~Piece();

		// Setters
		void setValue(int aValue);
		void setBlank(bool aBlank);
		// Getters
		int getValue();
		bool isBlank();
};