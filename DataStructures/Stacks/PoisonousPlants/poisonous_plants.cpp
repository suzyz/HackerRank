#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

stack<int> st;

int main()
{
	int n,cur;
	cin >> n;
	
	int ans = 0;
	bool flag = false;
	for (int i = 0; i < n; ++i)
	{
		cin >> cur;
		int idx = i;
		while (!st.empty() && st.top()< cur)
		{
			flag = true;
			st.pop();
		}
		
		st.push(cur);
	}
	if (!flag)
		cout << 0 << endl;

	while (flag)
	{
		
	}

	cout << ans << endl;
	return 0;
}
