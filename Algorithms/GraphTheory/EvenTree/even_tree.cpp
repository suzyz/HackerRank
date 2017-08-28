#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int maxn = 120;

int n,ans=0;
int g[maxn][maxn],children[maxn];
bool vis[maxn];

void calc(int x)
{
	vis[x]=true;
	children[x]=1;
	for(int i=1;i<=g[x][0];i++)
	{
		int y=g[x][i];
		if(!vis[y])
		{
			calc(y);
			children[x]+=children[y];
		}
	}
}

void cut(int x)
{
	vis[x]=true;
	for(int i=1;i<=g[x][0];i++)
	{
		int y=g[x][i];
		if(!vis[y])
		{
			if(children[y]%2==0)
			{
				children[x]-=children[y];
				ans++;
			}
			cut(y);
		}
	}
}

int main() {

	int p,a,b;
	scanf("%d%d",&n,&p);

	if(n%2!=0)
	{
		printf("0\n");
		return 0;
	}

	for(int i=0;i<p;i++)
	{
		scanf("%d%d",&a,&b);

		g[a][0]++;
		g[a][g[a][0]]=b;
		g[b][0]++;
		g[b][g[b][0]]=a;
	}

	calc(1);

	memset(vis,0,sizeof(vis));
	cut(1);

	printf("%d\n",ans);
    return 0;
}
