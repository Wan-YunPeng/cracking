/**
	wanyunpeng  11.25
	questions : Given a directed graph, design an algorithm to find out whether there is a route
				between two nodes.
	备注：深度优先代码形式上很简单，只需递归即可，但是深度优先带来的一个坏处是可能沿某一路径一直深入，很久才能访问下一个兄弟节点
		  广度优先可以找到最短路径。
**/

#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr){}
};

TreeNode *createMinimalBST(int A[], int start, int end);
void inOrder(TreeNode *root);

int main()
{
	int A[] = { 1, 2, 3, 4, 5, 6 };
	TreeNode *root = createMinimalBST(A, 0, sizeof(A) / sizeof(A[0]) - 1);
	inOrder(root);
	return 0;
}


TreeNode *createMinimalBST(int A[], int start, int end)
{
	if (start > end)
		return nullptr;

	int mid = (start + end) / 2;
	TreeNode *node = new TreeNode(A[mid]);
	node->left = createMinimalBST(A, start, mid - 1);
	node->right = createMinimalBST(A, mid + 1, end);
	return node;
}

void inOrder(TreeNode *root)
{
	if (root == nullptr) return;

	inOrder(root->left);
	cout << root->val << endl;
	inOrder(root->right);
}