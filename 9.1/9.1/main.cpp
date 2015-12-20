/**
	wanyunpeng  12.7
	questions : A child is running up a staircase with n steps, and can hop either 1step, 2 steps, or
				3 steps at a time. Implement a method to count how many possible ways the child
				can run up the stairs.
	备注：类似于斐波那契数列
**/

#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> &cache);

int main()
{
	int n = 12;
	vector<int> cache(n + 1, 0);
	cout << solution(n,cache) << endl;
	return 0;
}

int solution(int n, vector<int> &cache)
{
	if (n <= 0) return 0;
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n == 3) return 4;
	if (cache[n] > 0) return cache[n];
	cache[n] = solution(n - 1, cache) + solution(n - 2, cache) + solution(n - 3, cache);
	return cache[n];
}