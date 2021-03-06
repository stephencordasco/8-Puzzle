/*********************************************************************************
author:		Stephen Cordasco
project:	AI Project - 8-puzzle with BFS AI and A* AI
class:		CS 481 - AI
instructor:	Dr. Han
date:		20 November 2018
*********************************************************************************/
#include <Windows.h>
#include <cstdio>
#include <ctime>

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

	clock_t start;							// used to keep time
	double duration;						// used to print total elapsed time

	// push the first node onto opne
	open.push_back(ptr);

	// start the clock
	start = clock();
	std::cout << "\nSearching...";

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
				// print success message
				std::cout << "\n\nGoal state found!\n";

				// print number of states searched
				numStates = closed.size();
				std::cout << "States searched: " << numStates << "\n";

				// calculate the total time elapsed and print it
				duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				std::cout << "\nTotal search time: " << duration << "\n";
				std::cin.get();
				std::cout << "\nPress ENTER to view Trace Path...";
				std::cin.get();

				// set found flag true
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
	int pathLength = 0;

	std::cout << "\nTracing the path...\n";
	while (current != nullptr)
	{
		Sleep(500);
		current->printState();
		current = current->parent;
		pathLength++;
	}
	std::cout << "\nPath Length: " << pathLength << "\n";
	std::cout << "\n========== END OF TRACE ==========\n";
	std::cout << "Press ENTER to continue...";
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

	clock_t start;							// used to keep time
	double duration;						// used to print total elapsed time

	// push the first node onto open
	open.push_back(ptr);

	// start the clock
	start = clock();
	std::cout << "\nSearching...";

	// begin search
	while (open.size() > 0 && !found)
	{
		// pointer to first node
		GraphNode *current = *open.begin();

		// pop front of open list
		open.pop_front();

		// check if current is goal
		if (current->isGoal())
		{
			// print success message
			std::cout << "\n\nGoal state found!\n";

			// print number of states searched
			numStates = closed.size();
			std::cout << "States searched: " << numStates << "\n";

			// calculate the total time elapsed and print it
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			std::cout << "\nTotal search time: " << duration << "\n";
			std::cin.get();
			std::cout << "Press ENTER to view Trace Path...";
			std::cin.get();

			// set found flag to true
			found = true;

			// trace the solution path
			tracePath(current);
		}
		else
		{
			// generate children of current
			current->expandGraph();

			// iterate through each child of current
			for (std::list<GraphNode*>::iterator it = current->children.begin(); it != current->children.end(); it++)
			{
				// pointer to children of current
				GraphNode *currentChild = *it;

				// child is not on open or closed
				if (!contains(open, currentChild) && !contains(closed, currentChild))
				{
					// assign child a heuristic value
					currentChild->heuristic = tilesOutOfPlace(currentChild->state);
					// push child on to open
					open.push_back(currentChild);
				}
				// child is already on open
				else if (contains(open, currentChild))
				{
					// pointer to node found in open
					GraphNode *temp = nullptr;

					// traverse open
					for (std::list<GraphNode*>::iterator it = open.begin(); it != open.end(); it++)
					{
						// pointer to GraphNodes in open
						GraphNode *t = *it;

						// check if same node is found
						if (t->isSameState(currentChild->state))
						{
							temp = t;
						}
					}

					// if child was reached by a shorter path
					if (pathLength(temp) < pathLength(currentChild))
					{
						currentChild = temp;
					}
				}
				// child is already on open
				else if (contains(closed, currentChild))
				{
					// pointer to node found in closed
					GraphNode *temp = nullptr;

					// traverse closed
					for (std::list<GraphNode*>::iterator it = closed.begin(); it != closed.end(); it++)
					{
						// pointer to GraphNodes in closed
						GraphNode *t = *it;

						// check if same node is found
						if (t->isSameState(currentChild->state))
						{
							temp = t;
						}
					}

					// if child was reached by a shorter path
					if (pathLength(temp) < pathLength(currentChild))
					{
						closed.remove(currentChild);
						open.push_back(currentChild);
					}
				}
			}
		}

		// push node onto closed list
		closed.push_back(current);

		// reorder states on open by heuristic merit
		open.sort();
	}
}

int Graph::pathLength(GraphNode *node)
{
	// pointer to the parameter
	GraphNode *current = node;
	// variable used to keep count of path length
	int pLength = 1;

	while (current != nullptr)
	{
		pLength++;
		current = current->parent;
	}

	return pLength;
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
