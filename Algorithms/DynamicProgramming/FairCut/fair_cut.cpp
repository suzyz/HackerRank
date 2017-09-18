#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;
const int maxn = 3002;

int n,m;
long long d[maxn],f[maxn][maxn];

int main()
{
    freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);

    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&d[i]);

    sort(d+1,d+n+1);

    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            f[i][j]= ((long long) 1)<<50;

    if(m>n/2)
        m = n-m;

    f[0][0]=0;
    long long tmp;
    for(int i=0;i<n;i++)
        for(int j=0;j<=i;j++)
        {
            if(j>m || i-j>n-m) continue;

            tmp = f[i][j] + (i-j-(n-m-(i-j)))*d[i+1];
            if(tmp<f[i+1][j+1]) f[i+1][j+1]=tmp;

            tmp = f[i][j] + (j-(m-j))*d[i+1];
            if(tmp<f[i+1][j]) f[i+1][j]=tmp;
        }

    printf("%lld\n",f[n][m]);
    return 0;
}
