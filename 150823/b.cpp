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

struct edge {
    int a, b, c;
    edge(int a, int b, int c) : a(a), b(b), c(c) {}
    bool operator<(const edge &o) const {
        return c < o.c;
    }
};

struct UnionFind {
    vector<int> rnk, par;
    
    UnionFind(int n) {
        rnk = vector<int> (n, 0);
        par = vector<int> (n);
        rep(i, n) par[i] = i;
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
        if(x == y) return;
        if(rnk[x] < rnk[y]) {            
            par[x] = y;
        } else {
            if(rnk[x] == rnk[y]) rnk[x]++;
            par[y] = x;
        }
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<edge> E;
    int ans = 0;
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        E.pb(edge(a, b, c));
        ans += c;
        //cout << ans << endl;
    }

    UnionFind uf(n);
    sort(all(E));
    rep(i, E.size()) {
        if(!uf.same(E[i].a, E[i].b)) {
            uf.unite(E[i].a, E[i].b);
            ans -= E[i].c;
        }
    }
    
    cout << ans << endl;
}

int main()
{
    int T;
    cin >> T;
    rep(t, T) {
        solve();
    }
    return 0;
}
