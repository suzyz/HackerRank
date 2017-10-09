#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
const int maxn = 200002;

int n;
long long p[maxn];

set<long long> prices;


int main() {

	scanf("%d",&n);

	for(int i=1;i<=n;i++)
		scanf("%lld",&p[i]);

	long long ans = ((long long) 1) << 50;
	prices.insert(p[1]);
	for (int i = 2; i <= n; ++i)
	{
		set<long long>::iterator it = prices.upper_bound(p[i]);
		if (it != prices.end())
			if (*it - p[i] < ans)
				ans = *it - p[i];

		prices.insert(p[i]);
	}

	printf("%lld\n",ans);
    return 0;
}
