#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    int T,n;
    scanf("%d",&T);

while(T)
{
    T--;
    scanf("%d",&n);

    int d,sum=0,mins=0,ans1=-1e9,ans2=0,maxd=-1e9;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&d);
        if(d>0) ans2+=d;
        if(d>maxd) maxd=d;
        sum += d;

        if(sum-mins>ans1) ans1 = sum-mins;

        if(sum<mins) mins=sum;
    }
    
    if(maxd<0) ans2 = maxd;

    printf("%d %d\n",ans1,ans2);
}
    return 0;
}
