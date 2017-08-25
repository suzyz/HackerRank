#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int maxn = 200002;

int n;
struct BigNum
{
	int len;
	string d;
} nums[maxn];

int idx[maxn];
int top=0,st[maxn<<1][2]; /* stack */
bool done[maxn<<1];

bool cmp(int a,int b) /* return true if nums[a]<nums[b] */
{
	if(nums[a].len<nums[b].len) return true;
	if(nums[a].len>nums[b].len) return false;

	return (nums[a].d<nums[b].d);
}

void qs()
{
	top=1;
	st[1][0]=1;
	st[1][1]=n;
	done[1]=false;

	int l,r,mid,tmp;
	while(top>0)
	{
		l=st[top][0];
		r=st[top][1];

		if(l>=r || done[top])
		{
			top--;
			continue;
		}

		done[top]=true;
		mid=l;
		for(int i=l;i<r;i++)
			if(cmp(idx[i],idx[r]))
			{
				tmp=idx[mid]; idx[mid]=idx[i]; idx[i]=tmp;
				mid++;
			}

		tmp=idx[mid]; idx[mid]=idx[r]; idx[r]=tmp;

		if(l<=mid-1)
		{
			top++;
			st[top][0]=l;
			st[top][1]=mid-1;
			done[top]=false;
		}
		if(mid<r)
		{
			top++;
			st[top][0]=mid+1;
			st[top][1]=r;
			done[top]=false;
		}
	}
}

int main() {

	freopen("big_sorting.in","r",stdin);

	scanf("%d",&n);

	char tmp[1000002];
	for(int i=1;i<=n;i++)
	{
		idx[i]=i;
		scanf("%s",tmp);
		nums[i].d = tmp;
		nums[i].len = strlen(tmp);
	}

	qs();

	for(int i=1;i<=n;i++)
		printf("%s\n",nums[idx[i]].d.c_str());

    return 0;
}
