/**
	wanyunpeng  11.18
	questions : You have two numbers represented by a linked list, where each node contains a
				single digit. Thedigits are stored in reverse order, such that the 1 'sdigit is at the head
				of the list. Write a function that adds the two numbers and returns the sum as a
				linked list.
				FOLLOW UP
				Suppose the digits are stored in forward order. Repeat the above problem.
	备注：
**/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct LinkList
{
	int val;
	LinkList *next;
	LinkList(int x) :val(x), next(nullptr){}
};

LinkList *sum(LinkList *p, LinkList *q);

LinkList *forwardSum(LinkList *p, LinkList *q);

// 若值很大，还要考虑是否溢出的问题。溢出后转为用string存储
int main()
{
	LinkList p(6); p.next = new LinkList(1); p.next->next = new LinkList(7);
	LinkList q(2); q.next = new LinkList(9); q.next->next = new LinkList(5);
	LinkList *re = forwardSum(&p, &q);
	stringstream ss;
	string num;
	while (re)
	{
		ss << re->val;
		re = re->next;
	}
	ss >> num;
	reverse(num.begin(), num.end());
	cout << num << endl;
	return 0;
}

LinkList *sum(LinkList *p, LinkList *q)
{
	if (p == nullptr) return q;
	if (q == nullptr) return p;

	LinkList dumpy(-1);
	LinkList *cur = &dumpy;
	int carry = 0, val = 0;
	for (; p != nullptr || q != nullptr; p = p->next != nullptr ? p->next : nullptr, q = q->next != nullptr ? q->next : nullptr)
	{
		const int a = p == nullptr ? 0 : p->val;
		const int b = q == nullptr ? 0 : q->val;
		val = (a + b + carry) % 10;
		carry = (a + b + carry) / 10;
		cur->next = new LinkList(val);
		cur = cur->next;
	}
	return dumpy.next;
}

// 将p、q改为逆序，在求和
LinkList *forwardSum(LinkList *p, LinkList *q)
{
	if (p == nullptr) return q;
	if (q == nullptr) return p;

	LinkList *nextp = p->next, *prevp = p;
	LinkList *nextq = q->next, *prevq = q;
	p->next = nullptr; q->next = nullptr;
	while (nextp)
	{
		p = nextp;
		nextp = nextp->next;
		p->next = prevp;
		prevp = p;
	}

	while (nextq)
	{
		q = nextq;
		nextq = nextq->next;
		q->next = prevq;
		prevq = q;
	}

	return sum(p, q);
}