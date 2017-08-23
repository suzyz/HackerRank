#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool vis[102],w[102];

bool win(int cur)
{
	if(cur<2)
		return false;
	if(cur<7)
		return true;

	if(vis[cur])
		return w[cur];

	vis[cur]=true;
	if(!win(cur-2) || !win(cur-3) || !win(cur-5))
		w[cur]=true;
	else
		w[cur]=false;

	return w[cur];
}

int main() {

	freopen("game_of_stones.in","r",stdin);
	freopen("game_of_stones.out","w",stdout);

	int n,m;
	scanf("%d",&m);
for(int i=1;i<=m;i++)
{
	scanf("%d",&n);

	if(win(n))
		printf("First\n");
	else
		printf("Second\n");
}

    return 0;
}
