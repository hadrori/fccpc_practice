#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
#define all(u) begin(u),end(u)
#define pb push_back
#define mp make_pair

long n, m;
vector<pair<int,int> > E;
vector<set<int> > G;

void input() {
    cin >> n >> m;
    E.clear();
    G.assign(n, set<int>());
    rep(i, m) {
        int u, v;
        cin >> u >> v, --u, --v;
        E.emplace_back(u, v);
        G[u].insert(v);
        G[v].insert(u);
    }
}

void solve() {
    long ans = n * (n-1) * (n-2) / 6;
    ans -= m * (n-2);
    rep(i, n) {
        long d = G[i].size();
        ans += d * (d-1) / 2;
    }
    long delta = 0;
    for (auto& e : E) {
        int u, v;
        tie(u, v) = e;
        if (G[u].size() > G[v].size()) swap(u, v);
        for (int w : G[u]) {
            if (G[v].find(w) != G[v].end()) ++delta;
        }
    }
    ans -= delta / 3;
    cout << ans << endl;
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
