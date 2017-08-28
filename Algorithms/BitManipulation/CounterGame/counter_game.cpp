#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long n;

int main() {
    int T;
    scanf("%d",&T);
    
while(T)
{
    T--;
    
    scanf("%lld",&n);
    
    int count=0;
    while(n>1)
    {
        count++;
        if((n&1)==0) n>>=1;
        else
        {
            for(int i=63;i>=0;i--)
                if((n&(((long long)1)<<i))!=0)
                {
                    n-=((long long)1)<<i;
                    break;
                }
        }
    }
    
    if(count%2) printf("Louise\n");
    else printf("Richard\n");
}
    return 0;
}

