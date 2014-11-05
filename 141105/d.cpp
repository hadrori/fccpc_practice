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

int N, M, K;

struct edge {
    int a, b, c;
    bool operator<(const edge &o) const {
        return c < o.c;
    }
};
vector<edge> E;
void input()
{
    cin >> N >> M >> K;
    vector<int> v(K);
    rep(i, K) cin >> v[i];
    E.clear();
    rep(i, M) {
        int a, b, c;
        cin >> a >> b >> c; a--; b--;
        E.pb((edge){a, b, c});
    }
    rep(i, K-1) E.pb((edge){v[i]-1, v[i+1]-1, 0});
}

struct UnionFind {
    vector<int> par, rnk;
    UnionFind(int n) {
        par = vector<int>(n);
        rep(i, n) par[i] = i;
        rnk = vector<int>(n, 0);
    }

    int find(int x) {
        if(par[x] == x) return x;
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

void solve()
{
    UnionFind uf(N);
    sort(all(E));
    
    int ans = 0;
    rep(i, E.size()) if(!uf.same(E[i].a, E[i].b)){
        uf.unite(E[i].a, E[i].b);
        ans += E[i].c;
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    rep(i, t) {
        input();
        cout << "Case #" << i + 1 << ": ";
        solve();
    }

    return 0;
}
