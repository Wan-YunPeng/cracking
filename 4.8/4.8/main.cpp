/**
	wanyunpeng  11.27
	questions : You have two very large binary trees: Tl, with millions of nodes, and T2, with
				hundreds of nodes. Create an algorithm to decideifT2 isa subtree ofTl.
				A tree T2 is a subtree of Tl if there exists a node n in Tl such that the subtree ofn
				is identical to T2. That is, if you cut off the tree at node n, the two trees would be
				identical.
	±¸×¢£º
**/
#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left, *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr){}
};

bool containTree(TreeNode *r1, TreeNode *r2);
bool isSubTree(TreeNode *r1, TreeNode *r2);
bool matchTree(TreeNode *r1, TreeNode *r2);

int main()
{
	TreeNode r1(5); r1.left = new TreeNode(3); r1.left->left = new TreeNode(2);
	r1.left->right = new TreeNode(4);
	TreeNode r2(3); r2.left = new TreeNode(2); r2.right = new TreeNode(4);
	cout << containTree(&r1, &r2) << endl;
	return 0;
}

bool containTree(TreeNode *r1, TreeNode *r2)
{
	if (r2 == nullptr) return true;
	return isSubTree(r1, r2);
}

bool isSubTree(TreeNode *r1, TreeNode *r2)
{
	if (r1 == nullptr)
		return false;

	if (r1->val == r2->val)
	{
		if (matchTree(r1, r2))
			return true;
	}

	return isSubTree(r1->left, r2) || isSubTree(r1->right, r2);
}
bool matchTree(TreeNode *r1, TreeNode *r2)
{
	if (r1 == nullptr && r2 == nullptr)
		return true;

	if (r1 == nullptr || r2 == nullptr)
		return false;

	if (r1->val != r2->val)
		return false;
	return matchTree(r1->left, r2->left) && matchTree(r1->right, r2->right);
}