// f[i][1]: 自i向下（包括i），能且仅能连接1个机器所要付出的最小代价
// f[i][0]: 自i向下（包括i），连接不到机器所要付出的最小代价
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>

using namespace std;

const int maxn = 100002;

int n, m, f[maxn][2];
vector<pair<int,int>> g[maxn];

bool isMachine[maxn];

void dfs(int cur, int fa) {

	if (isMachine[cur])
		f[cur][0] = INT_MAX;

	int sum = 0;

	for (int i = 0; i < g[cur].size(); ++i) {
		int v = g[cur][i].first;
		if (v == fa) 
			continue;

		int w = g[cur][i].second;

		dfs(v, cur);

		int tmp = min(f[v][0], f[v][1] + w);

		if (!isMachine[cur]) {
			f[cur][0] += tmp;
		}

		sum += tmp;
	}

	f[cur][1] = sum;

	if (!isMachine[cur])
		for (int i = 0; i < g[cur].size(); ++i) {
			int v = g[cur][i].first;
			if (v == fa) 
				continue;

			int w = g[cur][i].second;

			int tmp = sum - min(f[v][0], f[v][1] + w) + f[v][1];
			if (tmp < f[cur][1])
				f[cur][1] = tmp;
		}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	int u, v, w;
	for (int i = 0; i < n-1; ++i) {
		cin >> u >> v >> w;
		g[u].push_back(make_pair(v, w));
		g[v].push_back(make_pair(u, w));
	}

	for (int i = 0; i < m; ++i) {
		cin >> u;
		isMachine[u] = true;
	}

	dfs(0, -1);

	int ans = f[0][1];
	if (!isMachine[0])
		if (f[0][0] < ans)
			ans = f[0][0];

	cout << ans << endl;

	return 0;
}