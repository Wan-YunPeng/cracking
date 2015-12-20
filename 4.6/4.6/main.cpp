/**
	wanyunpeng  11.26
	questions : Write an algorithm to find the 'next'node (i.e., in-order successor) of a given nodein
				a binary search tree. Youmay assume that each nodehas a link to its parent.
	��ע��1.�ýڵ��Һ��ӵ�����ڵ�Ϊnext
		  2.�ýڵ�û���Һ��ӣ�����Ϊ���ڵ������ʱ�����ڵ㼴Ϊnext
		  3.û���Һ��ӣ�Ϊ���ڵ���Һ��ӣ�һֱ����ѧ�ң�ֱ��Ϊnull��Ϊ���ڵ������
**/

#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left, *right, *parent;
	TreeNode(int x, TreeNode *p) :val(x),left(nullptr), right(nullptr), parent(p){}
};

TreeNode *nextNode(TreeNode *node);
void inOrder(TreeNode *root);

int main()
{
	TreeNode root(4,nullptr); 
	root.left = new TreeNode(2,&root); 
	root.left->right = new TreeNode(3,root.left); 
	root.right = new TreeNode(6,&root); 
	root.right->left = new TreeNode(5, root.right);
	root.right->right = new TreeNode(7,root.right); 
	TreeNode *re = nextNode(root.right->left);
	inOrder(&root);
	cout << endl;
	if (re != nullptr)
		cout << re->val<<" "<<re->left<<" "<<re->right << endl;
	return 0;
}

TreeNode *nextNode(TreeNode *node)
{
	if (node == nullptr) return nullptr;

	if (node->right != nullptr)
	{
		TreeNode *re = node->right;
		while (re->left != nullptr)
		{
			re = re->left;
		}
		return re;
	}

	TreeNode *p = node, *x = p->parent;
	while (x != nullptr && x->left != p)
	{
		p = x;
		x = x->parent;
	}
	return x;
}

void inOrder(TreeNode *root)
{
	if (root == nullptr)
		return;

	inOrder(root->left);
	cout << root->val << " ";
	inOrder(root->right);
}
