/**
	wanyunpeng 11.15
	questions:Given two strings, write a method to decideif one isa permutation of theother
	备注： 1.大小写是否区别		2.空格是否区别
**/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool permutation(string s, string d);
bool permutation2(string s, string d);
int main()
{
	string s = "dog", d = "gOd";
	cout << permutation2(s, d) << endl;
	return 0;
}

// stl--sort
bool permutation(string s, string d)
{
	// 空格是否计算在内
	if (s.length() != d.length()) return false;

	// 不区分大小写
	for (int i = 0; i < s.length(); ++i)
		s[i] = tolower(s[i]);
	for (int i = 0; i < d.length(); ++i)
		d[i] = tolower(d[i]);

	sort(s.begin(), s.end());
	sort(d.begin(), d.end());
	return s == d;
}

// 统计每个字符出现的个数，进行比较
bool permutation2(string s, string d)
{
	if (s.length() != d.length()) return false;

	int sc[256] = { 0 };

	for (int i = 0; i < s.length(); ++i)
		sc[static_cast<int>(s[i])] += 1;

	for (int i = 0; i < d.length(); ++i)
	{
		int index = static_cast<int>(d[i]);
		if (--sc[index] < 0) return false;
	}
	return true;
}