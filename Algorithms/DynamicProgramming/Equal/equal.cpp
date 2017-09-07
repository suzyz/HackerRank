#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <climits>
using namespace std;

int n,chocolate[10002];
int cost[1010];

int main()
{
    freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);

    int T;
    scanf("%d",&T);

    cost[0]=0;
    cost[1]=cost[2]=cost[5]=1;
    cost[3]=cost[4]=2;
    for(int i=6;i<=1005;i++)
        cost[i] = cost[i-5]+1;

while(T)
{
    T--;

    scanf("%d",&n);

    scanf("%d",&chocolate[1]);
    int minn = chocolate[1];
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&chocolate[i]);
        if(chocolate[i]<minn) minn=chocolate[i];
    }

    int ans = INT_MAX;
    for(int i=0;i<=4;i++)
    {
        int goal = minn - i, sum = 0;

        for(int j=1;j<=n;j++)
             sum += cost[chocolate[j]-goal];
            
        if(sum<ans) ans=sum;
    }

    printf("%d\n", ans);
}
    return 0;
}