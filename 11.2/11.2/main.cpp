/**
	wanyunpeng  11.2
	questions : Write a method to sort an array of strings so that all the anagrams are next to each
				other.
	±¸×¢£º
**/

#include <iostream>
#include <unordered_map>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

void sort(vector<string> arr);

int main()
{
	return 0;
}

void sort(vector<string> arr)
{
	unordered_map<string, list<string>> hash;
	for (auto s : arr)
	{
		sort(s.begin(), s.end());
		if (hash.find(s) == hash.end())
			hash[s] = list<string>();
		list<string> anagrams = hash[s];
		anagrams.push_back(s);
	}
}