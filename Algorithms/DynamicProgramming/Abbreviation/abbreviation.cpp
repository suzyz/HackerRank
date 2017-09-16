#include <cstdio>
#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

bool f[1002][1002];

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);

	int T;
	scanf("%d",&T);
while(T)
{
	T--;

	char a[1002],b[1002];
	scanf("%s%s",a,b);

	int la = strlen(a), lb = strlen(b);

	memset(f,0,sizeof(f));
	for(int i=0;i<la;i++)
		for(int j=0;j<lb;j++)
		{
			if(a[i]==b[j] || (a[i]>='a' && a[i]-'a'+'A'==b[j]))
			{
				if(i>0 && j>0)
					f[i][j]|=f[i-1][j-1];
				else
				if(j==0)
					f[i][j]=true;		
			}
			if(a[i]>='a' && i>j) f[i][j]|=f[i-1][j];
		}

	if(f[la-1][lb-1]) printf("YES\n");
	else printf("NO\n");
}

    return 0;
}