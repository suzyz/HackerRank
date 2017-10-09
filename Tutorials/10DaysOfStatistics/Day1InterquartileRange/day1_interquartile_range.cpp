#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
#include <iomanip>
using namespace std;

int n,d[1010];

struct Num
{
	int x,freq;
} data[60];


double get_median(int st,int en)
{
	int len = en - st + 1;

	if (len&1)
		return 1.0 * d[st + (len-1)/2];
	else
		return 0.5 * (d[st + len/2 - 1] + d[st + len/2]);
}

bool cmp(const Num &a,const Num &b)
{
	if (a.x < b.x)
		return true;
	if (a.x > b.x)
		return false;
	return (a.freq < b.freq);
}

void unfold()
{
	int idx = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < data[i].freq; ++j)
			d[idx++] = data[i].x;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> data[i].x;

	int sum_f = 0;
	for (int i = 0; i < n; ++i)
	{
	 	cin >> data[i].freq;
	 	sum_f += data[i].freq;
	}

	sort(data,data+n,cmp);

	unfold();

	double q1 = get_median(0,sum_f/2 - 1);
	double q3 = get_median((sum_f+1)/2,sum_f - 1);

	cout << std::fixed << std::setprecision(1) << q3 - q1 << endl;
	
	return 0;
}