/**
	wanyunpeng  11.18
	questions : Write code to partition a linked list around a value x, such that all nodes less than x
				come before alt nodes greater than or equal to
	备注：注意判断NULL的情况：有时判断p是否为NULL；有时判断p->next是否为NULL
**/

#include <iostream>

using namespace std;

struct LinkList
{
	int val;
	LinkList *next;
	LinkList(int x) :val(x), next(nullptr){}
};

LinkList* partition(LinkList* head, int x);

int main()
{
	LinkList head(5); head.next = new LinkList(3);
	head.next->next = new LinkList(4); head.next->next->next = new LinkList(8);
	head.next->next->next->next = new LinkList(1);
	int x = 3;
	LinkList* re = partition(&head, x);
	while (re)
	{
		cout << re->val << " ";
		re = re->next;
	}
	cout << endl;
	return 0;
}

LinkList* partition(LinkList *head, int x)
{
	if (head == nullptr) return nullptr;

	LinkList less(-1), greater(-1);
	LinkList *p = &less;
	while (head)
	{
		LinkList *next;
		next = head->next;
		if (head->val < x)
		{
			p->next = head;
			head->next = nullptr;
			p = p->next;
		}
		else
		{
			head->next = greater.next;
			greater.next = head;			
		}
		head = next;
	}

	p->next = greater.next;
	return less.next;
}