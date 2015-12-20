/**
	wanyunpeng  12.7
	questions : Imagine a robot sitting on the upper left comer of an X by Ygrid. Therobot can only
				move in two directions:right and down. How many possible paths are there for the
				robot to go from (0, 0) to (X, Y) ?
				FOLLOW UP
				Imagine certain spots are "off limits," such that the robot cannot step on them.
				Design an algorithm to find a path for the robot from the top left to the bottom right.
	±¸×¢£º
**/

#include <iostream>
#include <vector>

using namespace std;

int solution(int x, int y);
vector<vector<int>> obstacles(vector<vector<int>> &grid);
void dfs(vector<vector<int>> &grid, int x, int y, vector<vector<int>> &path);
int main()
{
	cout << solution(3, 4) << endl;
	vector<vector<int>> grid = {
		{0,0,0},
		{0,1,0},
		{0,0,0}
	};
	obstacles(grid);
	return 0;
}

int solution(int x, int y)
{
	vector<int> f(y, 1);
	for (int i = 1; i < x; ++i)
	{
		f[0] = 1;
		for (int j = 1; j < y; ++j)
		{
			f[j] = f[j] + f[j - 1];
		}
	}
	for (auto i : f)
		cout << i << " ";
	cout << endl;
	return f.back();
}

vector<vector<int>> obstacles(vector<vector<int>> &grid)
{
	if (grid.empty()) return{};
	if (grid[0][0] == 1) return{ {0,0} };
	vector<vector<int>> path;
	dfs(grid,  0, 0, path);
	return path;
}

void dfs(vector<vector<int>> &grid, int x, int y, vector<vector<int>> &path)
{
	const int m = grid.size();
	const int n = grid[0].size();

	if (x == m - 1 && y == n - 1)
	{
		path.push_back({ x, y });
		for (auto & row : path)
		{
			for (auto & i : row)
				cout << i << " ";
			cout << endl;
		}
		cout << endl;
		path.pop_back();
		return;
	}

	if (x == m || y == n)
		return;
	if (grid[x][y] == 1)
		return;

	path.push_back({ x, y });
	dfs(grid, x + 1, y, path);
	dfs(grid, x, y + 1, path);
	path.pop_back();
	return;
}