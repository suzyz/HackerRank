#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	
	int T,n;
	scanf("%d",&T);

while(T)
{
	T--;

	scanf("%d",&n);

	int ans=0,s;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&s);
		ans^=s;
	}

	if(ans==0)
		printf("Second\n");
	else
		printf("First\n");
}

    return 0;
}
