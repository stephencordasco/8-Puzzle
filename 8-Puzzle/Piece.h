/*********************************************************************************
author:		Stephen Cordasco
project:	AI Project - 8-puzzle with BFS AI and A* AI
class:		CS 481 - AI
instructor:	Dr. Han
date:		18 October 2018
*********************************************************************************/
#ifndef PIECE_H
#define PIECE_H

#include <iostream>

class Piece
{
	private:
		friend class State;
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

#endif