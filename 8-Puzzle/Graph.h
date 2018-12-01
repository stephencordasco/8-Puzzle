/*********************************************************************************
author:		Stephen Cordasco
project:	AI Project - 8-puzzle with BFS AI and A* AI
class:		CS 481 - AI
instructor:	Dr. Han
date:		23 November 2018
*********************************************************************************/
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <list>

class Graph
{
public:

	class GraphNode
	{
	public:
		friend class Graph;				// forward declaration

		// ===================================== GRAPH NODE MEMBER VALUES =====================================

		int state[9];					// integer array representing a state
		int blank = 0;					// index of blank piece
		int heuristic = 0;				// tiles out of place
		GraphNode *parent;				// pointer to parent node
		std::list<GraphNode*> children;	// list of GraphNodes representing children of current GraphNode

		// ===================================== GRAPH NODE MEMBER FUNCTIONS ==================================

		/*********************************************************************************
		name:		GraphNode
		parameters:	none
		purpose:	default constructor
		*********************************************************************************/
		GraphNode(int aState[])
		{
			initState(aState);
		}

		/*********************************************************************************
		name:		initState
		parameters:	integer array
		purpose:	initializes integer array of a GraphNode
		*********************************************************************************/
		void initState(int aState[])
		{
			for (int ix = 0; ix < 9; ix++)
				this->state[ix] = aState[ix];
		}

		/*********************************************************************************
		name:		isGoal
		parameters:	none
		purpose:	returns true if state is goal state otherwise returns false
		*********************************************************************************/
		bool isGoal()
		{
			// define a goal state
			int goalState[9] = { 1, 2, 3, 8, 0, 4, 7, 6, 5 };
			// helper variable
			int count = 0;


			for (int ix = 0; ix < 9; ix++)
			{
				if (state[ix] == goalState[ix])
					count++;
			}
			if (count == 9)
				return true;
			else return false;
		}

		/*********************************************************************************
		name:		isSameState
		parameters:	integer array
		purpose:	returns true if state is same as parameter, otherwise returns false
		*********************************************************************************/
		bool isSameState(int aState[9])
		{
			int count = 0;
			for (int ix = 0; ix < 9; ix++)
			{
				if (state[ix] == aState[ix])
					count++;
			}
			if (count == 9)
				return true;
			else return false;
		}

		/*********************************************************************************
		name:		printState
		parameters:	none
		purpose:	prints state
		*********************************************************************************/
		void printState()
		{
			int count = 0;
			std::cout << "\n-------\n";
			for (int ix = 0; ix < 9; ix++)
			{
				std::cout << "|" << state[ix];
				count++;
				if (count == 3)
				{
					std::cout << "|\n";
					count = 0;
				}
			}
			std::cout << "-------\n";
		}

		/*********************************************************************************
		name:		copyState
		parameters:	integer array (2x)
		purpose:	creates a copy of a state
		*********************************************************************************/
		void copyState(int cState[9], int aState[9])
		{
			for (int ix = 0; ix < 9; ix++)
				cState[ix] = aState[ix];
		}

		/*********************************************************************************
		name:		moveLeft
		parameters:	integer array, integer
		purpose:	performs a legal left move
		*********************************************************************************/
		void moveLeft(int aState[9], int index)
		{
			if (index % 3 > 0)
			{
				// declare an integer array
				int newState[9];
				// initialize integer array
				copyState(newState, aState);

				int temp = newState[index - 1];
				newState[index - 1] = aState[index];
				newState[index] = temp;

				// pointer to child GraphNode with new state
				GraphNode *child = new GraphNode(newState);
				// push it onto list
				children.push_back(child);
				// establish parent connection
				child->parent = this;
			}
		}

		/*********************************************************************************
		name:		moveUp
		parameters:	integer array, integer
		purpose:	performs a legal up move
		*********************************************************************************/
		void moveUp(int aState[9], int index)
		{
			if (index - 3 >= 0)
			{
				int newState[9];
				copyState(newState, aState);

				int temp = newState[index - 3];
				newState[index - 3] = aState[index];
				newState[index] = temp;

				GraphNode *child = new GraphNode(newState);
				children.push_back(child);
				child->parent = this;
			}
		}

		/*********************************************************************************
		name:		moveRight
		parameters:	integer array, integer
		purpose:	performs a legal right move
		*********************************************************************************/
		void moveRight(int aState[9], int index)
		{
			if (index % 3 < 2)
			{
				int newState[9];
				copyState(newState, aState);

				int temp = newState[index + 1];
				newState[index + 1] = aState[index];
				newState[index] = temp;

				GraphNode *child = new GraphNode(newState);
				children.push_back(child);
				child->parent = this;
			}
		}

		/*********************************************************************************
		name:		moveDown
		parameters:	integer array, integer
		purpose:	performs a legal down move
		*********************************************************************************/
		void moveDown(int aState[9], int index)
		{
			if (index + 3 < 9)
			{
				int newState[9];
				copyState(newState, aState);

				int temp = newState[index + 3];
				newState[index + 3] = aState[index];
				newState[index] = temp;

				GraphNode *child = new GraphNode(newState);
				children.push_back(child);
				child->parent = this;
			}
		}

		/*********************************************************************************
		name:		expandGraph
		parameters:	none
		purpose:	adds child nodes to current GraphNode by performing legal moves:
					left, up, right, down
		*********************************************************************************/
		void expandGraph()
		{
			for (int ix = 0; ix < 9; ix++)
			{
				if (state[ix] == 0)
					blank = ix;
			}

			// try legal moves on current state
			moveLeft(state, blank);
			moveUp(state, blank);
			moveRight(state, blank);
			moveDown(state, blank);
		}
	};

	// ===================================== GRAPH CLASS MEMBER FUNCTIONS =====================================
	Graph()	{ }														// constructor
	~Graph() { }													// destructor

	void BFS(GraphNode *);											// Breadth-First Search algorithm
	bool contains(std::list<GraphNode*> li, GraphNode *);			// checks open and closed lists
	void tracePath(GraphNode *node);								// traces the path from goal to initial state

	void A_Star(GraphNode *);										// A* (Best-First Search) algorithm
	int tilesOutOfPlace(int aState[9]);								// return the heuristic value for a GraphNode
	std::list<GraphNode*> reorder(std::list<GraphNode*>);			// reorder a list based of heuristic value
};

#endif