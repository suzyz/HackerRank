#include <cstdio>
#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <utility>  /* pair */

using namespace std;
const int maxn = 1030;

int n,m,kk,tot;
int fish[maxn],cost[maxn][maxn];

vector<pair<int,int> > g[maxn];
set<pair<int,pair<int,int> > > q;

void update(int x,int y,int z)
{
	if(cost[x][y]<=z) return;

	pair<int,pair<int,int> > cur = make_pair(cost[x][y],make_pair(x,y));
	set<pair<int,pair<int,int> > >::iterator it = q.find(cur);
	if(it != q.end())
		q.erase(it);

	cost[x][y]=z;
	cur.first=z;
	q.insert(cur);
}

void init()
{
	for(int i=1;i<=n;i++)
		for(int j=0;j<tot;j++)
			cost[i][j]=INT_MAX;
}

void dij()
{
	init();

	update(1,fish[1],0);

	int x,y,z;
	pair<int,int> tmp;
	set<pair<int,pair<int,int> > >::iterator it;

	while(q.size())
	{
		it = q.begin();
		z = it->first;
		x = it->second.first;
		y = it->second.second;

		q.erase(q.begin());

		for(int i=0;i<g[x].size();i++)
		{
			tmp = g[x][i];
			update(tmp.first,y|fish[tmp.first],z+tmp.second);
		}
	}
}

int main() {

	freopen("a.in","r",stdin);

	int x,y,z;
	scanf("%d%d%d",&n,&m,&kk);
	tot = 1<<kk;

	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		for(int j=1;j<=x;j++)
		{
			scanf("%d",&z);
			fish[i]|=(1<<(z-1));
		}
	}

	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		g[x].push_back(make_pair(y,z));
		g[y].push_back(make_pair(x,z));
	}

	dij();

	int ans = INT_MAX;

	for(int i=0;i<tot;i++)
		for(int j=i;j<tot;j++)
			if((j|i)==tot-1)
			{
				if(cost[n][i]>cost[n][j])
					x=cost[n][i];
				else
					x=cost[n][j];
				if(x<ans) ans=x;
			}

	printf("%d\n", ans);

    return 0;
}
