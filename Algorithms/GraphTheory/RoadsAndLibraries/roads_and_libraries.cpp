#include <iostream>
#include <cstring>

//using namespace std;

const int maxn = 100002;

int tot,head[maxn<<1],next[maxn<<1],v[maxn<<1];

int colors, co[maxn];

void add(int x,int y)
{
	tot++; next[tot]=head[x]; head[x]=tot; v[tot]=y;
}

void dfs(int x)
{
	co[x]=colors;

	for(int i=head[x];i!=0;i=next[i])
	{
		int y=v[i];
		if(co[y]!=0) continue;
		dfs(y);
	}
}

int main()
{
	long long ans;
	int n,m,a,b,Q,c_lib,c_road;
	scanf("%d",&Q);

while(Q)
{
	Q--;

	scanf("%d%d%d%d",&n,&m,&c_lib,&c_road);
	if(c_lib<=c_road)
	{
		ans=(long long)c_lib * n;
		printf("%lld\n",ans);

		if(Q)
			for(int i=0;i<m;i++)
				scanf("%d%d",&a,&b);

		continue;
	}

	tot=0;
	memset(head,0,sizeof(head));
	memset(next,0,sizeof(next));
	memset(co,0,sizeof(co));
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}

	colors=0;
	for(int i=1;i<=n;i++)
		if(co[i]==0)
		{
			colors++;
			dfs(i);
		}

	ans=(long long)colors * c_lib + (long long) (n-colors) * c_road;
	printf("%lld\n",ans);
}

	return 0;
}