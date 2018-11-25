/*********************************************************************************
author:		Stephen Cordasco
project:	AI Project - 8-puzzle with BFS AI and A* AI
purpose:	An initial state and goal state are initialized. An AI using a BFS
			algorithm will solve the puzzle, storing the state space and steps
			taken as it executes. An AI using A* heuristic algorithm will then
			solve the puzzle, storing the path and steps taken as it executes.
			The different results will be displayed to show comparison of the
			two AI.
class:		CS 481 - AI
instructor:	Dr. Han
date:		18 October 2018
*********************************************************************************/
#include "State.h"
#include "Graph.h"

// function prototypes
void clearScreen();
void printMenu();
char getMenuChoice();
void playGame();
void playGameBF_AI();
void playGameBFS_AI();
void printState(Piece arr[]);
void movePiece(Piece arr[], char choice);
bool checkGoalState(Piece state[], Piece goal[], int arrSize);




int main()
{
	// variable used to store user choice
	char menuChoice = ' ';

	// begin program loop
	do
	{
		// print menu
		printMenu();
		// store user choice
		menuChoice = getMenuChoice();

		// get menuChoice
		switch (menuChoice)
		{
			case '1':			// user plays game
				playGame();
				clearScreen();
				break;

			case '2':			// AI plays game (custom brute force search)
				playGameBF_AI();
				clearScreen();
				break;

			case '3':			// AI plays game using BFS (breadth-first search)
				playGameBFS_AI();
				clearScreen();
				break;

			case '4':			// user quits
				std::cout << "Goodbye!\n\n";
				break;

			default:			// user entered an invalid character
				std::cout << "\nINVALID MENU CHOICE\n";
		}

	} while (menuChoice != '4');

	system("pause");
	return 0;
}

/*********************************************************************************
name:		clearScreen
parameters:	none
purpose:	prints 100 new lines to "refresh" the screen
*********************************************************************************/
void clearScreen()
{
	for (int i = 0; i < 100; i++)
		std::cout << "\n";
}

/*********************************************************************************
name:		printMenu
parameters:	none
purpose:	prints menu
*********************************************************************************/
void printMenu()
{
	std::cout << "\n==================== 8-Puzzle ====================\n";
	std::cout << "1.) Play 8-Puzzle\n";
	std::cout << "2.) AI Plays 8-Puzzle (Using Custom Brute Force)\n";
	std::cout << "3.) AI Plays 8-Puzzle (Using BFS)\n";
	std::cout << "4.) Exit\n";
	std::cout << "==================================================\n";
}

/*********************************************************************************
name:		difficultyMenu
parameters:	none
purpose:	prints difficulty menu
*********************************************************************************/
void difficultyMenu()
{
	std::cout << "\n================= CHOOSE DIFFICULTY ==============\n";
	std::cout << "1.) Standard\n";
	std::cout << "2.) Easy\n";
	std::cout << "3.) Medium\n";
	std::cout << "4.) Hard\n";
	std::cout << "==================================================\n";
}

/*********************************************************************************
name:		getMenuChoice
parameters:	none
purpose:	gets input from keyboard; returns it to caller
*********************************************************************************/
char getMenuChoice()
{
	// variable used to store user choice
	char menuChoice = ' ';
	// prompt user
	std::cout << "Enter a menu choice: ";
	std::cin >> menuChoice;

	return menuChoice;
}

/*********************************************************************************
name:		playGame
parameters:	none
purpose:	allows the user to play game; generates a goal and an initial state;
			begins game loop
*********************************************************************************/
void playGame()
{
	// determines when game is done
	bool gameOver = false;
	// store user move choice
	char moveChoice = ' ';
	// counts moves taken to find goal state
	int countMoves = 0;

	// all pieces for 8 puzzle game
	Piece blank(0, true), one(1, false), two(2, false),
		three(3, false), four(4, false), five(5, false),
		six(6, false), seven(7, false), eight(8, false);

	// initialize initial state
	Piece initialState[9] = { two, eight, three,
								one, six, four,
								blank, seven, five };
	// initialize goal state
	Piece goalState[9] = { one, two, three,
								eight, blank, four,
								seven, six, five };

	// print initial state and goal state
	std::cout << "\nGoal State\n";
	printState(goalState);
	std::cout << "Initial State\n";
	printState(initialState);

	while (!gameOver)
	{
		// get input from user
		std::cout << "Enter a move: ";
		std::cin >> moveChoice;

		// move piece
		movePiece(initialState, moveChoice);
		// print new state
		printState(initialState);

		// check for goal state
		if (checkGoalState(initialState, goalState, 9))
		{
			std::cout << "Goal state found!\n";
			// increment final move
			countMoves++;
			// print final move count
			std::cout << "Total moves: " << countMoves << "\n";
			std::cout << "Press ENTER to continue...\n";
			std::cin.get();
			std::cin.get();
			gameOver = true;
		}
		else
		{
			// increment moves count
			countMoves++;
			// print moves taken
			std::cout << "Move count: " << countMoves << "\n\n";
		}
	}
}

/*********************************************************************************
name:		playGameBF_AI
parameters:	none
purpose:	AI using custom brute force search algorithm plays game
*********************************************************************************/
void playGameBF_AI()
{
	// all pieces for 8 puzzle game
	Piece blank(0, true), one(1, false), two(2, false),
		three(3, false), four(4, false), five(5, false),
		six(6, false), seven(7, false), eight(8, false);

	// initialize initial state
	Piece initialState[9] = { two, eight, three,
								one, six, four,
								blank, seven, five };
	// initialize goal state
	Piece goalState[9] = { one, two, three,
								eight, blank, four,
								seven, six, five };

	// instance of BFS_Queue class
	BFS_Queue bfs_queue;

	// begin search
	std::cout << "Current State\n";
	bfs_queue.bruteForceSearch(initialState, goalState);
}

/*********************************************************************************
name:		playGameBFS_AI
parameters:	none
purpose:	AI using BFS (breadth-first search) algorithm plays game
*********************************************************************************/
void playGameBFS_AI()
{
	// create an initial state
	int initialState[9] =		{ 2, 8, 3, 1, 6, 4, 0, 7, 5 };			// MAIN test case
	int initialStateEasy[9] =	{ 1, 2, 3, 0, 8, 4, 7, 6, 5 };			// EASY test case
	int initialStateMedium[9] = { 0, 8, 3, 2, 6, 4, 1, 7, 5 };			// MEDIUM test case
	int initialStateHard[9] =	{ 8, 3, 4, 2, 6, 5, 1, 7, 0 };			// HARD test case

	// create a new graph node
	Graph::GraphNode *root = nullptr;

	// print the difficulty menu
	difficultyMenu();
	char choice = getMenuChoice();

	switch (choice)
	{
		case '1':
			// initial state
			root = new Graph::GraphNode(initialState);
			break;

		case '2':
			// set initial state
			root = new Graph::GraphNode(initialStateEasy);
			break;

		case '3':
			// set initial state
			root = new Graph::GraphNode(initialStateMedium);
			break;

		case '4':
			// set initial state
			root = new Graph::GraphNode(initialStateHard);
			break;

		default:
			std::cout << "\n===== INVALID SELECTION =====\n";
	}

	// create a new graph
	Graph *graph = new Graph();
	// begin graph expansion and search
	std::list<Graph::GraphNode*> solution = graph->BFS(root);

	// deallocate memory
	delete root;
	delete graph;
}

/*********************************************************************************
name:		printState
parameters:	Piece object array
purpose:	prints state of Piece object
*********************************************************************************/
void printState(Piece arr[])
{
	// helper variable
	int count = 0;

	// display state
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

/*********************************************************************************
name:		movePiece
parameters:	Piece object array, int type
purpose:	checks input from user; if valid continue else return
			checks for a blank piece
			checks for invalid move; if invalid return
			moves piece
*********************************************************************************/
void movePiece(Piece arr[], char choice)
{
	switch (choice)
	{
		case '1':	// left move call
			for (int i = 0; i < 9; i++)
			{
				// check for blank piece
				if (arr[i].getValue() == 0)
				{
					// check for invalid move
					if (i == 0 || i == 3 || i == 6)
					{
						std::cout << "========== INVALID MOVE ==========\n";
						return;
					}
					// move piece
					Piece temp = arr[i - 1];
					arr[i - 1].setValue(0);
					arr[i - 1].setBlank(true);
					arr[i].setValue(temp.getValue());
					arr[i].setBlank(temp.isBlank());
				}
			}
			break;
		case '2': // right move call
			for (int i = 0; i < 9; i++)
			{
				// check for blank piece
				if (arr[i].getValue() == 0)
				{
					// check for invalid move
					if (i == 2 || i == 5 || i == 8)
					{
						std::cout << "========== INVALID MOVE ==========\n";
						return;
					}
					// move piece
					Piece temp = arr[i + 1];
					arr[i + 1].setValue(0);
					arr[i + 1].setBlank(true);
					arr[i].setValue(temp.getValue());
					arr[i].setBlank(temp.isBlank());
					// return to main to prevent continued execution
					return;
				}
			}
			break;
		case '3':	// up move call
			for (int i = 0; i < 9; i++)
			{
				// check for blank piece
				if (arr[i].getValue() == 0)
				{
					// check for invalid move
					if (i == 0 || i == 1 || i == 2)
					{
						std::cout << "========== INVALID MOVE ==========\n";
						return;
					}
					// move piece
					Piece temp = arr[i - 3];
					arr[i - 3].setValue(0);
					arr[i - 3].setBlank(true);
					arr[i].setValue(temp.getValue());
					arr[i].setBlank(temp.isBlank());
				}
			}
			break;
		case '4':	// down move call
			for (int i = 0; i < 9; i++)
			{
				// check for blank piece
				if (arr[i].getValue() == 0)
				{
					// check for invalid move
					if (i == 6 || i == 7 || i == 8)
					{
						std::cout << "========== INVALID MOVE ==========\n";
						return;
					}
					// move piece
					Piece temp = arr[i + 3];
					arr[i + 3].setValue(0);
					arr[i + 3].setBlank(true);
					arr[i].setValue(temp.getValue());
					arr[i].setBlank(temp.isBlank());
					// return to main to prevent continued execution
					return;
				}
			}
			break;
		default:
			// check for invalid input key
			std::cout << "\n========== INVALID CHOICE ==========\n";
	}
}

/*********************************************************************************
name:		checkGoalState
parameters: Piece object array, Piece object array, int type
purpose:	checks current state against goal state; if
			current state is different from goal state return false otherwise
			return true
*********************************************************************************/
bool checkGoalState(Piece state[], Piece goal[], int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		if (state[i].getValue() != goal[i].getValue())
		{
			return false;
		}
	}
	return true;
}