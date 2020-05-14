#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 1002;

int n, m, dist[maxn];
vector<vector<int>> g;

void bfs(int s) {

	memset(dist, -1, sizeof(dist));
	dist[s] = 0;

	queue<int> qu;
	qu.push(s);

	while (!qu.empty()) {
		int cur = qu.front();
		qu.pop();

		for (int i = 0; i < g[cur].size(); ++i) {
			int v = g[cur][i];

			if (dist[v] == -1) {
				dist[v] = dist[cur]+1;

				qu.push(v);
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);

	int q = 0;
	cin >> q;

	while (q > 0) {
		q--;

		cin >> n >> m;

		g = vector<vector<int>>(n+1);

		int u, v;
		for (int i = 0; i < m; ++i) {
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		int s;
		cin >> s;

		bfs(s);

		for (int i = 1; i <= n; ++i)
			if (i != s) {
				if (dist[i] == -1)
					cout << "-1 ";
				else
					cout << 6*dist[i] << " ";
			}

		cout << endl;
	}

	return 0;
}