#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

stack<int> st;

int main()
{
	int n,type,cur;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> type;
		switch (type)
		{
			case 1:
				cin >> cur;
				if (st.size())
					cur = max(cur,st.top());
				st.push(cur);
				break;
			case 2:
				st.pop();
				break;
			case 3:
				cout << st.top() << endl;
		}
	}

	return 0;
}
