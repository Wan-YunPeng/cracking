/**
	wanyunpeng  11.25
	questions : Given a binary tree, design an algorithm whichcreates a linked list of all the nodes at
				each depth (e.g., if you have a tree with depth D,you'll have D linked lists)
	±¸×¢£º 
**/

#include <iostream>
#include <queue>

using namespace std;

struct LinkTreeNode
{
	int val;
	LinkTreeNode *left,
		*right,
		*next;
	LinkTreeNode(int x) :val(x), left(nullptr), right(nullptr), next(nullptr){}
};

void generator(LinkTreeNode *root);

int main()
{
	LinkTreeNode root(1);
	root.left = new LinkTreeNode(2); root.right = new LinkTreeNode(3);
	root.left->left = new LinkTreeNode(4); root.left->right = new LinkTreeNode(5);
	generator(&root);
	LinkTreeNode *p = &root;
	while (p)
	{
		LinkTreeNode *q = p;
		while (q)
		{
			cout << q->val << " ";
			q = q->next;
		}
		cout << endl;
		p = p->left;
	}
	return 0;
}

void generator(LinkTreeNode *root)
{
	if (root == nullptr) return;

	queue<LinkTreeNode *> cur,next;
	cur.push(root);

	while (!cur.empty())
	{
		LinkTreeNode *prevNode = cur.front();
		cur.pop();
		if (prevNode->left) next.push(prevNode->left);
		if (prevNode->right) next.push(prevNode->right);

		while (!cur.empty())
		{
			LinkTreeNode *curNode = cur.front();
			cur.pop();
			if (curNode->left) next.push(curNode->left);
			if (curNode->right) next.push(curNode->right);

			prevNode->next = curNode;
			curNode = curNode;
		}
		swap(cur, next);
	}
}