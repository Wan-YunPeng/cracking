/**
	wanyunpeng  11.26
	questions : Imp/emen t a function to check if a binary tree isa binary search tree
	备注：二叉查找树若有重复的元素，排序为 left <= root < right
**/

#include <iostream>

using namespace std;

struct BSTNode
{
	int val;
	BSTNode *left, *right;
	BSTNode(int x) :val(x), left(nullptr), right(nullptr){}
};

bool isBST(BSTNode *root);

// 利用递归求解：min/max方法
bool checkBST(BSTNode *root,int min,int max);

int main()
{
	BSTNode root(5); root.left = new BSTNode(3); root.right = new BSTNode(7);
	root.left->left = new BSTNode(2); root.left->right = new BSTNode(4);
	root.right->right = new BSTNode(8);
	cout << checkBST(&root,INT_MIN, INT_MAX) << endl;
	return 0;
}

// 中序遍历
bool isBST(BSTNode *root)
{
	if (root == nullptr) return true;
	BSTNode *cur = root, *prev;
	int prevVal = INT_MIN, curVal = INT_MIN;
	while (cur != nullptr)
	{
		if (cur->left == nullptr)
		{
			curVal = cur->val;
			cout << curVal << " ";
			if (curVal <= prevVal)
				return false;
			prevVal = curVal;

			prev = cur;
			cur = cur->right;
		}
		else
		{
			BSTNode *tmp = cur->left;
			while (tmp->right != nullptr && tmp->right != cur)
			{
				tmp = tmp->right;
			}

			if (tmp->right == nullptr)
			{
				tmp->right = cur;
				cur = cur->left;
			}
			else
			{
				curVal = cur->val;
				cout << curVal << " ";
				if (prevVal >= curVal)
					return false;
				prevVal = curVal;

				prev = cur;
				cur = cur->right;
			}
		}
	}
	cout << endl;
	return true;
}

// 利用递归求解：min/max方法
bool checkBST(BSTNode *root,int min, int max)
{
	if (root == nullptr)
		return true;

	if (root->val <= min || root->val >= max)
		return false;

	if (!checkBST(root->left, min, root->val) ||
		!checkBST(root->right, root->val, max))
		return false;

	return true;
}