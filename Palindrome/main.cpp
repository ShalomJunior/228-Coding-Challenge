#include <bits/stdc++.h>
using namespace std;

string checker(string s, vector<int> starts, vector<int> ends, vector<int>subs) {
    const int N = 26;
    int n = s.size();
    int q = subs.size();
    vector<vector<int>> pre(n, vector<int>(N));
    for (int i = 0; i < n; i++) {
        if (i)pre[i] = pre[i - 1];
        pre[i][s[i] - 'a']++;
    }
    string ans;
    for (int i = 0; i < q; i++) {
        int l = starts[i];
        int r = ends[i];
        int odds = 0;
        for (int j = 0; j < N; j++) {
            int cnt = pre[r][j] - (l == 0 ? 0 : pre[l - 1][j]);
            if (cnt & 1)odds++;
        }
        int need = odds / 2;
        ans += need > subs[i] ? "0" : "1";
    }
    return ans;
}

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> starts(q), ends(q), subs(q);
    for (auto& c : starts)cin >> c;
    for (auto& c : ends)cin >> c;
    for (auto& c : subs)cin >> c;
    cout << checker(s, starts, ends, subs) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}