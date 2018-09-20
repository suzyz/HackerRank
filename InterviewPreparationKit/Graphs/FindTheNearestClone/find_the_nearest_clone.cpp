// O(N^2) yet got AC. I guess the test cases are quite weak..
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 1000002;

int n, m, ans, targetColor, color[maxn], dist[maxn];

int head[maxn];
struct edge
{
    int u, v, next;

    edge(int a, int b, int c) {
        u = a;
        v = b;
        next = c;
    }
};
vector<edge> edges;

void addEdge(int a, int b) {
    edge e(a, b, head[a]);
    head[a] = edges.size();

    edges.push_back(e);
}

void bfs(int s) {

    memset(dist, -1, sizeof(dist));
    dist[s] = 0;

    queue<int> qu;
    qu.push(s);

    while (!qu.empty()) {
        int cur = qu.front();
        qu.pop();

        for (int i = head[cur]; i != -1; i = edges[i].next) {
            int v = edges[i].v;

            if (dist[v] == -1 || dist[v] > dist[cur]+1) {
                dist[v] = dist[cur]+1;

                qu.push(v);
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);

    memset(head, -1, sizeof(head));

    cin >> n >> m;

    int u, v;
    for (int i = 0; i < m; ++i){
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }

    for (int i = 1; i <= n; ++i)
        cin >> color[i];

    cin >> targetColor;

    vector<int> targetGroup;
    for (int i = 1; i <= n; ++i)
        if (color[i] == targetColor) {
            targetGroup.push_back(i);
        }

    if (targetGroup.size() < 2) {
        cout << -1 << endl;
        return 0;
    }

    ans = n-1;

    for (int i = 0; i < targetGroup.size(); ++i) {
        bfs(targetGroup[i]);

        for (int j = 0; j < targetGroup.size(); ++j) {
            int k = targetGroup[j];
            if (dist[k] > 0 && dist[k] < ans)
                ans = dist[k];
        }
    }

    cout << ans << endl;

    return 0;
}
