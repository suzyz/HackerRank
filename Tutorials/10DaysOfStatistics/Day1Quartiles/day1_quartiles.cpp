#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
#include <iomanip>
using namespace std;

int n,d[60];

double get_median(int st,int en)
{
	int len = en - st + 1;

	if (len&1)
		return 1.0 * d[st + (len-1)/2];
	else
		return 0.5 * (d[st + len/2 - 1] + d[st + len/2]);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> d[i];

	sort(d,d+n);

	double q1 = get_median(0,n/2 - 1);
	double q2 = get_median(0,n - 1);
	double q3 = get_median((n+1)/2,n - 1);

	cout << std::fixed << std::setprecision(0) << q1 << endl << q2 << endl << q3 << endl;
	
	return 0;
}