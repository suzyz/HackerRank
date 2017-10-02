#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 2502;

int n,d[maxn];

int main() {
	int mode = 0;
	/* sd: stanstard deviation */
	double sum = 0, mean = 0, median = 0, sd = 0 ,lower_boundary, upper_boundary;

	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&d[i]);
		sum += d[i];
	}
	mean = sum/n;
	sort (d,d+n);
	median = (1.0 * d[(n>>1)] + d[((n-1)>>1)])/2.0;

	int count = 1, max_count = 1;
	mode = d[0];
	int i = 1;
	while (i<n)
	{
		if (d[i]==d[i-1])
		{
			++count;
			if (count>max_count)
			{
				max_count = count;
				mode = d[i];
			}
		}
		else
			count = 1;
		
		++i;
	}

	for (int i = 0; i < n; ++i)
		sd += 1.0*(d[i] - mean)*(d[i] - mean);
	
	sd /= n;
	sd = sqrt(sd);

	lower_boundary = 1.96 * sd / sqrt(n);
	upper_boundary = mean + lower_boundary;
	lower_boundary = mean - lower_boundary;

	printf("%.1f\n%.1f\n%d\n%.1f\n%.1f %.1f\n",mean,median,mode,sd,lower_boundary,upper_boundary);

    return 0;
}

