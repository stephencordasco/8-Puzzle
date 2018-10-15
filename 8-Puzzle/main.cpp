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
date:		11 October 2018
*********************************************************************************/
#include "State.h"

// function prototypes
void printState(Piece arr[]);
void movePiece(Piece arr[], int choice);
bool checkGoalState(Piece state[], Piece goal[], int arrSize);

int main()
{
	// ====================== SETUP ======================
	// all the pieces for the 8 puzzle game
	Piece blank(0, true), one(1, false), two(2, false),
		three(3, false), four(4, false), five(5, false),
		six(6, false), seven(7, false), eight(8, false);

	// determines when the game is done
	bool gameOver = false;

	// counts the moves taken to find the goal state
	int countMoves = 0;

	// user choice
	int uChoice = 0;

	// initialize the initial state
	Piece initialState[9] = {	two, eight, three,
								one, six, four,
								blank, seven, five	};
	// initialize the goal state
	Piece goalState[9] = {		one, two, three,
								eight, blank, four,
								seven, six, five	};

	// print the initial state and the goal state
	cout << "Goal State\n";
	printState(goalState);
	cout << "Initial State\n";
	printState(initialState);
	// ===================================================


	// ============ CONSTRUCT THE STATE SPACE ============
	cout << "Current State\n";
	State state(initialState);
	state.displayState();
	// ===================================================


	// ==================== GAME LOOP ====================
	while (!gameOver)
	{
		// get input from the user
		cout << "Enter a move: ";
		cin >> uChoice;
		// move the piece
		movePiece(initialState, uChoice);
		// print the new state
		printState(initialState);

		if (checkGoalState(initialState, goalState, 9))
		{
			cout << "Goal state found!\n";
			// increment the final move
			countMoves++;
			// print the final move count
			cout << "Total moves: " << countMoves << "\n";
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
	// ===================================================


	system("pause");
	return 0;
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
void movePiece(Piece arr[], int choice)
{
	switch (choice)
	{
		case 1:	// left move call
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
		case 2: // right move call
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
		case 3:	// up move call
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
		case 4:	// down move call
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