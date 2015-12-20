/**
	wanyunpeng  11.18
	questions : Implementa function to check if a linked list is apalindrome,
	��ע��֪������ʱ����ջ�洢ǰ�벿��Ԫ��ֵ��ֱ�����벿�ֵ�ֵ�Ƚ�
		  ��֪������ʱ����slow��fast�ҵ��м�Ԫ��
**/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

template<class T>
struct LinkList
{
	T val;
	LinkList *next;
	LinkList(T x) :val(x), next(nullptr){}
};

template<class T>
bool isPanlindorme(LinkList<T> *head);

int main()
{
	LinkList<int> p(1); p.next = new LinkList<int>(2);
	p.next->next = new LinkList<int>(2); p.next->next->next = new LinkList<int>(2);
	p.next->next->next->next = new LinkList<int>(1);
	bool re = isPanlindorme(&p);

	LinkList<string> q("a");  q.next = new LinkList<string>("b");
	q.next->next = new LinkList<string>("a");
	cout << isPanlindorme(&q) << endl;
	cout << re << endl;
	return 0;
}

template<class T>
bool isPanlindorme(LinkList<T> *head)
{
	LinkList<T> *slow = head, *fast = head;
	stack<T> stk;

	while (fast && fast->next)
	{
		stk.push(slow->val);
		slow = slow->next;
		fast = fast->next->next;
	}

	if (fast != nullptr)// odd
	{
		slow = slow->next;
	}

	while (slow)
	{
		T top = stk.top(); 
		stk.pop();
		if (top != slow->val)
			return false;
		slow = slow->next;
	}

	return true;
}