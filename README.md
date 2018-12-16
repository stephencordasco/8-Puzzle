# 8-Puzzle
Author: Stephen Cordasco

Required OS
  -	Windows

Download the Project
  -	Page Link: https://github.com/stephencordasco/8-Puzzle
  -	Download/Clone: https://github.com/stephencordasco/8-Puzzle.git

Install MS Visual Studio 2017
  -	https://docs.microsoft.com/en-us/visualstudio/install/install-visual-studio?view=vs-2017

Included Project Files and File Descriptions
The following files are included in the project:
●	Graph.h (a graph class declaration)
  o	Includes the GraphNode class and class function definitions.
  o	Includes the Graph class function declarations and attributes.
●	Graph.cpp (graph member functions and search algorithms are defined here)
  o	Includes the Graph class function definitions.
  o	Responsible for the Breadth-first search algorithm and A* search algorithm.
●	BFS_Queue.h (a queue class declaration)
  o	Includes the BFS_Queue class function declarations and attributes.
●	BFS_Queue.cpp (queue member functions and search algorithms are defined here)
  o	Includes the BFS_Queue class function definitions.
  o	Responsible for the brute-force search algorithm.
●	State.h (node class declaration for the queue)
  o	Includes the State class function declarations and attributes.
●	State.cpp (constructor for each queue node)
  o	Includes the State class function definitions.
  o	Responsible for creating an instance of a state.
●	Piece.h (Piece class declaration)
  o	Includes the Piece class function declarations and attributes.
●	Piece.cpp (Piece member functions (constructors, setters and getters) are defined here)
  o	Includes the Piece class function definitions.
  o	Responsible for creating an instance of a piece.
●	main.cpp (main application implementation and program run)
  o	Includes the main program loop:
    ▪	Display the menu
    ▪	Get input from the keyboard
    ▪	Run the selected function
    ▪	Repeat

Running 8-Puzzle
•	Open Project/Solution and select 8-Puzzle or Clone 8-Puzzle into MS Visual Studio 2017
•	Build 8-Puzzle using MS Visual Studio 2017 (F7)
•	After successful build and compilation:
  o	Run the new executable file found in the Project Folder or
  o	Run the project using MS Visual Studio 2017 (F5, Ctrl + F5, Play Button)
•	Features:
  o	Play 8-Puzzle
    ▪	Strategically move the blank piece around the board to match the Goal State
    ▪	Controls
      -	‘1’ key – Left
      -	‘2’ key – Up
      -	‘3’ key – Right
      -	‘4’ key – Down
    ▪	Game will end once Goal State is found or upon closing the console window.
    
  o	AI Plays 8-Puzzle (Using Custom Brute Force)
    ▪	AI will use a custom brute-force search algorithm to solve 8-puzzle
    
  o	AI Plays 8-Puzzle (Using BFS)
    ▪	AI will use breath-first search algorithm to solve 8-puzzle
    ▪	Difficulty refers to state space size
      -	Standard is the primary test case used for development
      -	Easy is a simplified version of Standard
      -	Medium is a less simplified version of Standard
      -	Hard and Custom are new test cases that search hundreds to thousands of states
    ▪	After goal state has been found, press ENTER to view the trace path from goal state to initial state
    
  o	AI Plays 8-Puzzle (Using A*)
    ▪	AI will use A* search algorithm to solve 8-puzzle
    ▪	Same difficulty rules apply here
    ▪	After goal state has been found, press ENTER to view the trace path from goal state to initial state
    
  o	Exit
    ▪	Terminates the project closing the console window.

Warnings
•	A* search algorithm uses an admissible heuristic, but it is not optimal.
•	A* search algorithm may take a long time when on Hard or Custom difficulty settings.
  o Current results have taken up to 500 seconds to search for goal state, expanding and searching over 9,000 states.
