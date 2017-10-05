#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxlen = 10010;

char s[maxlen],t[maxlen];

int main()
{
	cin >> s >> t;
	int n = s.length(), m = t.length();

	int f[maxlen][maxlen];
	f[0][0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (s[i] == s[j])
				f[i][j] = min3(f[i-1][j-1],f[i][j-1] + 1, f[i-1][j] + 1);
			else
				f[i][j] = 
		}
	}
	return 0;
}