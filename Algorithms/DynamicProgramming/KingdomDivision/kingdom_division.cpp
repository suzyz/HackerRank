#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;
const int maxn = 100002;
const int maxm = 200002;
const long long mo = 1e9 + 7;

int n,degree[maxn];
bool vis[maxn];
int tot=0,head[maxm],next_e[maxm],v[maxm];
long long f[maxn][2];

void add_e(int a,int b)
{
    tot++; next_e[tot]=head[a]; head[a]=tot; v[tot]=b;
}

void dfs(int cur,long long sum,int x,vector<int> &ch)
{
    if(cur==ch.size())
    {
        f[x][1] = (f[x][1]+sum)%mo;
        return;
    }

    for(int j=0;j<=1;j++)
    {
        if(cur==0) dfs(cur+1,f[ch[cur]][j],x,ch);
        else dfs(cur+1,(sum*f[ch[cur]][j])%mo,x,ch);
    }
}

void calc(int x)
{
    vis[x]=true;
    std::vector<int> children;

    for(int i = head[x]; i!=0 ;i = next_e[i])
    {
        int y = v[i];
        if(vis[y]) continue;

        children.push_back(y);
        calc(y);
    }

    if(children.size()==0)
    {
        f[x][0]=0;
        f[x][1]=1;
        return;
    }

    if(children.size()==1)
    {
        f[x][0]=f[children[0]][1];
        f[x][1]=(f[x][0]+f[children[0]][0])%mo;
        return;
    }

    dfs(0,0,x,children);

    long long tmp = f[children[0]][0];
    for(int i=1;i<children.size();i++) 
        tmp = tmp * f[children[i]][0] % mo;
    
    f[x][0] = f[x][1] + mo - tmp;
    if(f[x][0]>=mo) f[x][0] -= mo;
}

int main()
{
    freopen("a.in","r",stdin);
    // freopen("a.out","w",stdout);

    scanf("%d",&n);

    int a,b;
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        add_e(a,b);
        add_e(b,a);
        degree[a]++;
        degree[b]++;
    }

    int root = 0;
    for(int i=1;i<=n;i++)
        if(degree[i]==1)
        {
            root=i;
            break;
        }

    memset(vis,0,sizeof(vis));
    calc(root);

    long long ans = f[root][0]<<1;
    if(ans>=mo) ans-=mo;
    printf("%lld\n",ans);

    return 0;
}