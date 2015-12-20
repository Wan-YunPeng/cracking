/**
	wanyunpeng 12.9
	questions : Given a boolean expression consistingof thesymbols 0,1,&, /, and A, and a desired
				boolean result value result, implement a function to count the number of ways of
				parenthesizing theexpression such that it evaluates to resuL t.
	备注：
**/

#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

int f(string exp, bool result, int s, int e, map<string, int>&q);

int main()
{
	
	string s = "1^0|0|1";
	map<string, int> q;
	cout << f(s, false, 0, s.size() - 1, q) << endl;
	return 0;
}


// 表达式exp，预期表达式输出的值result(true/false),s第一个字符下标，e末尾字符下标,q缓存
int f(string exp, bool result, int s, int e, map<string, int> &q) // start,end
{
	stringstream ss;
	ss << result << s << e;
	string key;
	ss >> key;
	if (q.find(key) != q.end())
		return q[key];

	if (s == e)
	{
		if (exp[s] == '1' && result == true)
			return 1;
		else if (exp[s] == '0' && result == false)
			return 1;
		return 0;
	}

	if (s > e) return 0;

	int c = 0;
	if (result)
	{
		for (int i = s + 1; i <= e; i += 2)
		{
			char op = exp[i];
			if (op == '&')
				c += f(exp, true, s, i - 1, q) * f(exp, true, i + 1, e, q);
			else if (op == '|')
			{
				c += f(exp, true, s, i - 1, q) * f(exp, false, i + 1, e, q);
				c += f(exp, false, s, i - 1, q) * f(exp, true, i + 1, e, q);
				c += f(exp, true, s, i - 1, q) * f(exp, true, i + 1, e, q);
			}
			else if (op == '^')
			{
				c += f(exp, true, s, i - 1, q) * f(exp, false, i + 1, e, q);
				c += f(exp, false, s, i - 1, q) * f(exp, true, i + 1, e, q);
			}
			else
				cout << "err" << endl;
		}
	}
	else
	{
		for (int i = s + 1; i <= e; i += 2)
		{
			char op = exp[i];
			if (op == '&')
			{
				c += f(exp, true, s, i - 1, q) * f(exp, false, i + 1, e, q);
				c += f(exp, false, s, i - 1, q) * f(exp, true, i + 1, e, q);
				c += f(exp, false, s, i - 1, q) * f(exp, false, i + 1, e, q);
			}
			else if (op == '|')
			{
				c += f(exp, false, s, i - 1, q) * f(exp, false, i + 1, e, q);
			}
			else if (op == '^')
			{
				c += f(exp, false, s, i - 1, q) * f(exp, false, i + 1, e, q);
				c += f(exp, true, s, i - 1, q) * f(exp, true, i + 1, e, q);
			}
			else
				cout << "err" << endl;
		}
	}
	q[key] = c;
	return c;
}