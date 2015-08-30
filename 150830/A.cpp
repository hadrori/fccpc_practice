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
const int MAX = 128;

struct union_find
{
    int rnk[MAX], par[MAX];

    union_find(int n){ for(int i = 0; i < n; i++) rnk[i] = 1, par[i] = i;}

    int find(int x){
        if(x == par[x]) return x;
        else return par[x] = find(par[x]);
    }
    void unite(int x, int y){
        x = find(x); y = find(y);
        if(x == y) return;
        if(rnk[x] > rnk[y]) par[y] = x;
        else{
            par[x] = y;
            if(rnk[x] == rnk[y]) rnk[y]++;
        }
    }
    bool same(int x, int y){
        x = find(x); y = find(y);
        return x == y;
    }
};
int n, k, a[128];

int solve()
{
    union_find uf(n);
    rep(i,n) rep(j,n) if(abs(a[i]-a[j]) <= k) uf.unite(i,j);
    set<int> s;
    rep(i,n) s.insert(uf.find(i));
    return s.size();
}

void input()
{
    cin >> n >> k;
    rep(i,n) cin >> a[i];
}

int main()
{
    int t; cin >> t;
    repi(i,1,t+1) {
        input();
        cout << "Case #" << i << ": " << solve() << endl;
    }
    return 0;
}
