#include "Maze.h"

int main()
{
	int n = 5;
	int m = 5;
	Maze maze = Maze(n, m);
	for(int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (j == i)
			{
				maze.makeConnection(i, j, i + 1, j);
				maze.makeConnection(i + 1, j, i + 1, j + 1);
			}
		}
	maze.removeConnection(0, 0, 1, 0);
	maze.printMaze();
	return 0;
}