/* Works ok for test case 0,1,2,3,4. But TLE for the rest.  */

#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int maxn = 100002;

int n;
int tot,head[maxn<<1],next_e[maxn<<1],v[maxn<<1];

int parent[maxn],w[maxn];

int mytime,order[maxn],time1[maxn],time2[maxn];

bool vis[maxn];

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
	mytime++;
	order[mytime]=x;
	time1[x]=mytime;
	
	parent[x]=p;
	for(int i=head[x];i!=0;i=next_e[i])
	{
		int y=v[i];
		if(parent[y]==0)
			dfs(y,x);
	}

	time2[x]=mytime;
}

int main() {

	freopen("a.in","r",stdin);

	int T,g,kk;
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

	mytime=0;
	memset(parent,0,sizeof(parent));
	dfs(1,-1);

	memset(w,0,sizeof(w));
	scanf("%d%d",&g,&kk);
	for(int i=1;i<=g;i++)
	{
		scanf("%d%d",&a,&b);
		if(parent[b]==a)
		{
			for(int j=1;j<time1[b];j++)
				w[order[j]]++;
			for(int j=time2[b]+1;j<=n;j++)
				w[order[j]]++;
		}
		else
			for(int j=time1[a];j<=time2[a];j++)
				w[order[j]]++;
	}

	int ans=0;
	for(int i=1;i<=n;i++)
		if(w[i]>=kk)
			ans++;

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
