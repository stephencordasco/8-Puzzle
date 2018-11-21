#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include "Piece.h"
#include "State.h"

class Graph
{
public:
	class GraphNode
	{
		friend class Graph;
		// value of the node
		Piece arr[9];
		// pointers of the node
		GraphNode *left;
		GraphNode *up;
		GraphNode *right;
		GraphNode *down;

		// default constructor
		GraphNode()
		{
			// initialize the array of the GraphNode to 0
			for (int i = 0; i < 9; i++)
			{
				arr[i].setValue(0);
			}
			// set the pointers to nullptr
			left = nullptr, up = nullptr, right = nullptr, down = nullptr;
		}

		// GraphNode overloaded constructor
		GraphNode(Piece *nArr)
		{
			// initialize the array of the GraphNode
			for (int i = 0; i < 9; i++)
			{
				arr[i] = nArr[i];
			}
			// set the pointers to nullptr
			left = nullptr, up = nullptr, right = nullptr, down = nullptr;
		}

		// GraphNode overloaded constructor
		GraphNode(Piece *nArr, GraphNode *l, GraphNode *u, GraphNode *r, GraphNode *d)
		{
			// initialize the array of the GraphNode
			for (int i = 0; i < 9; i++)
			{
				arr[i] = nArr[i];
			}
			// initialize the pointers of the GraphNode
			left = l, up = u, right = r, down = d;
		}
	};
	// constructor
	Graph();
	// destructor
	~Graph();

	// graph member functions
	void expandGraph(Piece[], Piece[9]);
	void printGraph(Piece *) const;
	bool isEmpty();
	void destroyGraph(GraphNode *ptr);

	// helper functions
	Piece * addChildLeft(Piece[]);
	Piece * addChildUp(Piece[]);
	Piece * addChildRight(Piece[]);
	Piece * addChildDown(Piece[]);

private:
	// pointer to the root of the graph
	GraphNode *root;
};

#endif