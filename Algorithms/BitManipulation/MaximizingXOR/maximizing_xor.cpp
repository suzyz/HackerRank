#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    scanf("%d%d",&l,&r);

    int ans=0;
    for(int i=l;i<=r;i++)
        for(int j=i;j<=r;j++)
            if((i^j) > ans)
                ans = i^j;

    printf("%d\n", ans); 

    return 0;
}