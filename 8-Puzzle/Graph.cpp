/*********************************************************************************
author:		Stephen Cordasco
project:	AI Project - 8-puzzle with BFS AI and A* AI
class:		CS 481 - AI
instructor:	Dr. Han
date:		20 November 2018
*********************************************************************************/
#include "Graph.h"

Graph::Graph()
{
	root = nullptr;
}

Graph::~Graph()
{
	destroyGraph(root);
}

void Graph::expandGraph(Piece init[], Piece goal[9])
{
	// initialize the root
	root = new GraphNode(init);

	// pointer to the root
	GraphNode *ptr = root;
	printGraph(ptr->arr);

	// add nodes
	addLeft(ptr);
	addUp(ptr);
	addRight(ptr);
	addDown(ptr);

}

void Graph::addLeft(GraphNode *ptr)
{
	Piece temp[9];
	std::copy(ptr->arr, ptr->arr + 9, temp);
	GraphNode *leftChild = new GraphNode(moveLeft(temp));
	ptr->left = leftChild;
	printGraph(leftChild->arr);
}

void Graph::addUp(GraphNode *ptr)
{
	Piece temp[9];
	std::copy(ptr->arr, ptr->arr + 9, temp);
	GraphNode *upChild = new GraphNode(moveUp(temp));
	ptr->up = upChild;
	printGraph(upChild->arr);
}

void Graph::addRight(GraphNode *ptr)
{
	Piece temp[9];
	std::copy(ptr->arr, ptr->arr + 9, temp);
	GraphNode *rightChild = new GraphNode(moveRight(temp));
	ptr->right = rightChild;
	printGraph(rightChild->arr);
}

void Graph::addDown(GraphNode *ptr)
{
	Piece temp[9];
	std::copy(ptr->arr, ptr->arr + 9, temp);
	GraphNode *downChild = new GraphNode(moveDown(temp));
	ptr->down = downChild;
	printGraph(downChild->arr);
}

void Graph::printGraph(Piece *arr) const
{
	// helper variable
	int count = 0;

	// display the initial state
	std::cout << "-------\n";
	for (int i = 0; i < 9; i++)
	{
		std::cout << "|" << arr[i].getValue();
		count++;
		if (count == 3)
		{
			std::cout << "|\n";
			count = 0;
		}
	}
	std::cout << "-------\n";
}

void Graph::destroyGraph(GraphNode *ptr)
{
	if (!ptr) return;
	destroyGraph(ptr->left);
	destroyGraph(ptr->up);
	destroyGraph(ptr->right);
	destroyGraph(ptr->down);
	std::cout << "\ndeallocating memory...\n";
	delete ptr;
}

bool Graph::isEmpty()
{
	if (root = nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Piece * Graph::moveLeft(Piece arr[])
{
	for (int i = 0; i < 9; i++)
	{
		// check for blank piece
		if (arr[i].getValue() == 0)
		{
			// check for invalid move
			if (i == 0 || i == 3 || i == 6)
			{
				return arr;
			}
			// move the piece
			Piece temp = arr[i - 1];
			arr[i - 1].setValue(0);
			arr[i - 1].setBlank(true);
			arr[i].setValue(temp.getValue());
			arr[i].setBlank(temp.isBlank());
		}
	}
	return arr;
}

Piece * Graph::moveUp(Piece arr[])
{
	for (int i = 0; i < 9; i++)
	{
		// check for blank piece
		if (arr[i].getValue() == 0)
		{
			// check for invalid move
			if (i == 0 || i == 1 || i == 2)
			{
				return arr;
			}
			// move the piece
			Piece temp = arr[i - 3];
			arr[i - 3].setValue(0);
			arr[i - 3].setBlank(true);
			arr[i].setValue(temp.getValue());
			arr[i].setBlank(temp.isBlank());
		}
	}
	return arr;
}

Piece * Graph::moveRight(Piece arr[])
{
	for (int i = 0; i < 9; i++)
	{
		// check for blank piece
		if (arr[i].getValue() == 0)
		{
			// check for invalid move
			if (i == 2 || i == 5 || i == 8)
			{
				return arr;
			}
			// move the piece
			Piece temp = arr[i + 1];
			arr[i + 1].setValue(0);
			arr[i + 1].setBlank(true);
			arr[i].setValue(temp.getValue());
			arr[i].setBlank(temp.isBlank());
			// return to function call to prevent continued execution
			return arr;
		}
	}
	return arr;
}

Piece * Graph::moveDown(Piece arr[])
{
	for (int i = 0; i < 9; i++)
	{
		// check for blank piece
		if (arr[i].getValue() == 0)
		{
			// check for invalid move
			if (i == 6 || i == 7 || i == 8)
			{
				return arr;
			}
			// move the piece
			Piece temp = arr[i + 3];
			arr[i + 3].setValue(0);
			arr[i + 3].setBlank(true);
			arr[i].setValue(temp.getValue());
			arr[i].setBlank(temp.isBlank());
			// return to main to prevent continued execution
			return arr;
		}
	}
	return arr;
}
