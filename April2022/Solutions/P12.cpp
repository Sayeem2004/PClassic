// Solved by Maxwell Zen
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double dbl;
typedef array<dbl, 3> pt;
typedef array<array<dbl, 4>, 3> mat;

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
string s;
array<pt, 4> pts;

void print(mat m) {
    F0R(i, 3) {
        F0R(j, 4) cout << m[i][j] << ' ';
        cout << '\n';
    }
}

array<dbl, 4> geteq(int i1, int i2, int i3, int i4) {
    pt a=pts[i1], b=pts[i2], c=pts[i3], d=pts[i4];
    array<dbl, 4> eq;
    F0R(i, 3) eq[i] = b[i]-a[i];
    eq[3] = 0;
    F0R(i, 3) eq[3] += eq[i] * (d[i]+c[i])/2.0;
    return eq;
}

mat swap(mat m, int a, int b) {
    F0R(i, 4) swap(m[a][i], m[b][i]);
    return m;
}

mat add(mat m, int a, dbl x, int b) {
    F0R(i, 4) m[b][i] += m[a][i]*x;
    return m;
}

mat mult(mat m, int a, dbl x) {
    F0R(i, 4) m[a][i] *= x;
    return m;
}

mat rref(mat m) {
    F0R(i, 3) {
        int s = i;
        while (s<3 && m[s][i]==0) s++;
        m = swap(m, i, s);
        m = mult(m, i, 1.0 / m[i][i]);
        F0R(j, 3) if (i != j) m = add(m, i, -m[j][i], j);
    }
    return m;
}

void solve() {
    F0R(i, 4) F0R(j, 3) {
        cin >> s;
        pts[i][j] = stold(s);
    }
    mat m;
    m[0] = geteq(0, 1, 2, 3);
    m[1] = geteq(0, 2, 1, 3);
    m[2] = geteq(0, 3, 1, 2);
    // print(m);
    m = rref(m);
    cout << m[0][3]  << ' ' << m[1][3] << ' ' << m[2][3] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(1);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
