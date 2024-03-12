#include <bits/stdc++.h>
using namespace std;

string checker(int x1, int y1, int x2, int y2) {
    const int N = 1005;
    vector<vector<bool>> vis(N, vector<bool>(N));
    function<void(int, int)> go = [&](int x, int y) {
        vis[x][y] = true;
        if (x + y >= N) return;
        /*
            We check first if the next coordinate are not already visited.
            If they are not then we try them until there is no more to try
            It is guurenteed that the recursion will end at a certen point since the maximum number
            of point we will check is bounded by 1e6
        */
        if (!vis[x + y][y])go(x + y, y);
        if (!vis[x][y + x])go(x, y + x);
        };
    go(x1, y1);
    return vis[x2][y2] ? "YES" : "NO";
}

// Input reading
// Customize as you want
void solve() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << checker(x1, y1, x2, y2) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}