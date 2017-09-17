#include <cstdio>
#include <iostream>
using namespace std;

int n,m,c[52];
long long f[252];

int main()
{
	scanf("%d%d",&n,&m);

	for(int i=1;i<=m;i++) scanf("%d",&c[i]);

	f[0]=1;
	for(int i=1;i<=m;i++)
		for(int j=c[i];j<=n;j++)
			f[j]+=f[j-c[i]];

	printf("%lld\n",f[n]);

    return 0;
}