/**
	wanyunpeng  11.16
	questions:Assume you have a method isSubstring which checks if one word is asubstring
			  of another. Given two strings, si and s2, write code to check Ifs2 isa rotation of si
			  using only onecalltoisSubstring (e.g., "waterbottLe" is a rotation of "erbottLewat").
	备注：将s1拆分为x和y两个部分（s1=xy），若s1 is a rotation of s2。那么有s == yx。
		  例如：s1 = xy = waterbottle ; x = wat; y = erbottle; s2 = yx == erbootlewat
		  不管x和y如何拆分，都会有yx为xyxy的子字符串，所有只需要判断s2是否为s1s1的字符串即可
**/

#include <iostream>
#include <string>

using namespace std;

bool isRotation(string s1, string s2);
bool isSubString(string sub, string s);
int main()
{
	string s1 = "waterbottle";
	string s2 = "erbottlewat";
	cout << isRotation(s1, s2) << endl;
	return 0;
}

bool isRotation(string s1, string s2)
{
	const int len = s1.size();
	if (s2.size() == len && len > 0)
		return isSubString(s2, s1 + s1);
	return false;
}

bool isSubString(string sub, string s)
{
	return sub.size() * 2 == s.size();
}