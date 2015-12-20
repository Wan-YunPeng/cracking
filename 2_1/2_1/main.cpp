/**
	wanyunpeng  11.18
	questions : Write code to remove duplicates from an unsorted linked list.
				FOLLOW UP
				How would you solve this problem if a temporary buffer is not allowed
	��ע����������ʱ�����ȿ����ǵ�������˫�����������Ƿ���ڻ����˻��Ƿ����Ҫ��
		  1.�����п�����˫ָ�룬slow��fast��1��Ѱ���м�Ԫ�� 2���ж��Ƿ��л�
		  2.��������ʽ���ռ������Ľ϶ࣨ����ΪO(n)�����������Ķ�����;��������ͨ�������������Ǵ�����ʽ���ܻ�ܸ���
**/

#include <iostream>
#include <unordered_map>
using namespace std;

struct LinkList
{
	int val;
	LinkList *next;
	LinkList(int x) :val(x), next(nullptr){}
};

// time:O(n) space:O(n)
void removeDuplicate(LinkList *head);

// time:O(n^2) space:O(1)
void removeDup(LinkList *head);

int main()
{
	LinkList head(1);
	head.next = new LinkList(3);
	head.next->next = new LinkList(1);
	head.next->next->next = new LinkList(3);
	removeDup(&head);
	LinkList *p = &head;
	while (p)
	{
		cout << p->val << " ";
		p = p->next;
	}
	return 0;
}

// time:O(n) space:O(n)
void removeDuplicate(LinkList *head)
{
	if (head == nullptr) return;
	unordered_map<int, bool> map;
	LinkList *p = head, *prev = head;
	while (p)
	{
		if (map.find(p->val) != map.end()) // �ظ�
		{
			prev->next = p->next;
			delete p;
			p = prev->next;
		}
		else
		{
			map[p->val] = true;
			prev = p;
			p = p->next;
		}
	}
}

// time:O(n^2) space:O(1)
void removeDup(LinkList *head)
{
	if (head == nullptr) return;
	LinkList *p = head, *q;
	while (p)
	{
		q = p->next;
		LinkList *prev = p;
		while (q)
		{
			if (q->val == p->val)
			{
				prev->next = q->next;
				delete q;
				q = prev->next;
			}
			else
			{
				prev = q;
				q = q->next;
			}
		}
		p = p->next;
	}
}