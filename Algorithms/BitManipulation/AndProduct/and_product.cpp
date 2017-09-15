#include <cstdio>
#include <iostream>
#include <climits>
using namespace std;

long long calc(long long x)
{
	for(int i=0;i<32;i++)
		if((((long long)1)<<i)>=x)
			return ((long long)1)<<i;

	return INT_MAX;
}

int main()
{
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
	 	ans=l;

	for(int i=st+1;i<=r;i++)
	   	ans&=i;

    printf("%lld\n", ans);
}

    return 0;
}