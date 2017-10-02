#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;
const int maxn = 1502;

int n,lim;
char s1[maxn],s2[maxn];
int f[maxn][maxn];

int main()
{
    // freopen("a.in","r",stdin);
    int T;
    scanf("%d",&T);
while(T) {
    T--;

    scanf("%d",&lim);
    scanf("%s%s",s1+1,s2+1);                                                                                                           

    n = strlen(s1+1);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            if (s1[i] == s2[j])
                f[i][j] = f[i-1][j-1];
            else
                f[i][j] = f[i-1][j-1]+1;
        }

    int ans = 0;
    for (int gap = 0; gap < n; ++gap) {
        int st1 = 0, st2 = 0;
        for (int en = 1; en+gap <= n; ++en) {
            while (st1 < en && f[en][en+gap] - f[st1][st1+gap] > lim)
                st1++;

            if (en-st1 > ans)
                ans = en-st1;

            while (st2 < en && f[en+gap][en] - f[st2+gap][st2] > lim)
                st2++;

            if (en-st2 > ans)
                ans = en-st2;
        }
    }
    printf("%d\n", ans);
}
    return 0;
}
