/**
	wanyunpeng  11.18
	questions : Given a circular linked list, implement an algorithm which returns the node at the
				beginning of the loop.
	±¸×¢£º
**/

#include <iostream>

using namespace std;

struct LinkList
{
	int val;
	LinkList *next;
	LinkList(int x) :val(x), next(nullptr){}
};

LinkList* loopNode(LinkList *head);

int main()
{
	LinkList head(1); head.next = new LinkList(2);
	head.next->next = new LinkList(3); head.next->next->next = new LinkList(4);
	head.next->next->next->next = new LinkList(5);
	head.next->next->next->next->next = head.next;
	LinkList *re = loopNode(&head);
	cout << re->val << endl;
	return 0;
}

LinkList* loopNode(LinkList *head)
{
	if (head == nullptr) return nullptr;
	LinkList *slow = head, *fast = head;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) // ÏàÓö
			break;
	}

	if (fast == nullptr || fast->next == nullptr)
		return nullptr;

	slow = head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return fast;
}