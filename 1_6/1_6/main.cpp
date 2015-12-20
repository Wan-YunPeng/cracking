/**
	wanyunpeng  11.15
	questions:Given an image represented by an NxN matrix, where each pixel in the image is 4
			  bytes, write a method to rotate the imageby 90 degrees. Canyou do this in place?
	备注：
**/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void rorate(vector<vector<int>> &grid);

int main()
{
	vector<vector<int>> grid;
	for (int i = 0; i < 4; ++i)
	{
		grid.push_back(vector<int>());
		for (int j = 0; j < 4; ++j)
			grid[i].push_back(i * 4 + j + 1);
	}
	rorate(grid);
	for (const auto& row : grid)
	{
		for (const auto& i : row)
			cout << i << " ";
		cout << endl;
	}
	return 0;
}

void rorate(vector<vector<int>> &grid)
{
	if (grid.empty()) return;
	const int m = grid.size();
	const int n = grid[0].size();

	// 沿主对角线翻转
	for (int i = 0; i < m; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			swap(grid[i][j], grid[j][i]);
		}
	}

	// 沿垂直中间线翻转
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n / 2; ++j)
		{
			swap(grid[i][j], grid[i][n - j - 1]);
		}
	}
}