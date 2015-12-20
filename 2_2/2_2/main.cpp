/**
	wanyunpeng  11.18
	questions:Implement an algorithm to find the kth to last element of a singly linked list.
	��ע��kΪ0��1���������һ��Ԫ�أ�kΪ2�����ص����ڶ���Ԫ�ء�
	������õ��������������һ��Ԫ�ص�ʱ�򷵻�һ������0���ۼƵ�kʱ�����---->��������
	��������������
**/

#include <iostream>

using namespace std;

struct LinkList
{
	int val;
	LinkList *next;
	LinkList(int x) :val(x), next(nullptr){}
};
// �ݹ�
LinkList* rec(LinkList* head, int k, int &i);

// ����
LinkList* findK(LinkList *head, int k);

int main()
{
	LinkList head(1); head.next = new LinkList(2);
	head.next->next = new LinkList(3); head.next->next->next = new LinkList(4);
	int i = 0, k = 0;
	LinkList* re = rec(&head, k, i);
	LinkList* re2 = findK(&head, k);
	if (re)
		cout << re->val << endl;
	if (re2)
		cout << re2->val << endl;
	return 0;
}

// �ݹ� -- 
LinkList* rec(LinkList* head, int k, int &i)
{
	if (head == nullptr)
		return 0;
	if (k == 0) k = 1;
	LinkList* nd = rec(head->next, k, i);
	i = i + 1;
	if (i == k)
		return head;
	return nd;
}

// ����
LinkList* findK(LinkList *head, int k)
{
	if (head == nullptr) return nullptr;

	LinkList *p = head, *q = head;
	while (p && k > 1)
	{
		p = p->next;
		k--;
	}

	if (p == nullptr) return nullptr;

	while (p->next)
	{
		p = p->next;
		q = q->next;
	}
	return q;
}

