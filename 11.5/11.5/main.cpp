/**
	wanyunpeng  12.15
	questions : Given a sorted array of strings which is interspersed with empty strings, write a
				method to find the locationof a given string.
	±¸×¢£º
**/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int findElement(vector<string> &arr, string target, int first, int last);

int main()
{
	vector<string> arr = { "at", "", "", "", "ball", "", "", "car", "", "", "dad", "", "" };
	cout << findElement(arr, "ball", 0, arr.size() - 1) << endl;
	return 0;
}

int findElement(vector<string> &arr, string target, int first, int last)
{
	if (first == last)
	{
		if (arr[first] == target)
			return first;
		else
			return -1;
	}

	if (first > last) return -1;

	int mid = (first + last) / 2;
	if (arr[mid] == "")
	{
		int leftIndex = findElement(arr, target, first, mid - 1);
		int rightIndex = findElement(arr, target, mid + 1, last);
		if (leftIndex == -1 && rightIndex == -1)
			return -1;
		return leftIndex == -1 ? rightIndex : leftIndex;
	}
	else if (arr[mid] == target)
		return mid;
	else if (arr[mid] > target)
	{
		return  findElement(arr, target, first, mid - 1);
	}
	else
		return findElement(arr, target, mid + 1, last);
	return -1;
}