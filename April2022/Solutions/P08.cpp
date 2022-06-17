#include <bits/stdc++.h>
using namespace std;


vector<string> tubeAdventures(int n, int m, int q, vector<string> islands, vector<int> queries) {
    int mxd = max(n,m);
    int req = 0;
    int diags = 0;
    vector<int> lens;

    for (int r = n-1; r >= n-(n+m-1); --r) {
        int c = 0, cc = c, rr = r;
        int cnt = 0, xcnt = 0;
        if (r < 0) {
            cc = -1 * r;
            rr = 0;
        }

        while (rr < n && cc < m) {
            //cout << rr << ' ' << cc << '\n';
            ++cnt;
            if (islands[rr][cc] == 'x') ++xcnt;
            ++rr; ++cc;
        }
        if (xcnt == 0) {
            lens.push_back(cnt);
        } else {
            ++diags;
            req += cnt - xcnt;
        }
    }

    vector<vector<bool>> dp(2, vector<bool>(n*m + 1));

    dp[0][0] = 1;
    for (auto l : lens) {
        for (int i = n*m; i >= 0; i--) {
            if (i + l <= n*m) {
                dp[0][i+l] = dp[1][i] || dp[0][i+l];
                dp[1][i+l] = dp[0][i] || dp[1][i+l];
            }
        }
    }

    vector<string> ans;
    ans.reserve(q);

    for (int q : queries) {
        if(q < req){
            ans.push_back("NO");
            continue;
        }
        q -= req;
        if (diags & 1) {
            if (dp[1][q]) ans.push_back("YES");
            else ans.push_back("NO");
        } else {
            if (dp[0][q]) ans.push_back("YES");
            else ans.push_back("NO");
        }
        // diags is the current number of diagonals filled
        // if it is even, you need an even number of things in the vector lens to sum to q
        // otherwise, you need an odd number of things in lens to sum to q
        // each number in lens can be used exactly once
    }


    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;

        vector<string> islands(n);
        for(int i = 0; i < n; i++) cin >> islands[i];
        vector<int> queries(q);
        for(int i = 0; i < q; i++) cin >> queries[i];

        vector<string> output = tubeAdventures(n, m, q, islands, queries);
        for(string s : output) {
            cout << s << '\n';
        }
    }
}
