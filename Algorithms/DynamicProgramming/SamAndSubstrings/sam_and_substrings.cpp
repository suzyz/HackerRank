#include <cstdio>
#include <iostream>
#include <climits>
#include <cstring>
using namespace std;
const int maxn = 200002;
const int mo = 1e9+7;

int n;
char s[maxn];
long long f[maxn];

int main()
{
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++) s[i]-='0';

	f[0]=s[0];
	for(int i=1;i<n;i++)
		f[i] = (10*f[i-1] + s[i]*i + s[i]) %mo;

	long long ans=0;
	for(int i=0;i<n;i++)
		ans = (ans + f[i])%mo;

	printf("%lld\n", ans);
    return 0;
}