/*********************************************************************************
author:		Stephen Cordasco
project:	AI Project - 8-puzzle with BFS AI and A* AI
class:		CS 481 - AI
instructor:	Dr. Han
date:		18 October 2018
*********************************************************************************/
#include "Piece.h"

/*********************************************************************************
name:		Piece
parameters:	none
purpose:	default constructor
*********************************************************************************/
Piece::Piece()
{
	value = 0;
	blank = true;
}

/*********************************************************************************
name:		Piece
parameters:	int type, bool type
purpose:	overloaded constructor
*********************************************************************************/
Piece::Piece(int aValue, bool aBlank)
{
	value = aValue;
	blank = aBlank;
}

/*********************************************************************************
name:		~Piece
parameters:	none
purpose:	destructor
*********************************************************************************/
Piece::~Piece()
{

}

/*********************************************************************************
name:		setValue
parameters:	int type
purpose:	used to set the value attribute of a Piece object
*********************************************************************************/
void Piece::setValue(int aValue)
{
	value = aValue;
}

/*********************************************************************************
name:		setBlank
parameters:	bool type
purpose:	used to set the blank attribute of a Piece object
*********************************************************************************/
void Piece::setBlank(bool aBlank)
{
	blank = aBlank;
}

/*********************************************************************************
name:		getValue
parameters:	none
purpose:	returns the value attribute of a Piece object
*********************************************************************************/
int Piece::getValue()
{
	return this->value;
}

/*********************************************************************************
name:		isBlank
parameters:	none
purpose:	returns the blank attribute (true || false) of a Piece object
*********************************************************************************/
bool Piece::isBlank()
{
	return this->blank;
}