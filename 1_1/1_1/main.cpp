/**
	wanyunpeng  11.15
	questions: Implement an algorithm to determine if a string has all unique characters.What
			   if you cannot use additional data structures?
	备注：明确该字符串的范围：1.ASCII字符（256）   2.只有26个英文字符（26,还有大小写）
		  对于字符串的对比：1.是否区分大小写	2.字符串中的空格是否计算在内（"Dog   " 和 "   Dog"是否相等）
**/



#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 使用sort函数
bool isUnique(string s);

// 使用数组记录每个字符是否出现
bool isUnique2(string s);

// 使用256个位来记录每个字符是否出现
bool isUnique3(string s);

int main()
{
	string s = "stringS324ds";
	bool re = isUnique3(s);
	cout << s << " is Unique : " << re << endl;
	return 0;
}

// 使用sort函数 区分大小写
bool isUnique(string s)
{
	if (s.empty() || s.size() == 1) return true;
	if (s.size() > 256) return false;
	sort(s.begin(), s.end());
	for (string::const_iterator itr = s.begin() + 1; itr != s.end(); ++itr)
	{
		if (*itr == *(itr - 1))	
			return false;
	}
	return true;
}

bool isUnique2(string s)
{
	if (s.empty() || 1 == s.length()) return true;
	if (s.length() > 256) return false;
	bool c[256];
	memset(c, 0, 256);// 初始化全为false

	for (int i = 0; i < s.size(); ++i)
	{
		int index = static_cast<int>(s[i]);
		if (c[index] == true)
			return false;
		c[index] == true;
	}
	return true;
}

// 使用256个位来记录每个字符是否出现
bool isUnique3(string s)
{
	if (s.empty() || 1 == s.length()) return true;
	if (s.length() > 256) return false;

	int f[8]; // 8个int，256位
	memset(f, 0, sizeof(f));
	for (int i = 0; i < s.length(); ++i)
	{
		const int index = static_cast<int>(s[i]);
		int a = index / 32, b = index % 32;
		if (f[a] & (1 << b)) return false;
		f[a] |= (1 << b);
	}
	return true;
}