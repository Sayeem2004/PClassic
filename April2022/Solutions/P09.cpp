// Solved by Maxwell Zen
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

#ifndef LOCAL
#define debug(...) 0
#else
#include "/Users/maxwellzen/CP/debug.cpp"
#endif

int n;
vector<ll> a;

void solve() {
    cin >> n;
    a.resize(n);
    F0R(i, n) cin >> a[i];
    set<ll> s;
    vector<ll> diff(n);
    F0R(i, n) {
        diff[i] = 1e18;
        auto it = s.upper_bound(a[i]);
        if (it != s.end()) {
            diff[i] = min(diff[i], *it-a[i]);
        }
        if (it != s.begin()) {
            it--;
            diff[i] = min(diff[i], a[i] - *it);
        }
        s.insert(a[i]);
    }
    // debug(diff);
    ll mn = a[n-1], mx = a[n-1];
    // R0F(i, n) {
    ROF(i, 1, n-1) {
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
        ll cdiff = max(abs(a[i]-mn), abs(a[i]-mx));
        // debug(i, a[i], mn, mx, cdiff, diff[i]);
        if (diff[i] <= cdiff) {
            cout << 0 << '\n';
            return;
        }
    }
    cout << 1 << '\n';
    return;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
