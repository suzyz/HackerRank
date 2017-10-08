#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

struct Stack
{
	int top;
	int d[100010];
	
	Stack() { top = 0; }

	void push(int x) { d[++top] = x; }
	void pop() { if (top > 0) --top; }
	int peek() { return d[top]; }
} stack_new,stack_old;

void move()
{
	while (stack_new.top > 0)
	{
		stack_old.push(stack_new.peek());
		stack_new.pop();
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		int op;
		scanf("%d",&op);
		switch (op)
		{
			case 1:
				int x;
				scanf("%d",&x);
				stack_new.push(x);
				break;
			case 2:
				if (stack_old.top == 0)
					move();

				stack_old.pop();
				break;
			case 3:
				if (stack_old.top == 0)
					move();
				printf("%d\n",stack_old.peek());
		}
	}

	return 0;
}