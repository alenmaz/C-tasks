#include "Maze.h"

Maze::Maze(int n, int m)
{
	m_field = new MCell[n*m];
	m_n = n;
	m_m = m;
}

const MCell& Maze::cell(int i, int j) const
{
	return m_field[i*m_n + j];
}

bool Maze::hasConnection(int i1, int j1, int i2, int j2)
{
	return (abs(j2 - j1) == 0 && abs(i2 - i1) == 1) || (abs(i2 - i1) == 0 && abs(j2 - j1) == 1);
}

bool Maze::makeConnection(int i1, int j1, int i2, int j2)
{
	if (abs(j2 - j1) == 0 && abs(i2 - i1) == 1)
	{
		m_field[min(i1, i1) * m_n + j1].m_right = true;
		return true;
	}
	if ((abs(i2 - i1) == 0 && abs(j2 - j1) == 1))
	{
		m_field[i1 * m_n + min(j1, j2)].m_down = true;
		return true;
	}
	return false;
}

bool Maze::removeConnection(int i1, int j1, int i2, int j2)
{
	MCell currCell;
	if (abs(j2 - j1) == 0 && abs(i2 - i1) == 1)
	{
		m_field[min(i1, i1) * m_n + j1].m_right = false;
		return true;
	}
	if ((abs(i2 - i1) == 0 && abs(j2 - j1) == 1))
	{
		m_field[i1 * m_n + min(j1, j2)].m_down = false;
		return true;
	}
	return false;
}

void Maze::printMaze()
{
	for (int j = 0; j < m_m; j++)
	{
		for (int i = 0; i < m_n; i++)
		{
			if (m_field[i * m_n + j].down())
				printf("%c", 191);
			else
			{
				if (m_field[i * m_n + j].right())
					printf("%c", 192);
				else
					printf("0");
			}
		}
		printf("\n");
	}
}

Maze::~Maze()
{
	delete m_field;
}