#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int n,top,match[260];
char s[1010],stack[1010];

bool is_balanced()
{
	top = 0;
	for (int i = 0; i < strlen(s); ++i)
	{
		switch (s[i])
		{
			case '(':
			case '[':
			case '{':
				stack[++top] = s[i];
				break;
			case ')':
			case ']':
			case '}':
				if (top > 0 && stack[top] == match[s[i]])
				{
					--top;
					break;
				}
				else
					return false;
		}
	}
	return top == 0;
}

int main()
{
	match[')'] = '(';
	match[']'] = '[';
	match['}'] = '{';

	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s",s);
		if (is_balanced())
			printf("YES\n");
		else
			printf("NO\n");
	}
	

	return 0;
}