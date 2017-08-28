#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100002;

int n;
int parent[maxn],size[maxn];

int find(int cur)
{
	if(parent[cur]==cur) return cur;

	parent[cur]=find(parent[cur]);
	return parent[cur];
}

void union_xy(int x,int y)
{
	if(size[x]<size[y])
	{
		parent[x]=y;
		size[y]+=size[x];
	}
	else
	{
		parent[y]=x;
		size[x]+=size[y];
	}
}

int main() {

	int p,a,b,x,y;
	scanf("%d%d",&n,&p);

	for(int i=0;i<n;i++)
	{
		parent[i]=i;
		size[i]=1;
	}

	for(int i=0;i<p;i++)
	{
		scanf("%d%d",&a,&b);

		x=find(a);
		y=find(b);
		if(x!=y)
			union_xy(x,y);
	}

	long long ans=n;
	ans=ans*(n-1)/2;

	int i=1;
	for(int i=0;i<n;i++)
		if(parent[i]==i)
		{
			long long tmp=size[i];
			tmp=tmp*(size[i]-1)/2;
			ans-=tmp;
		}

	printf("%lld\n",ans);
    return 0;
}
