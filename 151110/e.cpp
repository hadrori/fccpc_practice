#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
#define pb push_back
#define all(u) begin(u),end(u)
#define mp make_pair
#define long int64_t

typedef vector<vector<int>> graph;

#define EVEN(x) (mu[x] == x || (mu[x] != x && phi[mu[x]] != mu[x]))
#define ODD(x) (mu[x] != x && phi[mu[x]] == mu[x] && phi[x] != x)
#define OUTER(x) (mu[x] != x && phi[mu[x]] == mu[x] && phi[x] == x)
int maximum_matching(const graph &g, vector<pair<int,int>> &matching) {
    int n = g.size();
    vector<int> mu(n), phi(n), rho(n), scanned(n);
    rep(v,n) mu[v] = phi[v] = rho[v] = v;
    for(int x = -1;;) {
        if(x < 0) {
            for(x = 0; x < n && (scanned[x] || !EVEN(x)); ++x);
            if(x == n) break;
        }
        int y = -1;
        for(auto &e: g[x]) if(OUTER(e) || (EVEN(e) && rho[e] != rho[x]))  y = e;
        if(y == -1) scanned[x] = true, x = -1;
        else if(OUTER(y)) phi[y] = x;
        else {
            vector<int> dx(n,-2), dy(n,-2);
            for(int k = 0, w = x; dx[w] < 0; w = k%2 ? mu[w] : phi[w]) dx[w] = k++;
            for(int k = 0, w = y; dy[w] < 0; w = k%2 ? mu[w] : phi[w]) dy[w] = k++;
            bool vertex_disjoint = true;
            rep(v,n) if(dx[v] >= 0 && dy[v] > 0) vertex_disjoint = false;
            if(vertex_disjoint) {
                rep(v,n) if(dx[v] % 2 or dy[v] % 2) mu[phi[v]] = v, mu[v] = phi[v];
                mu[x] = y; mu[y] = x; x = -1;
                rep(v,n) phi[v] = rho[v] = v, scanned[v] = false;
            }
            else {
                int r = x , d = n;
                rep(v,n) if(dx[v] >= 0 && dy[v] >= 0 && rho[v] == v && d > dx[v]) d = dx[v], r = v;
                rep(v,n) if((dx[v] <= d && dx[v] % 2 && rho[phi[v]] != r) || (dy[v] <= d && dy[v] % 2 && rho[phi[v]] != r)) phi[phi[v]] = v;
                if(rho[x] != r) phi[x] = y;
                if(rho[y] != r) phi[y] = x;
                rep(v,n) if(dx[rho[v]] >= 0 || dy[rho[v]] >= 0) rho[v] = r;
            }
        }
    }
    matching.clear();
    rep(u,n) if(u < mu[u]) matching.push_back(make_pair(u,mu[u]));
    return matching.size();
}

const int N = 512;

int n, m, a[N];
set<int> bs;

void input() {
    cin >> n >> m;
    rep(i, n) cin >> a[i];
    bs.clear();
    rep(i, m) {
        int b;
        cin >> b;
        bs.insert(b);
    }
}

void solve() {
    vector<vector<int>> G(n);
    rep(i, n) repi(j, i+1, n) {
        if (bs.find(a[i] + a[j]) != bs.end()) {
            G[i].push_back(j);
            G[j].push_back(i);
        }
    }
    vector<pair<int, int>> dum;
    cout << maximum_matching(G, dum) << endl; 
}

int main() {
    cin.tie(0);
    int _; cin >> _;
    while(_--) {
        input();
        solve();
    }
    return 0;
}
