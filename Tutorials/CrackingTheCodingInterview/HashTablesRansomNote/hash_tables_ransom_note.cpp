#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;
const int maxsize = 100007;

int m,n;
struct Node
{
	char s[6];
	int freq;
	Node ()
	{
		memset(s,0,sizeof(s));
		freq = 0;
	}
} my_hash[maxsize];

int calc(string s)
{
	int b = 378551;  
    long long a = 63689;  
	long long key = 0;
	for (int j = 0; j < s.length(); ++j)
	{
		key = (key * a + s[j]) % maxsize;
		a = a * b % maxsize;
	}
	return key;
}

int main()
{
	clock_t st,en;
	st = clock();
	freopen("a.in","r",stdin);

	char s[6];
	scanf("%d%d",&m,&n);
	for (int i = 0; i < m; ++i)
	{
		scanf("%s",s);
		int key = calc(s) % maxsize;

		while (strlen(my_hash[key].s)!=0 && strcmp(my_hash[key].s,s)!=0)
		{
			++key;
			if (key == maxsize)
				key = 0;
		}
		memcpy(my_hash[key].s,s,strlen(s)+1);
		++my_hash[key].freq;
	}

	for (int i = 0; i < n; ++i)
	{
		scanf("%s",s);
		int key = calc(s) % maxsize;
		bool found = false;
		while (strlen(my_hash[key].s)!=0)
		{
			if (strcmp(my_hash[key].s,s)==0)
			{
				if (my_hash[key].freq < 1)
				{
					cout << "No" << endl;
					return 0;
				}
				found = true;
				--my_hash[key].freq;
				break;
			}
			
			++ key;
			if (key == maxsize)
				key = 0;
		}

		if (!found)
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" <<endl;

	en = clock();
	printf("%f\n",(float)(en-st)/CLOCKS_PER_SEC);
	return 0;
}