/**
	wanyunpeng  12.1
	questions : Write a program to swap odd and even bits in an integer with as few instructions as
				possible (e.g., bit 0 and bit! are swapped, bit 2 and bit 3 are swapped, and soon)
	±¸×¢£º
**/

#include <iostream>
#include <bitset>
using namespace std;

int bitSwap(int A);

int main()
{
	int A = 234;
	cout << bitset<32>(A) << endl;
	cout << bitset<32>(bitSwap(A)) << endl;
	return 0;
}

int bitSwap(int A)
{
	return (((A & 0xaaaaaaaa) >> 1) | (((A & 0x55555555) << 1)));
}