#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	freopen("tower_breakers.in","r",stdin);
	freopen("tower_breakers.out","w",stdout);

	int T,n,m;
	scanf("%d",&T);

while(T)
{
	T--;

	scanf("%d%d",&n,&m);
	if(m==1 || (n&1)==0)
		printf("2\n");
	else
		printf("1\n");
}

    return 0;
}
