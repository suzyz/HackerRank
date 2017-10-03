#include <cmath>
#include <cstdio>
#include <climits>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
const int maxn = 1010;

int n,m;
bool mymap[maxn][maxn];
int g[maxn][maxn],dist[maxn];

void bfs(int s)
{
	queue<int> qu;

	memset(dist,-1,sizeof(dist));
	dist[s] = 0;
	qu.push(s);

	while (!qu.empty())
	{
		int x = qu.front();
		qu.pop();

		for (int i = 1; i <= g[x][0]; ++i)
		{
			int y = g[x][i];

			if (dist[y] == -1 || dist[y] > dist[x] + 6)
			{
				dist[y] = dist[x] + 6;
				qu.push(y);
			}			
		}
	}
}

int main() {
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int Q;
	scanf("%d",&Q);

while(Q--)
{
	scanf("%d%d",&n,&m);

	memset(mymap,0,sizeof(mymap));


	int st,en;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d",&st,&en);
		mymap[st][en] = mymap[en][st] = true;
	}
	for (int i = 1; i <= n; ++i)
	{
		g[i][0] = 0;
		for (int j = 1; j <= n; ++j)
			if (j!=i && mymap[i][j])
				g[i][++g[i][0]]=j;
	}

	int s;
	scanf("%d",&s);

	bfs(s);
	for (int i = 1; i <= n; ++i)
		if (i!=s)
			printf("%d ",dist[i]);

	printf("\n");
}
	
    return 0;
}
