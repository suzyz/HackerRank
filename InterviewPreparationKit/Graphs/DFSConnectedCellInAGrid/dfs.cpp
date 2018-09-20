#include <iostream>
#include <vector>

using namespace std;

const int maxn = 12;
const int dir[][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int n, m, ans, grid[maxn][maxn];
bool vis[maxn][maxn];

int dfs(int x, int y) {
	vis[x][y] = true;

	int count = 1;

	for (int i = 0; i < 8; ++i) {
		int tx = x + dir[i][0];
		if (tx < 0 || tx >= n)
			continue;

		int ty = y + dir[i][1];
		if (ty < 0 || ty >= m || vis[tx][ty] || grid[tx][ty] == 0)
			continue;

		count += dfs(tx, ty);
	}

	return count;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> grid[i][j];


	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (grid[i][j] && !vis[i][j]) {
				int count = dfs(i, j);

				if (count > ans)
					ans = count;	
			}

	cout << ans << endl;

	return 0;
}