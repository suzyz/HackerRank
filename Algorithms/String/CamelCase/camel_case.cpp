#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

char s[100010];

int main() {

	scanf("%s",s);

	int n = strlen(s);
	int ans = 1;

	for(int i=0;i<n;i++)
		if(s[i]<='Z' && s[i]>='A')
			ans++;
	
	printf("%d\n",ans);
    return 0;
}
