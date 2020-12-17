#include "Maze.h"


void main()
{
	int n = 5;
	int m = 5;
	Maze maze = Maze(n, m);
	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (j == i)
			{
				maze.makeConnection(i, j, i, j + 1);
				maze.makeConnection(i, j + 1, i + 1, j + 1);
			}
		}
	maze.printMaze();
	return;
}