/**
	wanyunpeng  11.18
	question :  Implementan algorithm to delete a node in the middle of a singly linked list, given
				only access to that node.
	��ע������Ҫɾ���Ľڵ㣬��Ϊ�ǵ������޷��ҵ�����ڵ��ǰ�ýڵ㣬���԰Ѻ���һ���ڵ��ֵ��ֵ����ǰ�ڵ㣬ɾ����һ���ڵ�
		  ˼άģʽ�ĸı�
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
		cout << "�޷�ɾ��" << endl;
	return 0;
}

bool deleteNode(LinkList *nd)
{
	if (nd == nullptr || nd->next == nullptr) return false; // �޷�ɾ��

	LinkList *tmp = nd->next;
	nd->val = tmp->val;
	nd->next = tmp->next;
	delete tmp;
	return true;
}