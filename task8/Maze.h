#include <algorithm>
#include <iostream>
#include "MCell.h"

using namespace std;

class Maze
{
private:
	int m_n;
	int m_m;
	MCell* m_field;
public:
	Maze(int n, int m);
	const MCell& cell(int i, int j) const;
	bool hasConnection(int i1, int j1, int i2, int j2);
	bool makeConnection(int i1, int j1, int i2, int j2);
	bool removeConnection(int i1, int j1, int i2, int j2);
	void printMaze();
	~Maze();
};