#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int heap_size = 0;
struct Node
{
	int sum,val,l,r;
	Node() { sum = 0; val = l = r = -1; }
} nums_heap[100010];

void insert_node(int x)
{
	if (heap_size == 0)
	{
		heap_size = 1;
		nums_heap[1].sum = 1;
		nums_heap[1].val = x;
		return;
	}
	int i = 1;
	while (i>0)
	{
		++ nums_heap[i].sum;

		if (x < nums_heap[i].val)
		{
			if (nums_heap[i].l == -1)
			{
				nums_heap[i].l = ++heap_size;
				i = nums_heap[i].l;
				nums_heap[i].sum = 1;
				nums_heap[i].val = x;
				return;
			}
			
			i = nums_heap[i].l;
		}
		else
		{
			if (nums_heap[i].r == -1)
			{
				nums_heap[i].r = ++heap_size;
				i = nums_heap[i].r;
				nums_heap[i].sum = 1;
				nums_heap[i].val = x;
				return;
			}
			
			i = nums_heap[i].r;
		}
	}
}

int get_nth(int n)
{
	int i = 1;
	while (i>0)
	{
		if (nums_heap[i].l == -1 && n==1)
			return nums_heap[i].val;
		if (nums_heap[i].l != -1 && n == nums_heap[nums_heap[i].l].sum +1)
			return nums_heap[i].val;

		if (nums_heap[i].l != -1 && nums_heap[nums_heap[i].l].sum >= n)
		{
			i = nums_heap[i].l;
			continue;
		}

		if (nums_heap[i].l != -1)
			n = n - 1 - nums_heap[nums_heap[i].l].sum;
		else
			--n;

		i = nums_heap[i].r;
	}
	return -1;
}

int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i)
	{
		int j;
		scanf("%d",&j);
		insert_node(j);

		if (i&1)
			printf("%.1f\n",1.0*get_nth((i+1)/2));
		else
			printf("%.1f\n",0.5*(get_nth(i/2)+get_nth(i/2+1)));
	}

	return 0;
}