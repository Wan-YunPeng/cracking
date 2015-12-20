/**
	wanyunpeng  12.16
	questions : A circus is designinga tower routine consisting of people standing atop one another's shoulders. For practical and aesthetic reasons, each person must be both shorter
				and lighter than the person below him or her. Given the heights and weights of
				each person in the circus, write a method to compute the largest possible number
				of people in such a tower.
	备注：pair的排序，先按第一个元素排序，再从中找出最长增长子序列
**/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <string>
using namespace std;


void getIncreasingSequence(vector<pair<int, int> > &htwt);
void longIncreasingSequence(vector<pair<int, int> > &htwt);

int main()
{
	string s = "abc";
	auto itr = s.end();
	if (*itr == '\0')
		cout << "aaaaaaaa" << endl;
	vector<pair<int, int> > htwt = { { 65, 100 }, { 70, 35 }, { 56, 90 }, { 75, 100 }, { 60, 95 }, { 68, 110 } };
	getIncreasingSequence(htwt);
	for (auto p : htwt)
	{
		cout << p.first << " " << p.second << endl;
	}
	return 0;
}
void getIncreasingSequence(vector<pair<int, int> > &htwt)
{
	sort(htwt.begin(), htwt.end());	
	longIncreasingSequence(htwt);
	return;
}
void longIncreasingSequence(vector<pair<int, int> > &htwt)
{
	vector<pair<int, int> > re;
	
	for (int i = 0; i < htwt.size(); ++i)
	{
		vector<pair<int, int> >::iterator itr = re.end();
		for (auto it = re.begin(); it != re.end(); ++it)
		{
			if (it->second >= htwt[i].second && it->first >= htwt[i].first)
			{
				itr = it;
				break;
			}

		}
		if (re.empty()) re.push_back({ htwt[i].first, htwt[i].second });
		else if (itr == re.end() && htwt[i].second > prev(re.end())->second) re.push_back({ htwt[i].first, htwt[i].second });
		else if (itr != re.end())
		{
			itr->first = htwt[i].first;
			itr->second = htwt[i].second;
		}
	}
	swap(re, htwt);
}