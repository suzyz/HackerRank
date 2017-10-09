#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

int n,d[102];
double mean = 0, sd = 0;


int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> d[i];
		mean += d[i];
	}
	mean /= n;

	for (int i = 0; i < n; ++i)
		sd += (mean - d[i]) * (mean - d[i]);
	
	sd /= n;
	sd = sqrt(sd);

	cout << std::fixed << std::setprecision(1) << sd << endl;
	
	return 0;
}