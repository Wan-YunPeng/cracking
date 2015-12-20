/**
	wanyunpeng  11.25
	questions : Implement a function to check if a binary tree is balanced. For the purposes of this
				question, a balanced tree is defined to be a tree such that the heights of the two
				subtrees of any node never differ by more than on
	备注：二叉树因为含有递归结构，所以一般二叉树的解法通常可用递归来做
**/

#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
struct TreeNode{
	T val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(T x) :val(x), left(nullptr), right(nullptr){}
};

template<class T>
bool isBalanced(TreeNode<T> *root);

template<class T>
int dfs(TreeNode<T> *root);

template<class T>
bool isBalance(TreeNode<T> *root);

template<class T>
int height(TreeNode<T> *root);

int main()
{
	TreeNode<int> root(1); root.left = new TreeNode<int>(2);
	root.right = new TreeNode<int>(3); root.left->left = new TreeNode<int>(4);
	//root.left->left->left = new TreeNode<int>(5);
	cout << isBalance(&root) << endl;
	return 0;
}

template<class T>
bool isBalanced(TreeNode<T> *root)
{
	if (root == nullptr) return true;
	if (root->left == nullptr && root->right == nullptr) return true;

	int left = dfs(root->left);
	int right = dfs(root->right);

	if (abs(left - right) > 1)
		return false;
	else
		return isBalanced(root->left) && isBalanced(root->right);
}

template<class T>
int dfs(TreeNode<T> *root)
{
	if (root == nullptr) return 0;
	return max(dfs(root->left), dfs(root->right)) + 1;
}

template<class T>
bool isBalance(TreeNode<T> *root)
{
	if (height(root) == -1)
		return false;
	return true;
}

template<class T>
int height(TreeNode<T> *root)
{
	if (root == nullptr) return 0;

	int left = height(root->left);
	if (left == -1)
		return -1;

	int right = height(root->right);
	if (right == -1)
		return -1;

	if (abs(left - right) > 1)
		return -1;
	else
		return max(left, right) + 1;
}