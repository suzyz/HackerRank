#include <cstdio>
#include <iostream>
#include <climits>
using namespace std;

long long calc(long long x)
{
	for(int i=0;i<33;i++)
		if((((long long)1)<<i)>=x)
			return ((long long)1)<<i;

	return INT_MAX;
}

int main()
{
	freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);

	int T;
	long long l,r;
	scanf("%d",&T);
while(T)
{
	T--;

	scanf("%lld%lld",&l,&r);

	long long st = calc(l),ans;
	if(st<=r)
	 	ans=st;
	else
		st=ans=l;

	for(long long i=st+1;i<=r;i++)
	   	ans&=i;

    printf("%lld\n", ans);
    //printf("T:%d\n",T);
}

    return 0;
}