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

bool check(int len) {
    for (int i = 1; i <= n-len+1; ++i)
        for (int j = 1; j <= n-len+1; ++j)
            if (f[i+len-1][j+len-1] - f[i-1][j-1]<=lim)
                return true;
    return false;
}

int main()
{
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

    int l = 0, r = n;
    while (l<r) {
        int mid = l + ((r-l)>>1) + 1;
        if (check(mid)) {
            l = mid;
        }
        else
            r = mid-1;
    }
    printf("%d\n", l);
}
    return 0;
}
