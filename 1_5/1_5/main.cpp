/**
	wanyunpeng  11.15
	questions:
	备注：1.大小写		2.空格
**/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string compression(string &s);

int main()
{
	string s = "aabcccccaaa";
	string re = compression(s);
	cout << re << endl;
	return 0;
}

string compression(string &s)
{
	if (s.empty()) return "";
	if (s.size() == 1) return s;
	string re; stringstream ss;
	int count = 1; string prev = s.substr(0, 1);
	for (int i = 1; i < s.length(); ++i)
	{
		if (s.substr(i,1) == prev && i != s.length() - 1)
		{
			count++;
		}
		else
		{
			string c;
			ss << count;
			ss >> c; 
			ss.clear();
			re.append(prev);
			re.append(c);
			prev = s.substr(i, 1);
			cout << prev << " "<< count << endl;
			count = 1;
		}
		if (re.length() > s.length())
			return s;
	}
	return re;
}