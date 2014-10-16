#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(u) begin(u),end(u)
#define uniq(u) (u).erase(unique(all(u)),end(u))

#define ll long
#define long int64_t
#define mp make_pair
#define pb push_back
#define eb emplace_back

struct disjoint_set
{
    const int n;
    vector<int> p, r;
    disjoint_set(int n) : n(n), p(n, -1), r(n, 0) {}
    int root(int i) { return p[i] >= 0 ? p[i] = root(p[i]) : i; }
    void merge(int i, int j) {
        i = root(i), j = root(j);
        if (i != j) {
            if (r[i] < r[j]) swap(i, j);
            p[i] += p[j], p[j] = i;
            r[i] += r[i] == r[j];
        }
    }
    bool same(int i, int j) { return root(i) == root(j); }
    int size(int i) { return -p[root(i)]; }
};

struct edge
{
    int a, b, w;
    edge(int a, int b, int w) : a(a), b(b), w(w) {}
    bool operator >(const edge& t) const {
        return w > t.w;
    }
};

int n, m;

void solve()
{
    cin >> n >> m;
    vector<edge> E;
    rep(i, m) {
        int u, v, k;
        cin >> u >> v >> k;
        E.eb(u - 1, v - 1, k);
    }
    sort(all(E), greater<edge>());

    disjoint_set uf(n);
    vector<int> tmp;
    long ans = 0;
    rep(i, m) {
        const edge& e = E[i];
        if (not uf.same(e.a, e.b)) {
            uf.merge(e.a, e.b);
            tmp.pb(e.a);
        }
        if (i == m - 1 or E[i].w > E[i + 1].w) {
            vector<int> roots;
            for (const int j : tmp) {
                roots.pb(uf.root(j));
            }
            sort(all(roots));
            uniq(roots);
            for (const int r : roots) {
                cerr << uf.size(r) << ' ';
                ans += uf.size(r);
            }
            tmp.clear();
        }
    }
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
