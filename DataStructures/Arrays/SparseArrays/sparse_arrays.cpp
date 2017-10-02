#include <iostream>
#include <cstring>
#include <map>

using namespace std;

int main()
{
	map<string,int> freq;

	int n;
	string s;

	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>s;
		++ freq[s];
	}

	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>s;
		cout<<freq[s]<<endl;
	}

	return 0;
}