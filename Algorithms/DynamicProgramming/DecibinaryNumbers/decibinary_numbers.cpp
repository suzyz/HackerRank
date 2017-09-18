#include <cstdio>
#include <iostream>
#include <climits>
#include <cstring>
using namespace std;
const int maxv = 10000;
const int maxq = 100002;

int q[maxq];

long long sum1[52][maxv+2],sum2[maxv+2],f[maxv+2];

void find_digits(int len,int idx)
{
	int k=0;
	for(int i=0;i<=maxv;i++)
		if(sum1[len][i]>idx)
		{
			k=i-1;
			break;
		}
	
}

int main()
{
	int Q,m;
	scanf("%d",Q);

	m=0;
	for(int i=1;i<=Q;i++)
	{
		scanf("%d",&q[i]);
		m = q[i]>m ? q[i]:m;
	}
	max_len = 1;
	while(m>0)
	{
		m>>=1;
		max_len++;
	}

	f[0][0]=1;
	for(int i=1;i<=max_len;i++)
	{
		f[i][0]=1;
		for(int j=1;j<=maxv;j++)
		{
			for(int k=1;k<=9;k++)
			{
				if(j<k*(1<<(i-1)))
					break;
				f[i][j]+=f[i-1][j-k*(1<<(i-1))];
			}
			sum1[i][j]=sum1[i-1][j]+f[i][j];
			sum2[i]+=f[i][j];
		}
	}

	for(int i=1;i<=Q;i++)
	{
		int k=0;
		long long s = 1;
		for(int j=1;j<=max_len;j++)
		{
			s+=sum2[j];
			if(s>q[i])
			{
				k=j-1;
				s-=sum2[j];
				break;
			}
		}

		find_digits(k,q[i]-s);
	}

	printf("%lld\n", ans);

	
    return 0;
}