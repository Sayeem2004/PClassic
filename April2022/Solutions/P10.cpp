// Solved by Maxwell Zen & Mohammad Khan
#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int n;
vector<int> A, T;
vector<vector<int>> R;
vector<bool> V1, V2;
int ans1, ans2;

void setvis(int n) {
    if (V1[n]) return;
    V1[n] = true;
    setvis(A[n]);
}

void dfs1(int n, int t) {
    if (T[n] != -1) return;
    T[n] = t;
    int x = A[n];
    if (V1[x]) return;
    if (T[x] != -1) {
        ans1 = max(ans1, t-T[x]+1);
    } else dfs1(x, t+1);
    return;
}

int dfs2(int n, int b) {
    if (V2[n]) return 0;
    V2[n] = true;
    int mx = 0;
    for (auto x : R[n]) {
        if (!V2[x] && x != b) {
            mx = max(mx, dfs2(x, b));
        }
    }
    return mx+1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        A.resize(n);
        R.clear(); R.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
            R[A[i]].push_back(i);
        }
        V1.assign(n, false); V2.assign(n, false);
        T.assign(n, -1);
        ans1 = ans2 = 0;
        for (int i = 0; i < n; i++) {
            if (!V1[i]) {
                dfs1(i, 0);
                setvis(i);
            }
            if (!V2[i] && i == A[A[i]]) ans2 += dfs2(i, A[i]);
        }
        cout << max(ans1, ans2) << "\n";
    }
}
