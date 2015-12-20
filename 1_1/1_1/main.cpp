/**
	wanyunpeng  11.15
	questions: Implement an algorithm to determine if a string has all unique characters.What
			   if you cannot use additional data structures?
	��ע����ȷ���ַ����ķ�Χ��1.ASCII�ַ���256��   2.ֻ��26��Ӣ���ַ���26,���д�Сд��
		  �����ַ����ĶԱȣ�1.�Ƿ����ִ�Сд	2.�ַ����еĿո��Ƿ�������ڣ�"Dog   " �� "   Dog"�Ƿ���ȣ�
**/



#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// ʹ��sort����
bool isUnique(string s);

// ʹ�������¼ÿ���ַ��Ƿ����
bool isUnique2(string s);

// ʹ��256��λ����¼ÿ���ַ��Ƿ����
bool isUnique3(string s);

int main()
{
	string s = "stringS324ds";
	bool re = isUnique3(s);
	cout << s << " is Unique : " << re << endl;
	return 0;
}

// ʹ��sort���� ���ִ�Сд
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
	memset(c, 0, 256);// ��ʼ��ȫΪfalse

	for (int i = 0; i < s.size(); ++i)
	{
		int index = static_cast<int>(s[i]);
		if (c[index] == true)
			return false;
		c[index] == true;
	}
	return true;
}

// ʹ��256��λ����¼ÿ���ַ��Ƿ����
bool isUnique3(string s)
{
	if (s.empty() || 1 == s.length()) return true;
	if (s.length() > 256) return false;

	int f[8]; // 8��int��256λ
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