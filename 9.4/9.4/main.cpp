/**
	wanyunpeng  12.7
	questions : Write a method to return all subsets of aset.
	备注：
**/

#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<vector<int>> getSubSets(vector<int> &sets, int index);
vector<int> convert(vector<int> &sets,int i);
vector<vector<int>> dfsSubsets(vector<int> &sets,int index);
int main()
{
	vector<int> sets = { 1, 2, 3 };
	vector<vector<int>> re = getSubSets(sets,0);
	for (const auto &row : re)
	{
		for (const auto &i : row)
			cout << i << " ";
		cout << endl;
	}
	re = dfsSubsets(sets, 0);
	cout << endl;
	for (auto row : re)
	{
		for (auto i : row)
			cout << i << " ";
		cout << endl;
	}
	return 0;
}

vector<vector<int>> getSubSets(vector<int> &sets,int index)
{
	int size = 1<<sets.size();
	vector<vector<int>> re;
	for (int i = 0; i < size; ++i)
	{
		re.push_back(convert(sets, i));
	}
	return re;
}

vector<int> convert(vector<int> &sets, int i)
{
	vector<int> re;
	int index = 0;
	for (int k = i; k > 0; k >>= 1)
	{
		if ((k&1) == 1)
		{
			re.push_back(sets[index]);
		}
		index++;
	}
	return re;
}

vector<vector<int>> dfsSubsets(vector<int> &sets,int index)
{
	vector <vector<int>> allsubsets;
	if (sets.size() == index)
	{
		allsubsets = vector<vector<int>>();
		allsubsets.push_back(vector<int>());
	}
	else
	{
		allsubsets = dfsSubsets(sets, index + 1);
		int item = sets[index];
		// 获取多出来的subsets
		vector<vector<int>> moresubsets = vector<vector<int>>();
		for (auto subset : allsubsets)
		{
			vector<int> newsubsets = vector<int>();
			for (int i = 0; i < subset.size(); ++i)
				newsubsets.push_back(subset[i]);
			//newsubsets.emplace_back(subset);
			newsubsets.push_back(item);
			moresubsets.push_back(newsubsets);
		}
		for (auto tmp : moresubsets)
			allsubsets.push_back(tmp);
		//allsubsets.emplace_back(moresubsets);
	}
	return allsubsets;
}
