#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int dir[][2] = {{-2,1},{-2,-1},{1,-2},{-1,-2}};

bool vis[20][20],w[20][20];

bool win(int x,int y)
{
	if(vis[x][y]) return w[x][y];

	vis[x][y]=true;

	int tx,ty;
	for(int i=0;i<4;i++)
	{
		tx = x+dir[i][0];
		if(tx<1 || tx>15) continue;
		ty = y+dir[i][1];
		if(ty<1 || ty>15) continue;

		if(!win(tx,ty))
		{
			w[x][y]=true;
			break;
		}
	}
	return w[x][y];
}

int main() {

	freopen("a_chessboard_game.in","r",stdin);
	freopen("a_chessboard_game.out","w",stdout);

	int T,x,y;
	scanf("%d",&T);

while(T)
{
	T--;

	scanf("%d%d",&x,&y);

	if(win(x,y))
		printf("First\n");
	else
		printf("Second\n");
}

    return 0;
}
