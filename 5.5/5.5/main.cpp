/**
	wanyunpeng  12.1
	questions : Write a function to determine the number of bits required to convert integer A to
				integer B
	��ע��n & (n - 1)���Խ�n�����λ��1ȥ����������ͳ��1�ĸ���
**/

#include <iostream>

using namespace std;

int convert(int A, int B);
int bitSwap(int A, int B);

int main()
{
	int A = 31, B = 14;
	cout << convert(A, B) << endl;
	cout << bitSwap(A, B) << endl;
	return 0;
}

int convert(int A, int B)
{
	// ʹA���ڵ���B
	if (A < B)
		swap(A, B);
	int re = 0;
	while (B>0)
	{
		if ((A & 1) != (B & 1))
		{
			re++;
		}
		A >>= 1;
		B >>= 1;
	}

	while (A>0)
	{
		A >>= 1;
		re++;
	}
	return re;
}

int bitSwap(int A, int B)
{
	int re = 0;
	for (int c = A^B; c != 0;c = c &(c-1))
		re ++;
	return re;
}