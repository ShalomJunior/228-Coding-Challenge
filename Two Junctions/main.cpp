#include<bits/stdc++.h>
using namespace std;

//This function is the most close to the one provided by the plateform hackerrank during the challenge
int checker(int n, vector<int> from, vector<int> to, vector<int> w, int x, int y) {
    const int INF = 2e9;
    int m = from.size();
    // Store the edges as an adjacency list to perform the djikstra algorithm later.
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        adj[from[i] - 1].push_back({ to[i] - 1, w[i] });
        adj[to[i] - 1].push_back({ from[i] - 1, w[i] });
    }
    // Note that all node are reconverted to 0 based instead of 1 based in the statement 
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
    // Running the djikstra algorithm from the 3 differents starting points
    // Each of this vector contains the minimum cost or weight to reach a certain node staring from a specific node
    vector<int> a(n, INF), b(n, INF), c(n, INF);
    bfs(0, a);
    bfs(x, b);
    bfs(y, c);
    /*
    a[x] is the smallest cost to reach x starting from the initial point (0)
    b[y] is the smallest cost to reach y starting from the x
    c[n - 1] is the smallest cost to reach n - 1 starting from y
    Now we just need to sum all those values
    */
    return a[x] + b[y] + c[n - 1];
}

// Input reading ...
// Custom as you want
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