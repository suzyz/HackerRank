#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 3002;
const int maxm = 4500000;

int n,m,fa[maxn];
long long ans=0;

struct Edge
{
	int st,en,w;
} e[maxm];

bool cmp(const Edge &a,const Edge &b)
{
	if (a.w < b.w)
		return true;
	if (a.w > b.w)
		return false;
	if (a.st+a.en < b.st+b.en)
		return true;
	else
		return false;
}

int find_fa(int cur)
{
	if (fa[cur] == cur)
		return cur;

	fa[cur] = find_fa(fa[cur]);
	return fa[cur];
}

int main() {

	scanf("%d%d",&n,&m);

	for (int i = 0; i < m; ++i)
		scanf("%d%d%d",&e[i].st,&e[i].en,&e[i].w);
	
	sort(e,e+m,cmp);

	for (int i = 1; i <= n; ++i)
		fa[i] = i;

	int count = 0;
	for (int i = 0; i < m; ++i)
	{
		int x = find_fa(e[i].st);
		int y = find_fa(e[i].en);
		if (x==y)
			continue;

		++ count;
		ans += e[i].w;
		fa[x] = y;
		if (count >= n)
			break;
	}
	
	printf("%lld\n",ans);
    return 0;
}
