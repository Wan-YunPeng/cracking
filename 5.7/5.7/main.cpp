/**
	wanyunpeng  12.1
	questions : An array A containsall the integers from 0 through n, except for one numberwhich is
				missing. In this problem,we cannot access an entire integer in A with a single operation. Theelements of A are represented in binary, and the only operation we can use
				to access them is "fetch thejth bit ofAfi]," which takes constant time. Write code to
				find the missing integer. Canyou do it in 0(n) time?
	备注：
**/

#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

int findMissing(vector<bitset<32> > &array);
int findMissing(vector<bitset<32> > &array, int column);

int main()
{
	vector<bitset<32> > array = { 0, 3, 2, 1, 5, 4, 9, 6, 7 };
	cout << findMissing(array) << endl;
	return 0;
}

int findMissing(vector<bitset<32> > &array)
{
	return findMissing(array, 0);
}

int findMissing(vector<bitset<32> > &array, int column)
{
	if (column >= 31)
		return 0;

	vector<bitset<32> > oneBits;
	vector<bitset<32> > zeroBits;

	for (auto t : array)
	{
		if (t.test(column))
			oneBits.push_back(t);
		else
			zeroBits.push_back(t);
	}

	// counts(0) =< counts(1)，missing 0
	if (zeroBits.size() <= oneBits.size())
	{
		int v = findMissing(zeroBits, column + 1);
		return (v << 1) | 0; // v是不包含最后一位的值，这里返回要在末尾加上一个0
	}
	else
	{
		int v = findMissing(oneBits, column + 1);
		return (v << 1) | 1;
	}
}