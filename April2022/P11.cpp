#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)

#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)

#ifndef LOCAL
#define debug(...) 0
#else
#include "/Users/maxwellzen/CP/debug.cpp"
#endif

int n, q, l, r;
vvi trees;
ll MOD = 1e9+7;
vector<array<ll, 3>> seg;
array<ll, 3> ident = {1, 1, 0};

ll modexp(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p&1) res = (res*a)%MOD;
        a = (a*a)%MOD;
        p >>= 1;
    }
    return res;
}

ll eval(vi tree) {
    int h = tree.size();
    ll leaves = 1;
    ll prev = 1;
    R0F(i, h-1) {
        leaves = (leaves*tree[i+1])%MOD;
        prev = (leaves * modexp(prev, tree[i+1]))%MOD;
    }
    return prev;
}
ll p_a(vi tree) {
    ll res = 1;
    int h = tree.size();
    F0R(i, h) res = (res*tree[i])%MOD;
    return res;
}
ll x_a(vi tree) {
    int h = tree.size();
    ll res = 0;
    ll prod = 1;
    FOR(i, 1, h-1) {
        prod = (prod * tree[i])%MOD;
        res = (res+prod)%MOD;
    }
    return res;
}
array<ll, 3> comb(array<ll, 3> a, array<ll, 3> b) {
    if (a==ident) return b;
    if (b==ident) return a;
    array<ll, 3> ans;
    ans[0] = a[0] * modexp(b[1], a[2]+1) % MOD * modexp(b[0], a[1]) % MOD;
    ans[1] = a[1] * b[1] % MOD;
    ans[2] = (a[2] + a[1]*(1 + b[2]) % MOD)%MOD;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    trees.resize(n);
    seg.resize(2*n);
    F0R(i, n) {
        int h; cin >> h;
        trees[i].resize(h);
        F0R(j, h) cin >> trees[i][j];
        seg[i+n] = {eval(trees[i]), p_a(trees[i]), x_a(trees[i])};
        // debug(seg[i+n]);
    }
    ROF(i, 1, n) seg[i] = comb(seg[2*i], seg[2*i+1]);
    F0R(query, q) {
        cin >> l >> r;
        l--; r--;
        // {
        //     vi tree;
        //     tree.push_back(1);
        //     FOR(i, l, r+1) {
        //         FOR(j, 1, trees[i].size()) {
        //             tree.push_back(trees[i][j]);
        //         }
        //     }
        //     cout << eval(tree) << '\n';
        // }
        array<ll, 3> lans = ident, rans = ident;
        l += n; r += n;
        while (l <= r) {
            if (l%2 != 0) {
                lans = comb(lans, seg[l]);
                l++;
            }
            if (r%2==0) {
                rans = comb(seg[r], rans);
                r--;
            }
            l /= 2; r /= 2;
        }
        array<ll, 3> ans = comb(lans, rans);
        // debug(ans);
        cout << ans[0] << '\n';
    }
}
