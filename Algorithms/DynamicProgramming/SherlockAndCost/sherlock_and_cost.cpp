#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib> /* abs */
#include <cmath>
using namespace std;

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);

    int T,n,cur,pre,lo_hi,lo_lo,hi_lo,hi_hi,best_lo,best_hi,new_best_lo,new_best_hi;
    scanf("%d",&T);

while(T)
{
    T--;

    best_lo = best_hi = lo_hi = hi_lo = lo_lo = hi_hi = 0;
    scanf("%d",&n);
    scanf("%d",&pre);
    for(int i=2;i<=n;i++)
    {
        scanf("%d",&cur);
        lo_lo=0; /* 1 - 1 */
        lo_hi=cur-1;
        hi_lo=pre-1;
        hi_hi=abs(cur-pre);

        new_best_lo = max(best_lo,best_hi + hi_lo);
        new_best_hi = max(best_lo + lo_hi,best_hi + hi_hi);

        best_lo = new_best_lo;
        best_hi = new_best_hi;
        pre=cur;
    }

    printf("%d\n",best_lo > best_hi ? best_lo:best_hi);
}
   
    return 0;
}