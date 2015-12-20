/**
	wanyunpeng  11.15
	questions:Write an algorithm such that if an elementin an MxN matrix is 0, its entire row and
			  column are set to 0.
	±¸×¢£º
**/

#include <iostream>
#include <vector>

using namespace std;

void solution(vector<vector<int>> &grid);

int main()
{
	vector<vector<int>> grid = {
		{1,2,0,4,5},
		{1,2,2,2,1},
		{5,2,2,2,2}
	};
	solution(grid);
	for (const auto& row : grid)
	{
		for (const auto& i : row)
			cout << i << " ";
		cout << endl;
	}
	return 0;
}

void solution(vector<vector<int>> &grid)
{
	if (grid.empty()) return;
	
	const int m = grid.size();
	const int n = grid[0].size();

	bool row = false, col = false;
	for (int j = 0; j < n; ++j)
	{
		if (grid[0][j] == 0)
		{
			row = true;
			break;
		}
	}

	for (int i = 0; i < m; ++i)
	{
		if (grid[i][0] == 0)
		{
			col = true;
			break;
		}
	}

	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			if (grid[i][j] == 0)
			{
				grid[i][0] = 0;
				grid[0][j] = 0;
			}
		}
	}

	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			if (grid[i][0] == 0 || grid[0][j] == 0)
				grid[i][j] = 0;
		}
	}

	if (row)
	{
		for (int j = 0; j < n; ++j)
			grid[0][j] = 0;
	}

	if (col)
	{
		for (int i = 0; i < m; ++i)
			grid[i][0] = 0;
	}
}