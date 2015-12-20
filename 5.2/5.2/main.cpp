/**
	wanyunpeng  11.29
	questions : Given a real number between 0 and 7(e.g., 0.72)that is passed in as a double, print
				the binary representation. If the number cannot be represented accurately in binary
				with at most 32 characters, print "ERROR."
	±¸×¢£º
**/

#include <iostream>
#include <string>

using namespace std;

string transformer(double num);

int main()
{
	double d = 0.75;
	cout << transformer(d) << endl;
	return 0;
}

string transformer(double num)
{
	if (num <= 0 || num >= 1)
		return "ERROR";
	string re;
	re.append(".");
	while (num > 0)
	{
		if (re.length() > 32)
			return "ERROR";
		double tmp = num * 2;

		if (tmp >= 1)
		{
			re.append("1");
			num = tmp - 1;
		}
		else
		{
			re.append("0");
			num = tmp;
		}
			
	}
	return re;
}