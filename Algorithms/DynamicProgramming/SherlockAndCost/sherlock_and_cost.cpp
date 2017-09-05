#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

const int maxn = 100002;

int n;
int data[maxn],f[maxn][102];

int main()
{
    int T;
    scanf("%d",&T);

while(T)
{
    T--;
    memset(f,0,sizeof(f));

    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&data[i]);

    for(int i=2;i<=n;i++)
        for(int j=1;j<=data[i];j++)
        {
            for(int k=1;k<=data[i-1];k++)
            {
                int tmp=f[i-1][k]+abs(j-k);
                f[i][j]=tmp>f[i][j] ? tmp:f[i][j];
            }
        }

    int ans=0;
    for(int j=1;j<=data[n];j++)
        ans=f[n][j]>ans ? f[n][j]:ans;

    printf("%d\n", ans);
}
   
    return 0;
}