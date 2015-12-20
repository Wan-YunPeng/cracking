/**
	wanyunpeng  11.16
	questions:Assume you have a method isSubstring which checks if one word is asubstring
			  of another. Given two strings, si and s2, write code to check Ifs2 isa rotation of si
			  using only onecalltoisSubstring (e.g., "waterbottLe" is a rotation of "erbottLewat").
	��ע����s1���Ϊx��y�������֣�s1=xy������s1 is a rotation of s2����ô��s == yx��
		  ���磺s1 = xy = waterbottle ; x = wat; y = erbottle; s2 = yx == erbootlewat
		  ����x��y��β�֣�������yxΪxyxy�����ַ���������ֻ��Ҫ�ж�s2�Ƿ�Ϊs1s1���ַ�������
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