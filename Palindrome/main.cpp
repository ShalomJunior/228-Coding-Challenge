#include <bits/stdc++.h>
using namespace std;

// Closest function to the one asked to complete during the challenge
string checker(string s, vector<int> starts, vector<int> ends, vector<int>subs) {
    const int N = 26;
    int n = s.size();
    int q = subs.size();
    // Precomputing the prefix sum that will help for count of occurence in O(1) for each letter
    vector<vector<int>> pre(n, vector<int>(N));
    for (int i = 0; i < n; i++) {
        if (i)pre[i] = pre[i - 1];
        pre[i][s[i] - 'a']++;
    }
    string ans;
    // Working on each query
    for (int i = 0; i < q; i++) {
        int l = starts[i];
        int r = ends[i];
        int odds = 0;
        for (int j = 0; j < N; j++) {
            // You have the sum until l and until r.
            // To find how much we have in that interval just substract the total at r and the total at l - 1 if it is a valid index
            int cnt = pre[r][j] - (l == 0 ? 0 : pre[l - 1][j]);
            if (cnt & 1)odds++;
        }
        // The minimum number of susbstitution needed to make the string palindrome 
        int need = odds / 2;
        ans += need > subs[i] ? "0" : "1";
    }
    return ans;
}

// Input reading function.
// Customize as you want 
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