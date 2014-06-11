#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define repi(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
#define repit(i,a) for(__typeof((a).begin()) i=(a).begin();i!=(a).end();i++)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define UNIQUE(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair
#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)

using namespace std;

typedef long long ll;
typedef vector<int> vi;

struct uftree
{
    int n;
    vector<int> v;

    uftree(int size) : n(size), v(size, -1) {}
    int root(int i) { return v[i] >= 0 ? v[i] = root(v[i]) : i; }
    void unite(int i, int j) {
        i = root(i), j = root(j);
        if (i != j) {
            v[i] += v[j];
            v[j] = i;
        }
    }
    bool same(int i, int j) { return root(i) == root(j); }
    int size(int i) { return -v[root(i)]; }
};

const int N = 100010;

int n, m, a[N];
vector<vector<int> > G;

void input()
{
    cin >> n >> m;
    rep(i, n) cin >> a[i];

    G.assign(n, vector<int>());
    rep(i, m) {
        int u, v;
        cin >> u >> v, --u, --v;
        G[u].pb(v), G[v].pb(u);
    }
}

void solve()
{
    vector<pair<int, int> > vs;
    rep(i, n) vs.pb(mp(a[i], i));
    sort(rall(vs));

    vector<int> exists(n);

    ll ans = 0;

    uftree uf(n);
    rep(ii, n) {
        const int& i = vs[ii].second;
        exists[i] = true;

        ll s = 0;
        vector<int> v;
        rep(j, int(G[i].size())) {
            const int& ni = G[i][j];

            if (not exists[ni]) continue;
            if (not uf.same(i, ni)) {
                s += uf.size(ni);
                v.pb(uf.size(ni));
            }
            uf.unite(i, ni);
        }

        ll t = 2 * s;
        rep(j, int(v.size())) {
            t += (ll) (s - v[j]) * v[j];
        }
        ans += t * vs[ii].first;
    }

    printf("%.6f\n", (double) ans / n / (n - 1));
}

int main()
{
    input();
    solve();

    return 0;
}
