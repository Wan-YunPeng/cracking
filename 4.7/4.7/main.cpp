/**
	wanyunpeng  11.26
	questions : Design an algorithm and write code to find the first common ancestor of two nodes
				in a binary tree. Avoidstoring additional nodes in a data structure.NOTE: This is not
				necessarily a binary search tree.
	��ע���ж�p��q�Ƿ���ĳ���ڵ�����/�Ҳ࣬���ڣ�˳����һ�����£�������һ��ʱ���ҵ�
**/

#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left, *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr){}
};

struct Result
{
	bool isAncestor;
	TreeNode *node;
	Result(bool a, TreeNode *re) :isAncestor(a), node(re){}
};

Result CommonAncestorHelper(TreeNode *root, TreeNode *p, TreeNode *q);
TreeNode* CommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q);

TreeNode *commonAncestor(TreeNode *root, TreeNode *p, TreeNode *q);
TreeNode *commonAncestorHelper(TreeNode *root, TreeNode *p, TreeNode *q);
bool covers(TreeNode *root, TreeNode *p);



int main()
{
	TreeNode root(3); root.left = new TreeNode(2); root.right = new TreeNode(1);
	root.left->left = new TreeNode(5); root.right->left = new TreeNode(10);
	root.right->right = new TreeNode(12);
	TreeNode *re = commonAncestor(&root, root.right->right, root.right->right);
	if (re)
		cout << re->val << endl;

	re = CommonAncestor(&root, root.right->right, root.right->right);
	if (re)
		cout << re->val << endl;
	return 0;
}

TreeNode *commonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
	if (root == nullptr) return nullptr;

	if (!covers(root, p) || !covers(root, q))
		return nullptr;

	return commonAncestorHelper(root, p, q);
}

TreeNode *commonAncestorHelper(TreeNode *root, TreeNode *p, TreeNode *q)
{
	if (root == nullptr) return nullptr;
	if (root == p || root == q) return root;
	// �ж�p\q�Ƿ���ͬһ��
	bool is_p_on_left = covers(root->left, p);
	bool is_q_on_left = covers(root->left, q);
	// ����ͬһ�࣬����root
	if (is_p_on_left != is_q_on_left) return root;

	TreeNode *child_side = is_p_on_left ? root->left : root->right;
	return commonAncestorHelper(child_side, p, q);
}

bool covers(TreeNode *root, TreeNode *p)
{
	if (root == nullptr)return false;
	if (root == p) return true;
	return covers(root->left, p) || covers(root->right, p);
}

Result CommonAncestorHelper(TreeNode *root, TreeNode *p, TreeNode *q)
{
	if (root == nullptr) return Result(false, nullptr);

	if (root == p && root == q)
		return Result(true, root);

	Result rx = CommonAncestorHelper(root->left, p, q);
	if (rx.isAncestor)
		return rx;

	Result ry = CommonAncestorHelper(root->right, p, q);
	if (ry.isAncestor)
			return ry;

	if (rx.node != nullptr && ry.node != nullptr)
	{
		return Result(true, root);
	}
	else if (root == p || root == q)
	{
		bool isAncestor = rx.node != nullptr || ry.node != nullptr ? true : false;
		return Result(isAncestor, root);
	}
	else
	{
		return Result(false, rx.node != nullptr ? rx.node : ry.node);
	}
}

TreeNode* CommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
	Result re = CommonAncestorHelper(root, p, q);
	if (re.isAncestor)
		return re.node;
	return nullptr;
}