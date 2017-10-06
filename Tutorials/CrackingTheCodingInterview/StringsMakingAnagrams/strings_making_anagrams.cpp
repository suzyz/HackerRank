#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
const int maxlen = 10010;

string s,t;
int s_count[26];

int main()
{
	cin >> s >> t;
	for (int i = 0; i < s.length(); ++i)
		++s_count[s[i]-'a'];
	for (int i = 0; i < t.length(); ++i)
		--s_count[t[i]-'a'];

	int res = 0;
	for (int i = 0; i < 26; ++i)
		res += abs(s_count[i]);
	cout << res << endl;

	return 0;
}