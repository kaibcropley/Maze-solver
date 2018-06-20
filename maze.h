//
// Created by Kaib Cropley on 4/19/2018.
//

#include <iostream>

#ifndef ASS3_MAZE_H
#define ASS3_MAZE_H


class Maze {
	// Allows printing to console
	friend std::ostream &operator<<(std::ostream &out, Maze &maze);

public:
	// Constructors
	Maze();

	explicit Maze(std::string fileName);

	//Destructor
	~Maze();

	// Getter methods
	// Takes coordinates and returns if it is clear (can move there)
	bool isClear(int row, int col) const;

	// Takes coordinates and returns if it is a wall
	bool isWall(int row, int col) const;

	// Takes coordinates and returns if it is a path
	bool isPath(int row, int col) const;

	// Takes coordinates and returns if it is visited
	bool isVisited(int row, int col) const;

	// Returns true if spot is the exit
	bool isExit(int row, int col) const;

	// Setter methods
	// Takes coordinates and sets it as a path
	void MarkAsPath(int row, int col);

	// Takes coordinates and sets it as visited
	void MarkAsVisited(int row, int col);

private:
	// Maz max size
	const static int MAX_FIELD = 100;
	// Holds the maze
	char field[MAX_FIELD][MAX_FIELD];
	// Details of the maze
	int width;
	int height;
	int exitRow;
	int exitCol;
};


#endif //ASS3_MAZE_H
