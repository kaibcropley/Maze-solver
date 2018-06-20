#include <iostream>
#include <cassert>
#include "maze.h"
#include "creature.h"

using namespace std;

// Test printing maze, checking some getter methods
void test1() {
	Maze maze("Test Maze 1.txt");

	assert(maze.isClear(1, 1));
	assert(maze.isClear(1, 2));
	assert(maze.isClear(1, 3));
	assert(maze.isClear(2, 3));
	assert(!maze.isClear(1, 0));
	assert(!maze.isClear(2, 1));

	assert(maze.isWall(0, 1));
	assert(maze.isWall(1, 0));
	assert(maze.isWall(1, 4));
	assert(maze.isWall(2, 2));
	assert(!maze.isWall(1, 1));
	assert(!maze.isWall(2, 3));

	assert(maze.isExit(2, 3));
	assert(!maze.isExit(1, 1));
}

// Test maze setter methods
void test2() {
	Maze maze("Test Maze 2.txt");

	maze.MarkAsVisited(1, 1);
	maze.MarkAsVisited(2, 1);
	maze.MarkAsVisited(3, 1);
	maze.MarkAsVisited(4, 1);
	assert(maze.isVisited(1, 1));
	assert(maze.isVisited(2, 1));
	assert(maze.isVisited(3, 1));
	assert(maze.isVisited(4, 1));


	maze.MarkAsPath(1, 1);
	maze.MarkAsPath(2, 1);
	maze.MarkAsPath(2, 2);
	maze.MarkAsPath(3, 2);
	maze.MarkAsPath(3, 3);
	maze.MarkAsPath(3, 4);
	maze.MarkAsPath(3, 5);
	maze.MarkAsPath(3, 6);
	maze.MarkAsPath(2, 6);
	maze.MarkAsPath(1, 6);
	maze.MarkAsPath(0, 6);
	assert(maze.isPath(1, 1));
	assert(maze.isPath(2, 1));
	assert(maze.isPath(2, 2));
	assert(maze.isPath(3, 2));
	assert(maze.isPath(3, 4));
	assert(maze.isPath(3, 5));

}

// Test maze solver on an easy maze
void test3() {
	Maze maze("Test Maze 1.txt");
	assert(maze.isClear(1, 1));
	Creature c(1, 1);
	cout << c;
	cout << "Path: " << c.Solve(maze) << endl;
	cout << maze;
}

// Test maze solver on an easy maze
void test4() {
	Maze maze("Test Maze 2.txt");
	cout << maze;
	assert(maze.isClear(1, 1));
	Creature c(1, 1);
	cout << "Path: " << c.Solve(maze) << endl;
	cout << maze;

}

// Test maze solver on the maze from the book
void test5() {
	Maze maze("Test maze 3.txt");
	assert(maze.isClear(5, 15));
	Creature c(5, 15);
	cout << maze;
	cout << "Path: " << c.Solve(maze) << endl;
	cout << maze;
}

// Test maze solver on hard maze
void test6() {
	Maze maze("Test maze 4.txt");
	assert(maze.isClear(3, 1));
	Creature c(3, 1);
	cout << maze;
	cout << "Path: " << c.Solve(maze) << endl;
	cout << maze;
}

// Kaibs maze
void test7() {
	Maze maze("Test maze K.txt");
	assert(maze.isClear(1, 11));
	Creature c(1, 11);
	cout << maze;
	cout << "Path: " << c.Solve(maze) << endl;
	cout << maze;
}

// Laurens impossible maze
void test8() {
	Maze maze("Test maze L.txt");
	assert(maze.isClear(6, 4));
	Creature c(6, 4);
	cout << maze;
	cout << "Path: " << c.Solve(maze) << endl;
	cout << maze;
}

// Test specifically goNorth
void testNorth() {
	Maze maze("Test maze North.txt");
	assert(maze.isClear(4, 3));
	Creature c(4, 3);
	cout << c.Solve(maze) << endl;
	cout << maze;
}

// Test specifically goSouth
void testSouth() {
	Maze maze("Test maze South.txt");
	assert(maze.isClear(0, 1));
	Creature c(0, 1);
	cout << c.Solve(maze) << endl;
	cout << maze;
}

// Test specifically goWest
void testWest() {
	Maze maze("Test maze West.txt");
	assert(maze.isClear(2, 3));
	Creature c(2, 3);
	cout << c.Solve(maze) << endl;
	cout << maze;
}

// Test specifically goEast
void testEast() {
	Maze maze("Test maze East.txt");
	assert(maze.isClear(1, 0));
	Creature c(1, 0);
	cout << c.Solve(maze) << endl;
	cout << maze;
}

// Runs all tests
void testAll() {
	testNorth();
	testSouth();
	testWest();
	testEast();
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	cout << endl << "All test are complete!";
}

int main() {
	testAll();
	return 0;
}