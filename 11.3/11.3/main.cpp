/**
	wanyunpeng  11.3
	questions : Given a sorted array of n integers that has been rotated an unknown number of
				times, write code to find an element in the array. Youmay assume that the array was
				originally sorted in increasing order.
	备注：每次去除一小部分
**/

#include <iostream>
#include <vector>
using namespace std;

int findm(vector<int> &nums,int target);

int main()
{
	vector<int> nums = { 15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14 };
	cout << findm(nums, 5) << endl;
	return 0;
}

int findm(vector<int> &nums,int target)
{
	int first = 0, last = nums.size();
	
	while (first <= last)
	{
		int mid = (first + last) / 2;
		if (nums[mid] == target)
			return mid;
		if (nums[first] <= nums[mid])
		{
			if (nums[first] <= target && target < nums[mid])
				last = mid;
			else
				first = mid + 1;
		}
		else
		{
			if (target > nums[mid] && target <= nums[last - 1])
			{
				first = mid + 1;
			}
			else
				last = mid;
		}
	}
	return -1;
}