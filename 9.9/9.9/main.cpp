/**
	wanyupeng  12.8
	questions : Write an algorithm to prim all ways of arranging eight queens on an 8x8 chess
				board so that none of them share the same row, column or diagonal. In this case,
				"diagonal" means all diagonals, notjust the two that bisect the board.
	±¸×¢£º
**/

#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

class solution
{
	vector<vector<int>> grid;
	vector<int> main_dialog; // i - j + n
	vector<int> anti_dialog;// i + j
	vector<int> col;
	int count;
public:
	solution()
	{
		grid = vector<vector<int>>(8, vector<int>(8, 0));
		main_dialog = vector<int>(16, 0); // i - j + 8
		anti_dialog = vector<int>(16, 0); // i + j
		col = vector<int>(8, 0);
		count = 0;
	}
	int allQueens()
	{
		dfs(0, 0);
		return count;
	}
	void dfs(int x, int y)
	{
		if (x == 8)
		{
			count++;
			return;
		}

		for (int j = y; j < 8; ++j)
		{
			if (isValid(x, j))
			{
				grid[x][j] = 9;
				main_dialog[x - j + 8] = anti_dialog[x + j] = col[j] = 1;
				dfs(x + 1, 0);
				grid[x][j] = 0;
				main_dialog[x - j + 8] = anti_dialog[x + j] = col[j] = 0;
			}
				
		}

	}
	bool isValid(int x, int y)
	{
		if (main_dialog[x - y + 8] || anti_dialog[x + y] || col[y])
			return false;
		return true;
	}

};





int main()
{
	multimap<int, int> mm;
	mm.insert({ 1, 1 }); mm.insert({ 1, 2 });
	multimap<int,int>::iterator ii = mm.emplace(1, 3);
	cout << ii->second << endl;
	map<int, int>::iterator it = mm.find(1);
	//multimap<int,int>::difference_type
	cout << distance(mm.begin(), it) << endl;
	for (map<int, int>::iterator itr = mm.begin(); itr != mm.end(); ++itr)
		cout << itr->second << endl;
	solution s;
	cout << s.allQueens() << endl;
	return 0;
}