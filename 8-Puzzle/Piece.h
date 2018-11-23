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
		friend class State;		// forward declaration
		int value;				// store the value of the piece
		bool blank;				// used to determine if a piece is blank or not

	public:
		Piece();				// default constructor
		Piece(int , bool );		// overloaded constructor
		// destructor
		~Piece();				// destructor

		// Setters
		void setValue(int aValue);
		void setBlank(bool aBlank);
		// Getters
		int getValue();
		bool isBlank();
};

#endif