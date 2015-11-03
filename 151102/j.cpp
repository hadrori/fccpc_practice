#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define repd(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define repit(it,u) for(auto it=begin(u);it!=end(u);++it)

#define all(u) begin(u),end(u)
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),end(u))

#define pb push_back
#define mp make_pair

typedef long long ll;

const int N = 100010;

int n, c[N];
vector<vector<int>> G;

struct disjoint_set {
    const int n;
    vector<int> p;
    disjoint_set(int n) : n(n), p(n, -1) {};
    int root(int i) { return p[i] >= 0 ? p[i] = root(p[i]) : i; }
    bool same(int i, int j) { return root(i) == root(j); }
    int size(int i) { return -p[root(i)]; }
    void merge(int i, int j) {
        i = root(i), j = root(j);
        if (i != j) {
            if (p[i] > p[j]) swap(i, j);
            p[i] += p[j], p[j] = i;
        }
    }
};

void solve()
{
    disjoint_set uf(n);
    rep(i, n) {
        sort(all(G[i]), [](int a, int b) { return c[a] < c[b]; });
    }
    vector<vector<int>> H(n);
    rep(i, n) {
        const int k = G[i].size();
        rep(j, k) {
            if (c[i] < c[G[i][j]]) {
                H[i].push_back(G[i][j]);
            } else if (c[i] == c[G[i][j]]) {
                uf.merge(i, G[i][j]);
            }
        }
        rep(j, k-1) {
            if (c[G[i][j]] < c[G[i][j+1]]) {
                H[G[i][j]].push_back(G[i][j+1]);
            } else if (c[G[i][j]] == c[G[i][j+1]]) {
                uf.merge(G[i][j], G[i][j+1]);
            }
        }
    }
    vector<int> in(n);
    rep(i, n) {
        for (int v : H[i]) ++in[uf.root(v)];
    }
    long ans = 0;
    vector<long> pred(n);
    vector<int> ved(n);
    queue<int> que;
    rep(i, n) {
        if (i == uf.root(i) and in[i] == 0) que.push(i);
    }
    vector<vector<int>> ch(n);
    rep(i, n) ch[uf.root(i)].push_back(i);
    while (not que.empty()) {
        int v = que.front(); que.pop();
        if (ved[v]) continue;
        ved[v] = 1;
        long t = pred[v] + 1;
        ans += t * uf.size(v);
        for (int vv : ch[v]) {
            for (int u : H[vv]) {
                u = uf.root(u);
                pred[u] = max(pred[u], t);
                if (--in[u] == 0) que.push(u);
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    cin >> n;
    rep(i, n) cin >> c[i];
    int m;
    cin >> m;
    G.assign(n, vector<int>());
    rep(_, m) {
        int a, b;
        cin >> a >> b, --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    solve();
    
    return 0;
}
