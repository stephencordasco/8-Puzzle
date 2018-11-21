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

	Piece ll[9];
	Piece uu[9];
	Piece rr[9];
	Piece dd[9];

	std::copy(ptr->arr, ptr->arr + 9, ll);
	std::copy(ptr->arr, ptr->arr + 9, uu);
	std::copy(ptr->arr, ptr->arr + 9, rr);
	std::copy(ptr->arr, ptr->arr + 9, dd);

	GraphNode *l = new GraphNode(addChildLeft(ll));
	GraphNode *u = new GraphNode(addChildUp(uu));
	GraphNode *r = new GraphNode(addChildRight(rr));
	GraphNode *d = new GraphNode(addChildDown(dd));

	printGraph(l->arr);
	printGraph(u->arr);
	printGraph(r->arr);
	printGraph(d->arr);
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

Piece * Graph::addChildLeft(Piece arr[])
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

Piece * Graph::addChildUp(Piece arr[])
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

Piece * Graph::addChildRight(Piece arr[])
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

Piece * Graph::addChildDown(Piece arr[])
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
