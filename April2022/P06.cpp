// Solved by Alvin LI
#include <bits/stdc++.h>
using namespace std;

vector<int> lanternFestival(int n, vector<vector<int>> prefs)
{
    vector<int> nol = {-1};
    vector<set<int>> outdeg(n);
    vector<set<int>> indeg(n);

    for(auto& v : prefs) {
        outdeg[v[0]].insert(v[1]);
        indeg[v[1]].insert(v[0]);
    }
    for(auto& v : outdeg) {
        if (!(v.size() == 2 || v.size() == 0)) return nol;
    }
    vector<bool> vis(n);
    int rt = -1;
    for (int i = 0; i < n; i++) {
        if (indeg[i].size() == 0) rt = i;
    }
    if (rt == -1) return nol;
    vector<int> ans;
    queue<int> q;
    q.push(rt);
    vis[rt] = 1;
    while(q.size()) {
        int curr = q.front();
        q.pop();
        ans.push_back(curr);
        for(int i : outdeg[curr]) {
            if (vis[i]) {
                return nol;
            }
            vis[i] = 1;
            q.push(i);
        }
    }

    if (ans.size() != n) return nol;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n,p; cin >> n >> p;
        vector<vector<int>> prefs (p, vector<int> (2));
        for (int i = 0; i < p; i++) {
            cin >> prefs[i][0] >> prefs[i][1];
        }
        for (int i : lanternFestival(n, prefs)) {
            cout << i << '\n';
        }
    }
}
