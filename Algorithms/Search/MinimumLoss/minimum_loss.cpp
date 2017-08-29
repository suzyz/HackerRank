#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 200002;

int n,idx[maxn];
long long p[maxn];

bool cmp(int a,int b)
{
	if(p[a]>p[b]) return true;
	return false;
}

int main() {

	scanf("%d",&n);

	for(int i=1;i<=n;i++)
	{
		idx[i]=i;
		scanf("%lld",&p[i]);
	}
	
	sort(idx+1,idx+n+1,cmp);

	int a,b;
	long long ans = ((long long)1)<<50;

	for(int i=1;i<n;i++)
	{
		a=idx[i];
		b=idx[i+1];
		if(a<b && p[a]>p[b])
			ans=min(ans,p[a]-p[b]);
	}

	printf("%lld\n",ans);
    return 0;
}
