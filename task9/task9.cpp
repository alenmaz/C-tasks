#include "Maze.h"
#include "MTreeNode.h"

void printTree(const int* dists, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%i ", dists[i * n + j]);
		printf("\n");
	}
}

int* makeTree(MTreeNode* tree, Maze* maze, int n, int* dists)
{
	int i = tree->i();
	int j = tree->j();
	dists[i * n + j] = tree->distance();
	auto cell = maze->cell(i, j);
	if (cell.right())
	{
		tree->addChild(i, j + 1);
		makeTree(tree->hasChild(i, j + 1), maze, n, dists);
	}

	if (cell.down())
	{
		tree->addChild(i + 1, j);
		makeTree(tree->hasChild(i + 1, j), maze, n, dists);
	}
	return dists;
}

void main()
{
    int n = 5;
    int m = 5;
	Maze maze = Maze(n, m);
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < m - 1; j++)
		{
			if (j == i)
			{
				maze.makeConnection(i, j, i, j + 1);
				maze.makeConnection(i, j + 1, i + 1, j + 1);
				maze.makeConnection(i, j, i + 1, j);
				for (int s = 1; j + s + 1 < n && i + s + 1 < m; s++)
				{
					maze.makeConnection(i, j + s, i, j + s + 1);
					maze.makeConnection(i + s, j, i + s + 1, j);
				}
			}
		}
	maze.printMaze();

	int* dists = new int[n * m];
	MTreeNode* tree = MTreeNode::beginTree(0, 0);
	printTree(makeTree(tree, &maze, n, dists), n, m);

    return;
}
