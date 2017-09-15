#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

struct BigNum
{
	int len,d[110000];
	void operator += (BigNum &y)
	{
		int i=1,rem=0;
		while(i<=len && i<=y.len)
		{
			d[i]+=y.d[i]+rem;
			rem=d[i]/10;
			d[i]%=10;

			i++;
		}
		if(i<=len)
		{
			while(i<=len || rem>0)
			{
				d[i]+=rem;
				rem=d[i]/10;
				d[i]%=10;

				i++;
			}
			len = i-1;
		}
		else
		{
			while(i<=y.len || rem>0)
			{
				d[i]=y.d[i]+rem;
				rem=d[i]/10;
				d[i]%=10;

				i++;
			}
			len = i-1;
		}
	}
} t[22];

void square(BigNum x,BigNum &res)
{
	memset(res.d,0,sizeof(res.d));

	for(int i=1;i<=x.len;i++)
		for(int j=1;j<=x.len;j++)
			res.d[i+j-1]+=x.d[i]*x.d[j];
	
	int lim = 2*x.len-1;
	for(int i=1;i<=lim;i++)
	{
		if(res.d[lim]>9) lim++;

		res.d[i+1]+=res.d[i]/10;
		res.d[i]%=10;
	}
	res.len=lim;
}

void print(BigNum &cur)
{
	for(int j=cur.len;j>=1;j--)
		printf("%d",cur.d[j]);
	printf("\n");
}

int main()
{
	int n;
	scanf("%d%d%d",&t[1].d[1],&t[2].d[1],&n);

	t[1].len=t[2].len=1;
	BigNum tmp;
	for(int i=3;i<=n;i++)
	{
		t[i]=t[i-2];
		square(t[i-1],tmp);

		// printf("i:%d\n",i);
		// print(t[i-1]);
		// print(tmp);

		t[i]+=tmp;
	}

	print(t[n]);
	printf("%d\n",t[n].len );

    return 0;
}