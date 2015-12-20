/**
	wanyunpeng  11.16
	questions : Implement a function void reversefchar* str) in Cor C++ which reverses a null-terminated string.
	备注：string不能变成char*
**/

#include <iostream>
#include <string>

using namespace std;

// K&R
void reverse(char *s);

// 指针
void reverse2(char *s);
void swap(int &a, int &b);
int main()
{
	char s[] = "reverse";
	reverse(s);
	cout << s << endl;
	return 0;
}

void reverse(char *s)
{
	for (int i = 0, j = strlen(s) - 1; i < j; ++i,--j)
	{
		char tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
}


// 指针
void reverse2(char *s)
{
	if (!s) return;
	char *p = s, *q = s;
	while (*q) q++;
	q--;
	while (p < q)
	{
		swap(*p++, *q--);
	}
}
void swap(char &a, char &b)
{
	a = a ^ b;
	a = a ^ b;
	a = a ^ b;
}