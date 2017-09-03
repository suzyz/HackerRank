/* Build a new map and run Dijkstra. TLE for some cases. */

#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <climits>
#include <queue>

using namespace std;
const int maxn = 1002;
const int maxsum = 1000002;
const int maxt = 10000001;

int n,m,kk,tot;
int fi[maxn];

int M,head[maxt],next_e[maxt],v[maxt],c[maxt];

bool vis[maxsum];
int dist[maxsum];

void add(int x,int y,int z)
{
	M++; next_e[M]=head[x]; head[x]=M; v[M]=y; c[M]=z;
}

class mycomparison
{
public:
  bool operator() (const int &a, const int &b) const
  {
    if(dist[a]<dist[b]) return a;
	else return b;
  }
};

void dij()
{
	memset(dist,-1,sizeof(dist));

	int sum = tot*n, k;
	std::priority_queue<int,vector<int>,mycomparison> q;

	dist[fi[0]]=0;
	q.push(fi[0]);

	for(int i=1;i<sum;i++)
	{
		if(q.empty()) break;

		k=0;
		while(!q.empty())
		{
			k=q.top();
			q.pop();
// printf("%d\n",k );
			if(!vis[k]) break;
		}

		if(vis[k]) break;
		vis[k]=true;
printf("size:%d\n", q.size());
		for(int j=head[k];j!=0;j=next_e[j])
		{
			int y=v[j];
			if(vis[y]) continue;
			if(dist[y]==-1 || dist[y]>dist[k]+c[j])
			{
				dist[y]=dist[k]+c[j];
				q.push(y);
			}
		}
	}
}

int main() {

	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);

	int x,y,z;
	scanf("%d%d%d",&n,&m,&kk);
	tot = 1<<kk;

	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		for(int j=1;j<=x;j++)
		{
			scanf("%d",&z);
			fi[i]|=(1<<(z-1));
		}
	}

	int a,b;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		x--;
		y--;
		a = tot*x;
		b = tot*y;

		for(int j=0;j<tot;j++)
		{
			if(fi[x]==0 || (j&fi[x])) 
				add(a+j,b+(j|fi[y]),z);
			if(fi[y]==0 || (j&fi[y])) 
				add(b+j,a+(j|fi[x]),z);
		}
	}

	dij();

	int ans = INT_MAX;
	b = tot*(n-1);

	for(int i=0;i<tot;i++)
		if(dist[b+i]!=-1)
			for(int j=tot-i-1;j<tot;j++)
				if((j|i)==tot-1 && dist[b+j]!=-1)
				{
					if(dist[b+i]>dist[b+j]) x = dist[b+i];
					else x = dist[b+j];
					if(x<ans) ans=x;
				}

	printf("%d\n", ans);

    return 0;
}
