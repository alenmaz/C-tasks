#include "Maze.h"

Maze::Maze(int n, int m)
{
	m_field = new MCell[n * m];
	m_n = n;
	m_m = m;
}

const MCell& Maze::cell(int i, int j) const
{
	int index = i * m_n + j;
	if (index < m_n * m_m)
		return m_field[index];
}

bool Maze::hasConnection(int i1, int j1, int i2, int j2)
{
	return (abs(j2 - j1) == 0 && abs(i2 - i1) == 1) || (abs(i2 - i1) == 0 && abs(j2 - j1) == 1);
}

bool Maze::makeConnection(int i1, int j1, int i2, int j2)
{
	int index = min(i1, i2) * m_n + min(j1, j2);
	if (index < m_n * m_m)
	{

		if (abs(j2 - j1) == 0 && abs(i2 - i1) == 1)
		{
			m_field[index].m_down = true;
			return true;
		}
		if ((abs(i2 - i1) == 0 && abs(j2 - j1) == 1))
		{
			m_field[index].m_right = true;
			return true;
		}
	}
	return false;
}

bool Maze::removeConnection(int i1, int j1, int i2, int j2)
{
	int index = min(i1, i2) * m_n + min(j1, j2);
	if (index < m_n * m_m)
	{
		if (abs(j2 - j1) == 0 && abs(i2 - i1) == 1)
		{
			m_field[index].m_down = false;
			return true;
		}
		if ((abs(i2 - i1) == 0 && abs(j2 - j1) == 1))
		{
			m_field[index].m_right = false;
			return true;
		}
	}
	return false;
}

void Maze::printMaze()
{
	for (int i = 0; i < m_n; i++)
	{
		for (int j = 0; j < m_m; j++)
		{
			bool up = false;
			bool left = false;
			bool right = false;
			bool down = false;

			if (i > 0)
				up = hasConnection(i, j, i - 1, j) && cell(i - 1, j).down();
			if (i < m_m)
				down = cell(i, j).down();
			if (j > 0)
				left = hasConnection(i, j, i, j - 1) && cell(i, j - 1).right();
			if (j < m_n)
				right = cell(i, j).right();

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
				if (left && right)
					c = 196;

			printf("%c", c);
		}

		printf("\n");
	}
}

Maze::~Maze()
{
	delete m_field;
}