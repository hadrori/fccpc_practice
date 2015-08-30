#include <bits/stdc++.h>
using namespace std;

#define repi(i,a,b) for(int i = (int)(a); i<(int)(b); ++i)
#define rep(i,n) repi(i,0,n)
#define all(u) begin(u),end(u)
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),end(u))

#define pb push_back
#define eb emplace_back
#define mp make_pair

typedef long long ll;

typedef vector<vector<int> > graph;

class bridge {
    const int n;
    graph G;
    int cnt;
    vector<int> num, low, in;
    stack<int> stk;
    vector<pair<int, int> > brid;
    vector<vector<int> > comp;
    void dfs(int v, int p) {
        num[v] = low[v] = ++cnt;
        stk.push(v), in[v] = true;
        for (const int nv : G[v]) {
            if (num[nv] == 0) {
                dfs(nv, v);
                low[v] = min(low[v], low[nv]);
            } else if (nv != p and in[nv]) {
                low[v] = min(low[v], num[nv]);
            }
        }
        if (low[v] == num[v]) {
            if (p != n) brid.eb(min(v, p), max(v, p));
            comp.eb();
            int w;
            do {
                w = stk.top();
                stk.pop(), in[w] = false;
                comp.back().pb(w);
            } while (w != v);
        }
    }
public:
    bridge(const graph& G) : n(G.size()), G(G), cnt(0), num(n), low(n), in(n) {
        rep(i, n) if (num[i] == 0) dfs(i, n);
    }
    const vector<pair<int, int> > get() const {
        return brid;
    }
    const vector<vector<int> > components() const {
        return comp;
    }
};

const int N = 128;

int n, m, A[N][N];
graph G;

void input() 
{
    cin >> n >> m;
    rep(i, n) fill_n(A[i], n, 0);
    G.assign(n, vector<int>());
    rep(_, m) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        A[u][v] = A[v][u] = 1;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

bool is_complete(const vector<int>& S)
{
    const int k = S.size();
    rep(i, k) repi(j, i+1, k) {
        if (not A[S[i]][S[j]]) return false;
    }
    return true;
}

void solve()
{
    const auto B = bridge(G);
    const auto brids = B.get();
    const auto comps = B.components();
    vector<int> id(n);
    rep(i, int(comps.size())) {
        for (int v : comps[i]) {
            id[v] = i;
        }
    }
    int ans = 0;
    for (auto p : brids) {
        int u, v;
        tie(u, v) = p;
        if (comps[id[u]].size() != comps[id[v]].size()) continue;
        if (comps[id[u]].size() == 1) {
            if (G[u].size() != G[v].size()) continue;
            if (G[u].size() >= 3) continue;
            if (G[u].size() == 2) {
                if (G[G[u][0] ^ G[u][1] ^ v].size() != 1) continue;
                if (G[G[v][0] ^ G[v][1] ^ u].size() != 1) continue;
            }
        }
        if (is_complete(comps[id[u]]) and is_complete(comps[id[v]])) {
            ++ans;
        }
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        input();
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
