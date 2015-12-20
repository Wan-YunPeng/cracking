/**
	wanyunpeng 12.8
	questions : Implement an algorithm to print all valid (i.e., properly opened and closed) combinations ofn-pairs of parentheses.
	±¸×¢£º
**/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<string> generate(int n);
void dfs(vector<string> &re, string& path, int left, int right);

int main()
{
	map<int, int> mmap;
	mmap[2] = 2;
	mmap[3] = 3;
	mmap[5] = 5;
	int val = 4;
	map<int, int> ::iterator prev = mmap.end(),itr;
	for (itr = mmap.begin(); itr != mmap.end(); ++itr)
	{
		if (itr->first < val)
			prev = itr;
	}
	if (prev != mmap.end())
		cout << prev->first << endl;
	int n = 3;
	vector<string> re = generate(n);
	for (auto s : re)
		cout << s << endl;
	return 0;
}

vector<string> generate(int n)
{
	vector<string> re;
	string path = "";
	dfs(re, path, n, n);
	return re;
}

void dfs(vector<string> &re, string& path, int left, int right)
{
	if (left == 0 && right == 0)
	{
		re.push_back(path);
		return;
	}

	if (left == right)
	{
		path += "(";
		dfs(re, path, left - 1, right);
		path.pop_back();
		return;
	}

	if (left == 0)
	{
		path += ")";
		dfs(re, path, left, right - 1);
		path.pop_back();
		return;
	}

	if (left > 0 && left < right)
	{
		path += "(";
		dfs(re, path, left - 1, right);
		path.pop_back();
		path += ")";
		dfs(re, path, left, right - 1);
		path.pop_back();
	}
}