/*********************************************************************************
author:		Stephen Cordasco
project:	AI Project - 8-puzzle with BFS AI and A* AI
class:		CS 481 - AI
instructor:	Dr. Han
date:		20 November 2018
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
		friend class Graph;		// forward declaration
	public:

		// ===================================== GRAPH NODE MEMBER VALUES =====================================
		int state[9];
		int blank = 0;
		GraphNode *parent;
		std::list<GraphNode*> children;

		// ===================================== GRAPH NODE MEMBER FUNCTIONS ==================================
		GraphNode(int aState[])	// contructor
		{
			initState(aState);
		}

		void initState(int aState[])
		{
			for (int ix = 0; ix < 9; ix++)
				this->state[ix] = aState[ix];
		}

		bool isGoal()
		{
			int goalState[9] = { 1, 2, 3, 8, 0, 4, 7, 6, 5 };
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

		void copyState(int cState[9], int aState[9])
		{
			for (int ix = 0; ix < 9; ix++)
				cState[ix] = aState[ix];
		}

		void moveLeft(int aState[9], int index)
		{
			if (index % 3 > 0)
			{
				int newState[9];
				copyState(newState, aState);

				int temp = newState[index - 1];
				newState[index - 1] = aState[index];
				newState[index] = temp;

				GraphNode *child = new GraphNode(newState);
				children.push_back(child);
				child->parent = this;
			}
		}

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

		void expandGraph()
		{
			for (int ix = 0; ix < 9; ix++)
			{
				if (state[ix] == 0)
					blank = ix;
			}

			moveLeft(state, blank);
			moveUp(state, blank);
			moveRight(state, blank);
			moveDown(state, blank);
		}
	};

	// ===================================== GRAPH CLASS MEMBER FUNCTIONS =====================================
	Graph()	{ }		// constructor
	~Graph() { }	// destructor

	std::list<GraphNode*> BFS(GraphNode *);
	bool contains(std::list<GraphNode*> li, GraphNode *);
	void tracePath(std::list<GraphNode*> path, GraphNode *node);
};

#endif