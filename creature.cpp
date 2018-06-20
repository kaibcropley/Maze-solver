//
// Created by Kaib Cropley on 4/21/2018.
//

#include "creature.h"

// Constructors
Creature::Creature() {
}

// Parameter constructor
Creature::Creature(int row, int col) : startRow{row}, startCol{col},
									   row{row}, col{col}, path{""} {

}

// Destructor
Creature::~Creature() {
}

// Allows printing to the console
std::ostream &operator<<(std::ostream &output, Creature &c) {
	output << "C(" << c.row << "," << c.col << ")" << std::endl;
	return output;
}

// Solves the maze
std::string Creature::Solve(Maze &maze) {
	maze.MarkAsPath(row, col);
	if (maze.isExit(row, col)) {
		return "At exit";
	}

	if (goNorth(maze)) {
		return path;
	}

	row = startRow;
	col = startCol;
	if (goSouth(maze)) {
		return path;
	}

	row = startRow;
	col = startCol;
	if (goWest(maze)) {
		return path;
	}

	row = startRow;
	col = startCol;
	if (goEast(maze)) {
		return path;
	}

	return "X";
}

// Moves creature in cardinal direction
// Moves North
bool Creature::goNorth(Maze &maze) {
	bool success;
	if (maze.isClear(row - 1, col)) {
		row -= 1;
		maze.MarkAsPath(row, col);
		path += "N";
		if (maze.isExit(row, col)) {
			success = true;
		} else {
			success = goNorth(maze);
			if (!success) {
				success = goWest(maze);
				if (!success) {
					success = goEast(maze);
					if (!success) {
						maze.MarkAsVisited(row, col);
						row += 1;
						removeLastChar();
					}
				}
			}
		}
	} else {
		success = false;
	}
	return success;
}

// Moves South
bool Creature::goSouth(Maze &maze) {
	bool success;
	if (maze.isClear(row + 1, col)) {
		row += 1;
		maze.MarkAsPath(row, col);
		path += "S";
		if (maze.isExit(row, col)) {
			success = true;
		} else {
			success = goSouth(maze);
			if (!success) {
				success = goWest(maze);
				if (!success) {
					success = goEast(maze);
					if (!success) {
						maze.MarkAsVisited(row, col);
						row -= 1;
						removeLastChar();
					}
				}
			}
		}
	} else {
		success = false;
	}
	return success;
}

// Moves West
bool Creature::goWest(Maze &maze) {
	bool success;
	if (maze.isClear(row, col - 1)) {
		col -= 1;
		maze.MarkAsPath(row, col);
		path += "W";
		if (maze.isExit(row, col)) {
			success = true;
		} else {
			success = goWest(maze);
			if (!success) {
				success = goNorth(maze);
				if (!success) {
					success = goSouth(maze);
					if (!success) {
						maze.MarkAsVisited(row, col);
						col += 1;
						removeLastChar();
					}
				}
			}
		}
	} else {
		success = false;
	}
	return success;
}

// Moves East
bool Creature::goEast(Maze &maze) {
	bool success;
	if (maze.isClear(row, col + 1)) {
		col += 1;
		maze.MarkAsPath(row, col);
		path += "E";
		if (maze.isExit(row, col)) {
			success = true;
		} else {
			success = goEast(maze);
			if (!success) {
				success = goNorth(maze);
				if (!success) {
					success = goSouth(maze);
					if (!success) {
						maze.MarkAsVisited(row, col);
						col -= 1;
						removeLastChar();
					}
				}
			}
		}
	} else {
		success = false;
	}
	return success;
}

// Removes last character from path as we backtrack
void Creature::removeLastChar() {
	path.erase(path.size() - 1, 1);
}

