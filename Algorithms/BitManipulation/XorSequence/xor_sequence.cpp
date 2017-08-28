#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

long long f(long long x)
{
	int y = x&7;
	if(y<2) return x;
	if(y<4) return 2;
	if(y<6) return x+2;
	return 0;
}

int main() {

	freopen("a.in","r",stdin);

	int q;
	long long l,r,ans;

	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%lld%lld",&l,&r);
		ans=f(r)^f(l-1);
		printf("%lld\n",ans);
	}

    return 0;
}