/**
	wanyunpeng  12.8
	questions : Write a method to compute all permutations of a string
	±¸×¢£º
**/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void permutations(string s, int index);

int main()
{
	string s = "abcd";
	permutations(s,0);
	return 0;
}

void permutations(string s, int index)
{
	if (index == s.size())
	{
		cout << s << endl;
		return;
	}

	for (int i = index; i < s.size(); ++i)
	{
		swap(s[index], s[i]);
		permutations(s, index + 1);
		//swap(s[index], s[i]);
	}
}