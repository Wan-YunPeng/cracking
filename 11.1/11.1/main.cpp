/**
	wanyunpeng  11.1
	questions : Youare given two sorted arrays, A and B, where A has a large enoughbuffer at the
				end to hold B.Write a method to merge Binto A in sorted order
	±¸×¢£º
**/

#include <iostream>

using namespace std;

void merge(int A[], int m, int B[], int n);

int main()
{
	int A[10] = { 2, 1, 9, 8, 6, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX };
	int B[5] = { 3, 6, 5, 7, 10 };
	merge(A, 5, B, 5);
	for (int i = 0; i < 10; ++i)
		cout << A[i] << " ";
	cout << endl;
	return 0;
}

void merge(int A[], int m, int B[], int n)
{
	int indexA = m - 1, indexB = n - 1;
	int mergeIndex = m + n - 1;
	while (indexA >= 0 && indexB >= 0)
	{
		if (A[indexA] > B[indexB])
		{
			A[mergeIndex] = A[indexA];
			mergeIndex--;
			indexA--;
		}
		else
		{
			A[mergeIndex] = B[indexB];
			mergeIndex--;
			indexB--;
		}
	}
	
	while (indexB >= 0)
	{
		A[mergeIndex] = B[indexB];
		mergeIndex--;
		indexB--;
	}
}