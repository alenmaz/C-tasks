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
			bool up = false;
			bool left = false;
			bool right = m_field[i * m_n + j].right();
			bool down = m_field[i * m_n + j].down();

			if (j > 0)
				up = hasConnection(i, j, i, j - 1) && cell(i, j - 1).down();
			if (i > 0)
				left = hasConnection(i, j, i - 1, j) && cell(i - 1, j).right();

			char c = 248;
			if (up && down)
			{
				if (!left && !right)
					c = 179;
				if (right && left)
					c = 197;
				if (left && !right)
					c = 180;
				if (right && !left)
					c = 195;

			}

			if (up && !down)
			{
				if (right && left)
					c = 193;
				if (!right && left)
					c = 217;
				if (right && !left)
					c = 192;
			}

			if (!up && down)
			{
				if (!right && left)
					c = 191;
				if (right && left)
					c = 194;
				if (right && !left)
					c = 218;
			}

			if (!up && !down)
			{
				if (left && right)
					c = 196;
			}

			printf("%c", c);
		}

		printf("\n");
	}
}

Maze::~Maze()
{
	delete m_field;
}