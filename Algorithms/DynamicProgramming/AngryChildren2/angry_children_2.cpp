#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;
const int maxn = 100002;

int n,m;
long long d[maxn],sum[maxn];

int main()
{
    freopen("a.in","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&d[i]);

    sort(d+1,d+n+1);

    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+d[i];

    long long cur,ans=0;

    for(int i=1;i<=m;i++)
        ans += d[i] * (long long)(i-1 - (m-i));

    cur = ans;
    for(int i=2;i<=n-m+1;i++)
    {
        cur += (d[i-1] + d[i+m-1]) * (long long)(m-1) - (sum[i+m-2]-sum[i-1])*2;

        if(cur<ans) ans=cur;
    }

    printf("%lld\n", ans);
    return 0;
}
