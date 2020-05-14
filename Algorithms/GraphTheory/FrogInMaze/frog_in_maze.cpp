// 0: good cell
// 1: mine
// 2: wall
// 3: exit
// 4: tunnel

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int maxn = 22;
const int dir[][2] = {{1,0},{-1,0},{0,1},{0,-1}};

double ans = 0;
int n, m, grid[maxn][maxn];

struct point
{
	int x, y;
	point() {
	}

	point(int a, int b) {
		x = a;
		y = b;
	}
};

point tunnel[maxn][maxn];
vector<point> nexts[maxn][maxn];

int reachableMines = 0, reachableExits = 0;
bool vis[maxn][maxn];

void dfs(int x, int y, bool justThroughTunnel) {
	if (vis[x][y])
		return;

	vis[x][y] = true;

	if (grid[x][y] == 1) {
		reachableMines++;
		return;
	}

	if (grid[x][y] == 3) {
		reachableExits++;
		return;
	}

	if (grid[x][y] == 0 || (grid[x][y] == 4 && justThroughTunnel)) {

		for (vector<point>::iterator it = nexts[x][y].begin(); 
			it != nexts[x][y].end(); ++it) {
			
			dfs(it->x, it->y, false);
		}
	} else {
		// need to go through tunnel!

		dfs(tunnel[x][y].x, tunnel[x][y].y,  true);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);

	int sx, sy, k;
	string s;
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		cin >> s;

		for (int j = 0; j < m; ++j) {
			switch (s[j]) {
				case 'A':
					sx = i;
					sy = j;
					grid[i][j] = 0;
					break;
				case '0':
					grid[i][j] = 0;
					break;
				case '*':
					grid[i][j] = 1;
					break;
				case '#':
					grid[i][j] = 2;
					break;
				case '%':
					grid[i][j] = 3;
					break;
			}
		}
	}

	int a, b, c, d;
	for (int i = 0; i < k; ++i) {
		cin >> a >> b >> c >> d;
		--a; --b;
		--c; --d;

		grid[a][b] = grid[c][d] = 4;

		tunnel[a][b].x = c;
		tunnel[a][b].y = d;

		tunnel[c][d].x = a;
		tunnel[c][d].y = b;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] == 0 || grid[i][j] == 4) {
				for (int t = 0; t < 4; ++t) {
					int tx = i + dir[t][0];
					if (tx < 0 || tx >= n)
						continue;
					int ty = j + dir[t][1];
					if (ty < 0 || ty >= m || grid[tx][ty] == 2)
						continue;

					nexts[i][j].push_back(point(tx,ty));
				}
			}
		}
	}

	dfs(sx, sy, false);
	cout << 1.0*reachableExits/(reachableExits+reachableMines) << endl;

	return 0;
}