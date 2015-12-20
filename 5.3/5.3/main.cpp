/**
	wanyunpeng  11.30
	questions : Given a positive integer, print the next smallest and the next largest number that
				have the same number of 7bits in their binary representation.
	备注：最小大值：rightmost non-trailing zero
		  最大小值：rightmost not-trailing one
**/

#include <iostream>
#include <bitset>
using namespace std;

int nextNumber(int num);
int prevNumber(int num);

int main()
{
	int i = 13948;
	cout << bitset<32>(i) << endl;
	cout << bitset<32>(nextNumber(i)) << endl;
	cout << bitset<32>(prevNumber(i)) << endl;
	return 0;
}

int nextNumber(int num)
{
	int c0 = 0, c1 = 0;
	int p;
	int re = num;
	while (((num & 1) == 0) && (num != 0))
	{
		c0++;
		num >>= 1;
	}

	while (((num & 1) == 1))
	{
		c1++;
		num >>= 1;
	}

	if (c0 + c1 == 31 || c0 + c1 == 0)
		return -1;

	p = c0 + c1;
	re &= ~((1 << p ) - 1); // 低位清零
	re |= 1 << p;
	re |= (1 << (c1 - 1)) - 1;
	return re;
}

int prevNumber(int num)
{
	int c0 = 0, c1 = 0;
	int p;
	int re = num;

	while ((num & 1) == 1)
	{
		c1++;
		num >>= 1;
	}

	while ((num&1) == 0 && num != 0)
	{
		c0++;
		num >>= 1;
	}

	if (c0 + c1 == 31 || c0 + c1 == 0)
		return -1;

	p = c0 + c1;
	re &= ~((1 << (p + 1)) - 1);
	re |= ((1 << (c1 + 1) - 1) << c0);
	return re;
}