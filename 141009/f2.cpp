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

//
int n, m;
vector<vector<pair<int, int> > > E;
void input()
{
    cin >> n >> m;
    vector<pair<int, pair<int, int> > > v;
    rep(i, m) {
        int a, b, k;
        cin >> a >> b >> k; a--, b--;
        v.pb(mp(k, mp(a, b)));
    }

    sort(v.rbegin(), v.rend());
    int bfr = -1;

    E.clear();
    vector<pair<int, int> > tmp;
    rep(i, v.size()) {
        if(bfr != v[i].first) {
            E.pb(tmp);
            tmp.clear();
        }
        tmp.pb(v[i].second);
        bfr = v[i].first;
    }
    if(tmp.size()) E.pb(tmp);
}

struct UnionFind {
    vector<int> par, rnk, num;
    UnionFind() {}
    UnionFind(int n) {
        par = vector<int>(n);
        rep(i, n) par[i] = i;
        rnk = vector<int>(n, 0);
        num = vector<int>(n, 1);
    }

    int find(int x) {
        if(x == par[x]) return x;
        return par[x] = find(par[x]);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    void unite(int x, int y) {
        x = find(x), y = find(y);
        int tnum = num[x] + num[y];
        if(x == y) return;
        if(rnk[x] < rnk[y]) par[x] = y;
        else {
            if(rnk[x] == rnk[y]) rnk[x]++;
            par[y] = x;
        }
        x = find(x);
        num[x] = tnum;
    }
};

void solve()
{
    ll ans = 0;
    UnionFind uf(n);
    rep(i, E.size()) {
        vector<int> tmp;
        rep(j, E[i].size()) {
            int u = E[i][j].first, v = E[i][j].second;
            if(!uf.same(u, v)) {
                uf.unite(u, v);
                //cout << "unite " << u << " " << v << endl;
                tmp.pb(uf.find(u));
            }
        }
        rep(j, tmp.size()) tmp[j] = uf.find(tmp[j]);
        sort(all(tmp));
        uniq(tmp);
        rep(j, tmp.size()) {
            int df = uf.num[tmp[j]];
            //cout << tmp[j] << " " << df << endl;
            ans += df;
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
        input();
        solve();
    }

    return 0;
}
