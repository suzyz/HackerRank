#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int maxn = 100002;
const int root = 1;

int n,ans,kk;
int tot,head[maxn<<1],next_e[maxn<<1],v[maxn<<1];

int parent[maxn],w[maxn];

void add(int a,int b)
{
	tot++; next_e[tot]=head[a]; head[a]=tot; v[tot]=b;
}

int gcd(int a,int b)
{
	if(a%b==0) return b;
	return gcd(b,a%b);
}

void dfs(int x,int p)
{
	parent[x]=p;
	for(int i=head[x];i!=0;i=next_e[i])
	{
		int y=v[i];
		if(parent[y]==0)
			dfs(y,x);
	}
}

void calc(int x,int sum)
{
	sum+=w[x];
	if(sum>=kk) ans++;

	for(int i=head[x];i!=0;i=next_e[i])
	{
		if(v[i]!=parent[x])
			calc(v[i],sum);
	}
}

int main() {

	freopen("a.in","r",stdin);

	int T,g;
	scanf("%d",&T);
while(T)
{
	T--;

	tot=0;
	memset(head,0,sizeof(head));
	memset(next_e,0,sizeof(next_e));

	int a,b;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}

	memset(parent,0,sizeof(parent));
	dfs(root,-1);
	
	memset(w,0,sizeof(w));
	scanf("%d%d",&g,&kk);
	for(int i=1;i<=g;i++)
	{
		scanf("%d%d",&a,&b);
		if(parent[b]==a)
		{
			w[root]++;
			w[b]--;
		}
		else
		{
			/* It's guaranteed that an undirected edge 
			connecting a and b exists in the tree.
			So we have parent[a]==b */
			w[a]++;
		}
	}

	ans=0;
	calc(root,0);

	if(ans>0)
	{
		int c = gcd(ans,n);
		ans/=c;
		n/=c;
	}
	else
		n=1;

	printf("%d/%d\n",ans,n);
}
    return 0;
}
