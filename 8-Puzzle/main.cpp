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

// function prototypes
void printMenu();
char getMenuChoice();
void playGame();
void playGameBFS_AI();
void printState(Piece arr[]);
void movePiece(Piece arr[], char choice);
bool checkGoalState(Piece state[], Piece goal[], int arrSize);

int main()
{
	// user choice
	char menuChoice = ' ';
	// begin program loop
	do
	{
		// print the menu
		printMenu();
		menuChoice = getMenuChoice();
		// get the menuChoice
		switch (menuChoice)
		{
			case '1':	// user plays the game
				playGame();
				break;

			case '2': // AI plays the game
				playGameBFS_AI();
				break;

			case '3':
				cout << "Goodbye!\n\n";
				break;

			default:
				cout << "\nINVALID MENU CHOICE\n";
		}

	} while (menuChoice != '3');

	system("pause");
	return 0;
}

void printMenu()
{
	cout << "==================== 8-Puzzle ====================\n\n";
	cout << "1.) Play 8-Puzzle\n";
	cout << "2.) AI Plays 8-Puzzle (Using BFS)\n";
	cout << "3.) Exit\n";
	cout << "==================================================\n";
}

char getMenuChoice()
{
	cout << "Enter a menu choice: ";
	char menuChoice = ' ';
	cin >> menuChoice;

	return menuChoice;
}

void playGame()
{
	// determines when the game is done
	bool gameOver = false;
	// store user move choice
	char moveChoice = ' ';
	// counts the moves taken to find the goal state
	int countMoves = 0;

	// all the pieces for the 8 puzzle game
	Piece blank(0, true), one(1, false), two(2, false),
		three(3, false), four(4, false), five(5, false),
		six(6, false), seven(7, false), eight(8, false);

	// initialize the initial state
	Piece initialState[9] = { two, eight, three,
								one, six, four,
								blank, seven, five };
	// initialize the goal state
	Piece goalState[9] = { one, two, three,
								eight, blank, four,
								seven, six, five };

	// print the initial state and the goal state
	cout << "\nGoal State\n";
	printState(goalState);
	cout << "Initial State\n";
	printState(initialState);

	while (!gameOver)
	{
		// get input from the user
		cout << "Enter a move: ";
		cin >> moveChoice;
		// move the piece
		movePiece(initialState, moveChoice);
		// print the new state
		printState(initialState);
		// check for goal state
		if (checkGoalState(initialState, goalState, 9))
		{
			cout << "Goal state found!\n";
			// increment the final move
			countMoves++;
			// print the final move count
			cout << "Total moves: " << countMoves << "\n\n\n";
			gameOver = true;
		}
		else
		{
			// increment the moves count
			countMoves++;
			// print the moves taken
			cout << "Move count: " << countMoves << "\n\n";
		}
	}
}

void playGameBFS_AI()
{
	// all the pieces for the 8 puzzle game
	Piece blank(0, true), one(1, false), two(2, false),
		three(3, false), four(4, false), five(5, false),
		six(6, false), seven(7, false), eight(8, false);

	// initialize the initial state
	Piece initialState[9] = { two, eight, three,
								one, six, four,
								blank, seven, five };
	// initialize the goal state
	Piece goalState[9] = { one, two, three,
								eight, blank, four,
								seven, six, five };

	// instance of BFS_Queue class
	BFS_Queue bfs_queue;

	// begin search
	cout << "Current State\n";
	bfs_queue.BFS(initialState, goalState);
}

/*********************************************************************************
name:		printState
parameters:	Piece object array
purpose:	prints the state of the Piece object calling the function
*********************************************************************************/
void printState(Piece arr[])
{
	// helper variable
	int count = 0;

	// display the initial state
	cout << "-------\n";
	for (int i = 0; i < 9; i++)
	{
		cout << "|" << arr[i].getValue();
		count++;
		if (count == 3)
		{
			cout << "|\n";
			count = 0;
		}
	}
	cout << "-------\n";
}

/*********************************************************************************
name:		movePiece
parameters:	Piece object array, int type
purpose:	checks the input from the user; if valid continue else return
			checks for a blank piece
			checks for invalid move; if invalid return
			moves the piece
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
						cout << "========== INVALID MOVE ==========\n";
						return;
					}
					// move the piece
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
						cout << "========== INVALID MOVE ==========\n";
						return;
					}
					// move the piece
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
						cout << "========== INVALID MOVE ==========\n";
						return;
					}
					// move the piece
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
						cout << "========== INVALID MOVE ==========\n";
						return;
					}
					// move the piece
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
			cout << "\n========== INVALID CHOICE ==========\n";
	}
}

/*********************************************************************************
name:		checkGoalState
parameters: Piece object array, Piece object array, int type
purpose:	checks the current state against the goal state; if the
			current state is different from the goal state return false otherwise
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