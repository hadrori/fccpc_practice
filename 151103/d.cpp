#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
#define all(u) begin(u),end(u)
#define pb push_back
#define mp make_pair

const int N = 20010;

int n, a[N], p[N];

void input() {
    cin >> n;
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> p[i], --p[i];
}

int in[N], g[N];
set<int> grundy[N];

void solve() {
    fill_n(in, n, 0);
    fill_n(g, n, 0);
    rep(i, n) grundy[i].clear();
    repi(i, 1, n) ++in[p[i]];
    queue<int> que;
    rep(i, n) if (in[i] == 0) que.push(i);
    while (not que.empty()) {
        int v = que.front(); que.pop();
        for (int i = 0; ; ++i) {
            if (grundy[v].find(i) == grundy[v].end()) {
                g[v] = i; break;
            }
        }
        if (p[v] >= 0) {
            grundy[p[v]].insert(g[v]);
            if (--in[p[v]] == 0) {
                que.push(p[v]);
            }
        }
    }
    int ans = 0;
    rep(i, n) if (a[i] & 1) {
        ans ^= g[i];
    }
    cout << (ans ? "first" : "second") << endl;
}

int main() {
    cout << fixed << setprecision(12);
    int t; cin >> t;
    rep(i,t) {
        cout << "Case #" << i+1 << ": ";
        input();
        solve();
    }
    return 0;
}
