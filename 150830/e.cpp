#include <bits/stdc++.h>
using namespace std;

#define repi(i,a,b) for(int i = (int)(a); i<(int)(b); ++i)
#define rep(i,n) repi(i,0,n)
#define all(u) begin(u),end(u)
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),end(u))

#define pb push_back
#define mp make_pair

typedef long long ll;

struct UnionFind {
    vector<int> ppar, rnk;
    UnionFind(int n) {
        ppar.assign(n, 0);
        rnk = vector<int>(n, 0);
        rep(i, n) ppar[i] = i;        
    }

    int find(int x) { 
        if(x == ppar[x]) return x;
        return ppar[x] = find(ppar[x]);
    }
                            
    bool same(int x, int y) {
        return find(x) == find(y); 
    }

    void unite(int x, int y) {
        if(x < 0 or y < 0) return;
        x = find(x);
        y = find(y);
        
        if(rnk[x] < rnk[y]) {
            ppar[x] = y;
        } else {
            if(rnk[x] == rnk[y])
                rnk[x]++;
            ppar[y] = x;
        }
    }
    
};

struct query {
    char type;
    int a, b;
    query() {}
    query(char type, int a, int b) : type(type), a(a), b(b) {}
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> par(n);
    // int root;
    rep(i, n) {
        cin >> par[i];
        par[i]--;
        // if(par[i] < 0) root = i;
    }

    vector<bool> erased(n, false);
    vector<bool> valid(q, true);
    
    vector<query> qs(q);
    rep(i, q) {
        char c;
        cin >> c;
        int a, b;
        cin >> a;
        if(c == 'Q') cin >> b;
        a--; b--;
        qs[i] = query(c, a, b);
    }

    rep(i, q) {
        if(qs[i].type == 'C') {
            if(erased[qs[i].a]) {
                valid[i] = false;                
            }
            erased[qs[i].a] = true;
        }
    }
    
    UnionFind uf(n);    
    rep(i, n) {        
        if(!erased[i]) {            
            uf.unite(i, par[i]);
            //cout << qs[i].a << " " << par[qs[i].a] << endl;
        }
    }

    vector<int> ans(q);
    for(int i = q-1; i >= 0; i--) {
        if(qs[i].type == 'Q') {
            if(uf.same(qs[i].a, qs[i].b)) ans[i] = 1;
            else ans[i] = 0;
        } else {
            if(valid[i]) {
                uf.unite(qs[i].a, par[qs[i].a]);
                //cout << qs[i].a << " " << par[qs[i].a] << endl;
            }
            ans[i] = -1;
        }
    }
    cout << endl;
    rep(i, q) {
        if(ans[i] == 0) cout << "NO" << endl;
        else if(ans[i] == 1) cout << "YES" << endl;
    }

}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ":";
        solve();
    }
    return 0;
}
