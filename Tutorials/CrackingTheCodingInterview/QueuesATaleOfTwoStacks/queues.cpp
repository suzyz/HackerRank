/* Plain and Simple. Without using two stacks.
   For the solution using two stacks, please check out queues_2.cpp.
 */

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

struct Queue
{
	int head,tail;
	int nums[100010];

	Queue() { head = tail = 0; }
	void enqueue(int x) { nums[tail++] = x; }
	void dequeue() { ++head; }
	int top() { return nums[head]; }
} qu;


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
				qu.enqueue(x);
				break;
			case 2:
				qu.dequeue();
				break;
			case 3:
				printf("%d\n",qu.top());
		}
	}

	return 0;
}