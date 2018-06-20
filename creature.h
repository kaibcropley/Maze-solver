//
// Created by Kaib Cropley on 4/21/2018.
//

#ifndef ASS3_CREATURE_H
#define ASS3_CREATURE_H

#include <iostream>
#include "maze.h"


class Creature {
	// Allows printing to the console
	friend std::ostream &operator<<(std::ostream &output, Creature &c);

public:
	// Constructors
	Creature();

	Creature(int row, int col);

	// Destructor
	~Creature();

	// Solves the maze
	std::string Solve(Maze &maze);

private:
	// Current maze
	Maze maze;
	// Starting position
	int startRow;
	int startCol;
	// Current position
	int row;
	int col;
	// Path from the start to the end
	std::string path;

	// Move in cardinal directions
	bool goNorth(Maze &maze);

	bool goSouth(Maze &maze);

	bool goWest(Maze &maze);

	bool goEast(Maze &maze);

	// Removes last character from path as we backtrack
	void removeLastChar();
};


#endif //ASS3_CREATURE_H
