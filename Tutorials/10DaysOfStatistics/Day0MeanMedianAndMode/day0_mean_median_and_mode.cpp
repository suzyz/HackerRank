#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
#include <iomanip>
using namespace std;

int n,d[2600];

int main()
{
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> d[i];
		sum += d[i];
	}
	sort(d,d+n);
	double mean = 1.0 * sum / n;
	double median;
	if (n&1)
		median = d[n/2];
	else
		median = 0.5 * (d[n/2 - 1] + d[n/2]);

	int mode = d[0], max_count = 1, count = 1;
	for (int i = 1; i < n; ++i)
	{
		if (d[i] == d[i-1])
		{
			++count;
			if (count > max_count)
			{
				max_count = count;
				mode = d[i];
			}
		}
		else
			count = 1;
	}

	cout << std::fixed << std::setprecision(1) << mean << endl << median << endl << mode << endl;
	return 0;
}