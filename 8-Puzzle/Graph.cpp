/*********************************************************************************
author:		Stephen Cordasco
project:	AI Project - 8-puzzle with BFS AI and A* AI
class:		CS 481 - AI
instructor:	Dr. Han
date:		20 November 2018
*********************************************************************************/
#include "Graph.h"

std::list<Graph::GraphNode*> Graph::BFS(GraphNode *ptr)
{
	std::list<GraphNode*> solutionPath;
	std::list<GraphNode*> open;
	std::list<GraphNode*> closed;
	bool found = false;

	open.push_back(ptr);
	while (open.size() > 0 && !found)
	{
		GraphNode *current = *open.begin();
		closed.push_back(current);
		open.pop_front();

		current->expandGraph();
		current->printState();

		for (std::list<GraphNode*>::iterator it = current->children.begin(); it != current->children.end(); it++)
		{
			// ===== ERROR =====
			GraphNode *currentChild = *it;
			if (currentChild->isGoal())
			{
				currentChild->printState();
				std::cout << "\nGoal state found!\n";
				found = true;
				tracePath(solutionPath, currentChild);
			}

			if (!contains(open, currentChild) && !contains(closed, currentChild))
				open.push_back(currentChild);
		}
	}

	return solutionPath;
}

bool Graph::contains(std::list<Graph::GraphNode*> li, Graph::GraphNode *node)
{
	for (std::list<GraphNode*>::iterator it = li.begin(); it != li.end(); it++)
	{
		GraphNode *temp = *it;
		// ===== ERROR =====
		if (temp->isSameState(node->state))
			return true;
	}
	return false;
}

void Graph::tracePath(std::list<Graph::GraphNode*> path, Graph::GraphNode *node)
{
	GraphNode *current = node;
	path.push_back(current);

	while (current->parent != nullptr)
	{
		current = current->parent;
		path.push_back(current);
	}
}