/**
	wanyunpeng  11.27
	questions : Youare given a binary tree in which each node contains a value. Design an algorithm to print all paths which sum to a given value. Thepath does not need to start
				or end at the root or a leaf.
	备注：
**/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left, *right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

void findSum(TreeNode *root, int sum);
void findSum(TreeNode *root, int sum, vector<int> &path, int level);
int depth(TreeNode *root);
void print(vector<int> &path,int start, int end);

int main()
{
	cout << setbase(8) << 17 << endl;
	TreeNode root(5); root.left = new TreeNode(3); root.left->left = new TreeNode(1);
	root.left->right = new TreeNode(4); root.right = new TreeNode(8);
	root.right->right = new TreeNode(9);
	int target = 9;
	findSum(&root, target);
	return 0;
}

int depth(TreeNode *root)
{
	if (root == nullptr)
		return 0;
	return 1 + max(depth(root->left), depth(root->right));
}

void findSum(TreeNode *root, int sum)
{
	int dep = depth(root);
	vector<int> path(dep);
	findSum(root, sum, path, 0);
}

void findSum(TreeNode *root, int sum, vector<int> &path, int level)
{
	if (root == nullptr)
		return;

	// 放入
	path[level] = root->val;

	// 寻找以当前节点为终点的路径,向上寻找
	int t = 0;
	for (int i = level; i >= 0; --i)
	{
		t += path[i];
		if (t == sum)
			print(path, i, level);
	}

	findSum(root->left, sum, path, level + 1);
	findSum(root->right, sum, path, level + 1);

	// 取出
	path[level] = INT_MIN;
}

void print(vector<int> &path, int start, int end)
{
	for (int i = start; i <= end; ++i)
		cout << path[i] << " ";
	cout << endl;
}