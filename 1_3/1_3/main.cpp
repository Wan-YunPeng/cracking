/**
	wanyunpeng 11.15
	questions:Given two strings, write a method to decideif one isa permutation of theother
	��ע�� 1.��Сд�Ƿ�����		2.�ո��Ƿ�����
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
	// �ո��Ƿ��������
	if (s.length() != d.length()) return false;

	// �����ִ�Сд
	for (int i = 0; i < s.length(); ++i)
		s[i] = tolower(s[i]);
	for (int i = 0; i < d.length(); ++i)
		d[i] = tolower(d[i]);

	sort(s.begin(), s.end());
	sort(d.begin(), d.end());
	return s == d;
}

// ͳ��ÿ���ַ����ֵĸ��������бȽ�
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