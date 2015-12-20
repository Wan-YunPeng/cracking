/**
	wanyunpeng  11.18
	question :  Implementan algorithm to delete a node in the middle of a singly linked list, given
				only access to that node.
	备注：给你要删除的节点，因为是单链表，无法找到这个节点的前置节点，可以把后面一个节点的值赋值到当前节点，删除下一个节点
		  思维模式的改变
**/

#include <iostream>

using namespace std;

struct LinkList
{
	int val;
	LinkList *next;
	LinkList(int x) :val(x), next(nullptr){}
};

bool deleteNode(LinkList *nd);

int main()
{
	LinkList head(1); head.next = new LinkList(2);
	head.next->next = new LinkList(3); 
	LinkList *p = &head;
	bool re = deleteNode(p);
	if (re)
	{
		p = &head;
		while (p)
		{
			cout << p->val << " ";
			p = p->next;
		}
		cout << endl;
	}
	else
		cout << "无法删除" << endl;
	return 0;
}

bool deleteNode(LinkList *nd)
{
	if (nd == nullptr || nd->next == nullptr) return false; // 无法删除

	LinkList *tmp = nd->next;
	nd->val = tmp->val;
	nd->next = tmp->next;
	delete tmp;
	return true;
}