#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
#include <iomanip>
using namespace std;

int n,d[60];

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> d[i];

	double w,sum_w = 0, sum_d = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> w;
		sum_w += w;
		sum_d += w * d[i];
	}
	cout << std::fixed << std::setprecision(1) << sum_d/sum_w << endl;

	return 0;
}