//
// Created by Kaib Cropley on 4/19/2018.
//

#include <fstream>
#include "maze.h"

// Default constructor
Maze::Maze() {
	width = 0;
	height = 0;
}

// Constructor that takes the file name then stores the maze data
Maze::Maze(std::string fileName) {
	std::ifstream in(fileName);
	if (!in) {
		std::cerr << "Error opening file: " << fileName << std::endl;
	}
	in >> width;
	in >> height;
	in >> exitRow;
	in >> exitCol;
	in.get();
	in.get();

	for (int i{0}; i < height; i++) {
		for (int j{0}; j < width; j++) {
			field[i][j] = static_cast<char>(in.get());
		}
		in.get();
		in.get();
	}
}

// Destructor
Maze::~Maze() {

}

// Allows printing to the console
std::ostream &operator<<(std::ostream &out, Maze &maze) {
	std::cout << "Width: " << maze.width <<
			  "\nHeight: " << maze.height <<
			  "\nExit: (" << maze.exitRow << "," << maze.exitCol << ")\n";
	for (int row{0}; row < maze.height; row++) {
		for (int col{0}; col < maze.width; col++) {
			out << maze.field[row][col];
		}
		out << std::endl;
	}
	out << std::endl;
	return out;
}

// Takes coordinates and returns if it is clear (can move there)
bool Maze::isClear(int row, int col) const {
	if (row < 0 || col < 0) {
		return false;
	}
	return (field[row][col] == ' ');
}

// Takes coordinates and returns true if it is a wall
bool Maze::isWall(int row, int col) const {
	if (row < 0 || col < 0) {
		return true;
	}
	return (field[row][col] == 'X');
}

// Take coordinates and returns true if it's a path
bool Maze::isPath(int row, int col) const {
	if (row < 0 || col < 0) {
		return false;
	}
	return (field[row][col] == '*');
}

// Takes coordinates and returns true if it's been visited
bool Maze::isVisited(int row, int col) const {
	if (row < 0 || col < 0) {
		return false;
	}
	return (field[row][col] == '+' || field[row][col] == '*');
}

// Takes coordinates and sets it as a path
void Maze::MarkAsPath(int row, int col) {
	field[row][col] = '*';
}

// Takes coordinates and sets it as visited
void Maze::MarkAsVisited(int row, int col) {
	field[row][col] = '+';
}

// Takes coordinates and returns true if it is the exit
bool Maze::isExit(int row, int col) const {
	return (row == exitRow && col == exitCol);
}
