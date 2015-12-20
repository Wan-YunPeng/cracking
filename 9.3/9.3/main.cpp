/**
	wanyunpeng 12.7
	questions : Amagic index in anarray A[l.. .n-l] isdefined to be an index such that A[i] =
				i. Given a sorted array of distinct integers, write a method to find a magic index, if
				one exists, in array A.
				FOLLOW UP
				What if the values are not distinct?
	±¸×¢£º
**/

#include <iostream>
#include <algorithm>
using namespace std;

int magicNumber(int A[], int n);
int magic(int A[], int start, int end,int n);
int main()
{
	int A[] = { -2, -1, 1, 3, 5 };
	cout << magicNumber(A, sizeof(A) / sizeof(A[0])) << endl;
	int B[] = { -10, -5, 2, 2, 2, 3, 4, 7, 9, 12, 13 };
	cout << magic(B, 0, sizeof(B) / sizeof(B[0]) - 1, sizeof(B) / sizeof(B[0])) << endl;
	return 0;
}

int magicNumber(int A[], int n)
{
	int start = 0, end = n;
	while (start != end)
	{
		int mid = (start + end) / 2;
		if (mid == A[mid])
			return mid;
		else if (mid > A[mid])
			start = mid + 1;
		else
			end = mid;
	}
	return -1;
}

int magic(int A[], int start, int end,int n)
{
	if (start < 0 || end < start || end >= n) return -1;

	int mid = (start + end) / 2;

	if (mid == A[mid]) return mid;

	int leftIndex = min(A[mid], mid - 1);
	int left = magic(A, start, leftIndex,n);
	if (left >= 0)
		return left;

	int rightIndex = max(A[mid], mid + 1);
	int right = magic(A, rightIndex, end,n);
	return right;
}