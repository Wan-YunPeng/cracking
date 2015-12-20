/**
	wanyunpeng  11.15
	questions;Write a method to replace all spaces in a string with '%20'. Youmay assume that the
			  string has sufficient space at the end of the string to hold the additional characters,
			  and that you are given the "true" length of the string. (Note: if implementing inJava,
			  please usea character array so that you can perform this operation inplace.)
	备注：
**/

#include <iostream>
#include <string>

using namespace std;

string replace(string s, int length);
void erase(string &s);

int main()
{
	string s = "   Mr John Smith   ";
	string re = replace(s, s.length());
	cout << re << endl;
	return 0;
}

string replace(string s, int length)
{
	// 去掉首尾空格
	erase(s);
	length = s.length();
	int spaceCount = 0, newLength = 0;
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == ' ') spaceCount++;
	}
	newLength = length + spaceCount * 2;
	
	string str(newLength, '\0');

	for (int i = length - 1; i >= 0; i--)
	{
		if (s[i] == ' ')
		{
			str[newLength - 1] = '0';
			str[newLength - 2] = '2';
			str[newLength - 3] = '%';
			newLength -= 3;
		}
		else
		{
			str[newLength - 1] = s[i];
			newLength -= 1;
		}
	}
	return str;
}

void erase(string &s)
{
	s.erase(0, s.find_first_not_of(' '));
	s.erase(s.find_last_not_of(' ') + 1);
}