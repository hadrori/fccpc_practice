#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
#define all(u) begin(u),end(u)
#define pb push_back
#define mp make_pair

struct disjoint_set {
    int n;
    vector<int> p;
    disjoint_set(int n) : n(n), p(n, -1) {}
    int root(int i) { return p[i] >= 0 ? p[i] = root(p[i]) : i; }
    void merge(int i, int j) {
        i = root(i), j = root(j);
        if (i != j) {
            if (p[i] > p[j]) swap(i, j);
            p[i] += p[j], p[j] = i;
        }
    }
    bool same(int i, int j) { return root(i) == root(j); }
};

struct edge {
    int u, v, w;
    edge(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator <(const edge& o) { return w > o.w; }
};

int n, m;
vector<edge> E;

void input() {
    cin >> n >> m;
    E.clear();
    rep(_, m) {
        int u, v, w;
        cin >> u >> v >> w, --u, --v;
        E.emplace_back(u, v, w);
    }
}

void solve() {
    sort(all(E));
    disjoint_set uf(n);
    long ans = 0, ans1 = 0;
    for (auto& e : E) {
        if (not uf.same(e.u, e.v)) {
            uf.merge(e.u, e.v);
        } else {
            ans += e.w;
            ans1 = max<long>(ans1, e.w);
        }
    }
    cout << ans << ' ' << ans1 << endl;
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
