/**
	wanyunpeng  11.29
	questions : Youaregiven two 32-bit numbers, N andM, andtwobitpositions, i andj. Write a
				method to insert M into Nsuch that M starts at bit j and ends at bit i. Youcan assume
				that the bits j through i have enough space to fit all ofM. That is,ifM= 10011,
				you can assumethat there are at least 5 bits between j and i. Youwould not, for
				example, havej-3 and i=2, because Mcould not fully fit between bit 3 and bit2.
				EXAMPLE:
				Input: N = 16000000000, M = 10011, i = 2, j = 6
				Output: N = 10001001100
	备注：1.要插入的位清零
		  2.利用位移进行更新
		  *对某个数进行移位操作时(left/right shifting)不会改变这个数，若要记录该结果，另外用一个变量或直接使用原变量
		  *对某个数的位操作也是如此（与、或、非、异或）都不会改变原变量的值
**/

#include <iostream>
#include <string>
#include <bitset>
using namespace std;

void insert(int& M, int& N, int i, int j);
void clearBit(int &N, int k);
int counts(int M);

int main()
{
	int N = 0x00000620, M = 0x00000013;
	int i = 2, j = 6;
	N | 1;
	
	insert(M, N, i, j);
	cout <<bitset<32>(N) << endl;
	return 0;
}


void insert(int& M, int& N, int i, int j)
{
	int nums = counts(M);
	if (nums > j - i + 1)
		return ;

	for (int k = nums + i - 1; k >= i; --k)
		clearBit(N, k);
	int mask = M << i;
	N |= mask;
}

void clearBit(int &N, int k)
{
	N &= (~(1 << k));
}

int counts(int M)
{
	int re = 0;
	while (M > 0)
	{
		M >>= 1;
		re++;
	}
	return re;
}
