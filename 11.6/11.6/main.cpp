/**
	wanyunpeng  12.15
	questions : Given an MX N matrix in which each row and each column is sorted in ascending
				order, write a method to find an element.
	备注：先找行，再找列
**/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
using namespace std;

bool findElement(vector<vector<int>> &grid, int target);

int main()
{
	vector<vector<int>> grid = {
		{ 15, 20, 40, 85 },
		{20,35,80,95},
		{30,55,95,105},
		{40,80,100,120}
	};
	
	cout << findElement(grid, 45) << endl;

	list<int> a = { 1, 2, 3 };
	list<int> b = { 11, 22, 33};
	transform(a.begin(), a.end(), b.begin(),a.begin(), plus<int>());
	for (auto i : a)
	{
		cout << i << " ";
	}
	cout << endl;
	return 0;
}


bool findElement(vector<vector<int>> &grid, int target)
{
	if (grid.empty()) return false;
	const int m = grid.size() - 1;
	const int n = grid[0].size() - 1;

	int row = 0, col = n;
	while (row <= m && col >= 0)
	{
		if (grid[row][col] == target)
			return true;
		else if (grid[row][col] > target)
		{
			col--;
		}
		else
			row++;
	}
	return false;
}