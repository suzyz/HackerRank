#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn =30;

int n;
int dist[maxn][maxn],ans[maxn][maxn];

int qu[700][2];

int bfs(int a,int b)
{
	memset(dist,-1,sizeof(dist));

	dist[1][1]=0;

	int l=0,r=1;
	int x,y,tx,ty,dir[2];
	dir[0]=a;
	dir[1]=b;
	qu[0][0]=qu[0][1]=1;

	while(l<r)
	{
		x=qu[l][0];
		y=qu[l][1];
		l++;

		for(int k=0;k<=1;k++)
		{
			for(int i=-1;i<=1;i+=2)
				for(int j=-1;j<=1;j+=2)
				{
					tx=x+i*dir[k];
					ty=y+j*dir[1-k];
					// printf("a:%d b:%d x:%d y:%d tx:%d ty:%d\n", a,b,x,y,tx,ty);
					if(tx<1 || ty<1 || tx>n || ty>n || dist[tx][ty]>=0) continue;

					dist[tx][ty]=dist[x][y]+1;
					qu[r][0]=tx;
					qu[r][1]=ty;
					r++;
				}
		}
		if(dist[n][n]>=0) break;
	}
	return dist[n][n];
}

int main() {

	scanf("%d",&n);

	for(int i=1;i<n;i++)
		for(int j=i;j<n;j++)
			ans[i][j]=bfs(i,j);

	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(i<=j) printf("%d",ans[i][j]);
			else printf("%d",ans[j][i]);

			if(j<n-1) printf(" ");
		}
		printf("\n");
	}

    return 0;
}
