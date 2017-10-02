#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class Trie
{
public:
	int count;
	Trie *p[26];

	Trie()
	{
		count = 0;
		memset(p,0,sizeof(p));
	}
	~Trie();
	
	void add(string name);
	int find(string prefix);
};

void Trie::add(string name)
{
	Trie *ch = this;
	for (int i = 0; i < name.length(); ++i)
	{
		if (ch->p[name[i]] == NULL)
			ch->p[name[i]] = new Trie;

		ch = ch->p[name[i]];
		++ ch->count;
	}
}

int Trie::find(string prefix)
{
	Trie *ch = this;
	for (int i = 0; i < prefix.length(); ++i)
	{
		if (ch->p[prefix[i]] == NULL)
			return 0;
		ch = ch->p[prefix[i]];
	}
	if (ch == NULL)
		return 0;
	return ch->count;
}

int main()
{
	int n;
	Trie *trie = new Trie;

	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		string operation,name;
		cin>>operation>>name;

		for (int j = 0; j < name.length(); ++j)
			name[j] -= 'a';

		if (operation=="add")
			trie->add(name);
		else
		{
			int ans = trie->find(name);
			cout<<ans<<endl;
		}
	}
	return 0;
}