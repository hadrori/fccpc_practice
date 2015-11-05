#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
#define all(u) begin(u),end(u)
#define pb push_back
#define mp make_pair

const int inf = 1e9;
struct edge {
    int to, cap, rev;
    edge(int to, int cap, int rev) : to(to), cap(cap), rev(rev) {}
};
typedef vector<vector<edge> > graph;

void add_edge(graph& G, int from, int to, int cap) {
    G[from].emplace_back(to, cap, G[to].size());
    G[to].emplace_back(from, 0, G[from].size() - 1);
}

struct maxflow {
    const int n;
    graph& G;
    vector<int> level, iter;
    void bfs(int s, int t) {
        level.assign(n, -1);
        queue<int> q;
        level[s] = 0, q.push(s);
        while (not q.empty()) {
            const int v = q.front(); q.pop();
            if (v == t) return;
            for (const auto& e : G[v]) {
                if (e.cap > 0 and level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
    }
    int dfs(int v, int t, int f = inf) {
        if (v == t) return f;
        for (int& i = iter[v]; i < int(G[v].size()); ++i) {
            edge& e = G[v][i];
            if (e.cap > 0 and level[v] < level[e.to]) {
                const int d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d, G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    maxflow(graph& G) : n(G.size()), G(G) {}
    int pour(int s, int t) {
        int ret = 0, d;
        while (bfs(s, t), level[t] >= 0) {
            iter.assign(n, 0);
            while ((d = dfs(s, t, inf)) > 0) ret += d;
        }
        return ret;
    }
};

const int N = 108;

int n, m;
char A[N][N];

void solve() {
    const int V = n + m + 2;
    const int s = V - 2;
    const int t = V - 1;
    graph G(V);
    rep(i, n) add_edge(G, s, i, 1);
    rep(i, n) rep(j, m) if (A[i][j] == '1') {
        add_edge(G, i, n + j, 1);
    }
    rep(j, m) add_edge(G, n + j, t, 1);
    cout << maxflow(G).pour(s, t) << endl;
}

void input() {
    cin >> n >> m;
    rep(i, n) cin >> A[i];
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
