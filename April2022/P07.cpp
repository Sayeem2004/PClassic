#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n; cin >> n;
    vector<int> fun(n);
    vector<int> energy(n);
    for (int i = 0; i < n; i++) {
        cin >> fun[i] >> energy[i];
    }

    //0: not having used 2*
    //1: having used 2*
    vector<vector<int>> dp(n, vector<int>(2));

    for(int i = 0; i < n; i++) {
        dp[i][0] = fun[i];
        dp[i][1] = 2*fun[i];
    }

    for (int i = 0; i < n; i++) {
        if (i + energy[i] + 1 < n){
            int nxt = i + energy[i] + 1;
            dp[nxt][0] = max(dp[nxt][0], dp[i][0] + fun[nxt]); //dont use 2*
            dp[nxt][1] = max(dp[nxt][1], dp[i][0] + 2*fun[nxt]); //use 2* at nxt
            dp[nxt][1] = max(dp[nxt][1], dp[i][1] + fun[nxt]); //used 2* at or before i
        }
        if (i + 1 < n) {
            dp[i+1][0] = max(dp[i+1][0], dp[i][0]);
            dp[i+1][1] = max(dp[i+1][1], dp[i][1]);
        }
    }
    int mx = 0;

    for(int i = 0; i < n; i++) {
        mx = max(mx, dp[i][1]);
    }
    cout << mx << '\n';

}

signed main() {
    int t; cin >> t;
    while(t--){
        solve();
    }
}
