#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

struct NumsHeap
{
	bool is_min_heap;
	int size, nums[100010];
	NumsHeap(bool flag) { is_min_heap = flag; size = 0; }

	void push(int x);
	void pop();
	int top() { return size > 0 ? nums[1] : -1; }
} min_heap(true), max_heap(false);

void NumsHeap::push(int x)
{
	nums[++size] = x;

	int i = size, j = i>>1;
	while (j>0)
	{
		if (is_min_heap ^ (nums[j] > nums[i]))
			break;

		int tmp = nums[i]; nums[i] = nums[j]; nums[j] = tmp;
		i = j;
		j = i>>1;
	}
}

void NumsHeap::pop()
{
	--size;
	if (size == 0)
		return;
	nums[1] = nums[size+1];
	int i = 1, j = i<<1;
	while (j<=size)
	{
		if (is_min_heap && (nums[i] <= nums[j] && (j==size || (j<size && nums[i] <= nums[j+1]))))
			break;
		if (!is_min_heap && (nums[i] >= nums[j] && (j==size || (j<size && nums[i] >= nums[j+1]))))
			break;

		if (j<size && (is_min_heap ^ (nums[j+1] > nums[j])))
			++j;
		int tmp = nums[i]; nums[i] = nums[j]; nums[j] = tmp;
		i = j;
		j = i<<1;
	}
}

void rebalance()
{
	if (min_heap.size > max_heap.size + 1)
	{
		max_heap.push(min_heap.top());
		min_heap.pop();
	}
	else
	if (max_heap.size > min_heap.size + 1)
	{
		min_heap.push(max_heap.top());
		max_heap.pop();
	}
}

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);

	int n;
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i)
	{
		int j;
		scanf("%d",&j);

		if (min_heap.size == 0 || j >= min_heap.top())
			min_heap.push(j);
		else
			max_heap.push(j);
		rebalance();

		if (i&1)
		{
			if (min_heap.size > max_heap.size)
				printf("%.1f\n",1.0 * min_heap.top());
			else
				printf("%.1f\n",1.0 * max_heap.top());
		}
		else
			printf("%.1f\n",0.5 * (min_heap.top() + max_heap.top()));
	}

	return 0;
}