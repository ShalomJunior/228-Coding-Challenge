#include<bits/stdc++.h>
using namespace std;

int checker(int n, vector<int> from, vector<int> to, vector<int> w, int x, int y) {
    const int INF = 2e9;
    int m = from.size();
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        adj[from[i] - 1].push_back({ to[i] - 1, w[i] });
        adj[to[i] - 1].push_back({ from[i] - 1, w[i] });
    }
    --x, --y;
    auto bfs = [&](int root, vector<int>& dis) {
        vector<bool> vis(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({ 0, root });
        dis[root] = 0;
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (vis[u])continue;
            vis[u] = true;
            for (auto& [v, cost] : adj[u]) {
                if (dis[u] + cost < dis[v]) {
                    dis[v] = dis[u] + cost;
                    pq.push({ dis[v], v });
                }
            }
        }
        };
    vector<int> a(n, INF), b(n, INF), c(n, INF);
    bfs(0, a);
    bfs(x, b);
    bfs(y, c);
    return a[x] + b[y] + c[n - 1];
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> from(m), to(m), w(m);
    for (int i = 0; i < m; i++) {
        cin >> from[i] >> to[i] >> w[i];
    }
    int x, y;
    cin >> x >> y;
    cout << checker(n, from, to, w, x, y) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}