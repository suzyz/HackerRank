#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100002;
const int maxm = 200002;

int n,m;
int tot,head[maxm],next_e[maxm],u[maxm],v[maxm];

bool cut[maxm];

int blocks,block[maxn],block_num[maxn];
int colors,color[maxn],color_num[maxn];

void add(int x,int y)
{
	tot++; next_e[tot]=head[x]; head[x]=tot; u[tot]=x; v[tot]=y;
	tot++; next_e[tot]=head[y]; head[y]=tot; u[tot]=y; v[tot]=x;
}

void tarjan(int cur)
{
	idx++;
	dfn[cur]=low[cur]=idx;

	top++;
	stack[top]=cur;
	instack[cur]=true;

	for(int i=head[cur];i!=0;i=next[i])
	{
		int y=v[i];

		if(dfn[y]==0)
		{
			tarjan(y);
			low[cur]=low[cur]<low[y] ? low[cur]:low[y];
		}
		else
			if(instack[y])
				low[cur]=low[cur]<dfn[y] ? low[cur]:dfn[y];
	}

	top--;
	instack[cur]=false;
}

int dfs1(int cur,int b)
{
	vis[cur]=true;
	block[cur]=b;

	int res=1;
	for(int i=head[cur];i!=0;i=next[i])
	{
		int y=v[i];
		if(vis[y]) continue;

		res+=dfs1(y,b);
	}
	return res;
}

int dfs2(int cur,int co)
{
	vis[cur]=true;
	color[cur]=co;

	int res=1;
	for(int i=head[cur];i!=0;i=next[i])
		if(!cut[i])
		{
			int y=v[i];
			if(vis[y]) continue;

			res+=dfs2(y,co);
		}
		return res;
}

int main() {
	int T,x,y;
	scanf("%d",&T);

while(T)
{
	T--;

	scanf("%d%d",&n,&m);

	tot=0;
	memset(head,0,sizeof(head));
	memset(next_e,0,sizeof(next_e));

	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);
		// edges[x]++;
		// edges[y]++;
	}

	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(instack,0,sizeof(instack));

	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);

	for(int i=1;i<=tot;i++)
		if(low[v[i]]>dfn[u[i]])
		{
			cut[i]=true;
			if((i&1)==0) cut[i-1]=true;
			else cut[i+1]=true;
		}

	int ans=0;
	memset(vis,0,sizeof(vis));
	blocks=0;
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			blocks++;
			block_num[blocks]=dfs1(i,blocks);

			ans+=(block_num[blocks]-1)*block_num[blocks];
		}

	memset(vis,0,sizeof(vis));
	colors=0;
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			colors++;
			color_num[colors]=dfs2(i,colors);
		}

}

    return 0;
}
