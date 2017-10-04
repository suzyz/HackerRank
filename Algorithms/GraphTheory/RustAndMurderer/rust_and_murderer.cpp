#include <cmath>
#include <cstdio>
#include <climits>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <utility>
#include <vector>

using namespace std;
const int maxn = 200010;

int n,m;
int dist[maxn];
map<int,bool> main_road[maxn];
vector<int> g[maxn];
set<int> q;

void dij(int s)
{
	memset(dist,-1,sizeof(dist));
	dist[s] = 0;

	//q.insert(s);
	for (vector<int>::iterator i = g[s].begin(); i != g[s].end(); ++i)
	{
		dist[*i] = 1;
		q.insert(*i);
	}

	while (!q.empty())
	{
		set<int>::iterator cur = q.begin();
		int k = *cur;
		q.erase(cur);
		for (vector<int>::iterator i = g[k].begin(); i != g[k].end(); ++i)
		{
			if (dist[*i] == -1 || dist[*i] > dist[k] + 1)
			{
				dist[*i] = dist[k] + 1;
				if (q.find(*i) == q.end())
					q.insert(*i);
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

	for (int i = 1; i <= n; ++i)
	{
		g[i].clear();
		main_road[i].clear();
	}

	int st,en;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d",&st,&en);
		main_road[st][en] = main_road[en][st] = true;	
	}

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (i != j && !main_road[i][j])
				g[i].push_back(j);

	int s;
	scanf("%d",&s);

	dij(s);
	
	for (int i = 1; i <= n; ++i)
		if (i!=s)
			printf("%d ",dist[i]);

	printf("\n");
}
    return 0;
}
