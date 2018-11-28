/*********************************************************************************
author:		Stephen Cordasco
project:	AI Project - 8-puzzle with BFS AI and A* AI
class:		CS 481 - AI
instructor:	Dr. Han
date:		20 November 2018
*********************************************************************************/
#include <Windows.h>

#include "Graph.h"

/*********************************************************************************
name:		BFS
parameters:	pointer to GraphNode
purpose:	performs Breadth-First Search
*********************************************************************************/
void Graph::BFS(GraphNode *ptr)
{
	size_t numStates = 0;					// used to count the number of states searched
	std::list<GraphNode*> open;				// list to store the nodes being searched
	std::list<GraphNode*> closed;			// list to store the searched nodes
	bool found = false;						// value to determine if goal has been found or not

	// push the first node onto opne
	open.push_back(ptr);

	// begin search
	while (open.size() > 0 && !found)
	{
		// pointer to first node
		GraphNode *current = *open.begin();
		// push node onto closed list
		closed.push_back(current);
		// pop front of open list
		open.pop_front();

		// expand the graph
		current->expandGraph();
		// print the new states
		//current->printState();

		for (std::list<GraphNode*>::iterator it = current->children.begin(); it != current->children.end(); it++)
		{
			// pointer to children of current
			GraphNode *currentChild = *it;

			// check for goal state
			if (currentChild->isGoal())
			{
				// print goal state
				currentChild->printState();
				std::cout << "\nGoal state found!\n";
				// print number of states searched
				numStates = closed.size();
				std::cout << "States searched: " << numStates << "\n";
				std::cin.get();
				std::cout << "Press ENTER to view Trace Path...\n";
				std::cin.get();
				found = true;
				// trace the solution path
				tracePath(currentChild);
			}

			// push children onto open
			if (!contains(open, currentChild) && !contains(closed, currentChild))
				open.push_back(currentChild);
		}
	}
}

/*********************************************************************************
name:		contains
parameters:	list of GraphNode pointers, pointer to GraphNode
purpose:	checks if GraphNode exists in list
*********************************************************************************/
bool Graph::contains(std::list<Graph::GraphNode*> li, Graph::GraphNode *node)
{
	for (std::list<GraphNode*>::iterator it = li.begin(); it != li.end(); it++)
	{
		GraphNode *temp = *it;
		if (temp->isSameState(node->state))
			return true;
	}
	return false;
}

/*********************************************************************************
name:		tracePath
parameters:	list of GraphNode pointers, pointer to GraphNode
purpose:	traces the path from goal to initial state
*********************************************************************************/
void Graph::tracePath(Graph::GraphNode *node)
{
	GraphNode *current = node;

	std::cout << "\nTracing the path...\n";
	while (current != nullptr)
	{
		Sleep(750);
		current->printState();
		current = current->parent;
	}
	std::cout << "\n========== END OF TRACE ==========\n";
	std::cout << "Press ENTER to continue...\n";
	std::cin.get();
}

/*********************************************************************************
name:		A_Star
parameters:	pointer to GraphNode
purpose:	performs a Heuristic search on the state space for the goal state
*********************************************************************************/
void Graph::A_Star(GraphNode *ptr)
{
	size_t numStates = 0;					// used to count the number of states searched
	std::list<GraphNode*> open;				// list to store the nodes being searched
	std::list<GraphNode*> closed;			// list to store the searched nodes
	bool found = false;						// value to determine if goal has been found or not

	// push the first node onto open
	open.push_back(ptr);

	// begin search
	while (open.size() > 0 && !found)
	{
		// pointer to first node
		GraphNode *current = *open.begin();
		// push node onto closed list
		closed.push_back(current);
		// pop front of open list
		open.pop_front();

		// expand the graph
		current->expandGraph();
		// print the new states
		current->printState();

		for (std::list<GraphNode*>::iterator it = current->children.begin(); it != current->children.end(); it++)
		{
			// pointer to children of current
			GraphNode *currentChild = *it;

			// check for goal state
			if (currentChild->isGoal())
			{
				// print goal state
				currentChild->printState();
				std::cout << "\nGoal state found!\n";
				// print number of states searched
				numStates = closed.size();
				std::cout << "States searched: " << numStates << "\n";
				std::cin.get();
				std::cout << "Press ENTER to view Trace Path...\n";
				std::cin.get();
				found = true;
				// trace the solution path
				tracePath(currentChild);
			}

			// check if child is on open or closed
			if (!contains(open, currentChild) && !contains(closed, currentChild))
			{
				// push child on to open
				open.push_back(currentChild);
				// assign child a heuristic value
				currentChild->heuristic = tilesOutOfPlace(currentChild->state);
			}
		}
	}
}

/*********************************************************************************
name:		tilesOutOfPlace
parameters:	integer array
purpose:	counts and returns the number of tiles out of place (the heuristic)
*********************************************************************************/
int Graph::tilesOutOfPlace(int aState[9])
{
	// variable used to count tiles out of place
	int count = 0;
	// define a goal state
	int goal[9] = { 1, 2, 3, 8, 0, 4, 7, 6, 5 };

	for (int i = 0; i < 9; i++)
	{
		if (aState[i] != goal[i])
			count++;
	}

	return count;
}