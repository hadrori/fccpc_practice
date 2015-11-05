#include <bits/stdc++.h>
using namespace std;
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repi(i,0,n)
#define all(u) begin(u),end(u)
#define pb push_back
#define mp make_pair
const int inf = 1e9;

int n, m, d[1024], s[1024];
vector<pair<int,int>> G[1024];
vector<pair<int,int>> rG[1024];

bool solve() {
    rep(i,n) d[i] = inf;
    d[0] = 0;
    vector<bool> inNeg(n, false);
    rep(_, 2*n) {
        rep(i,n) if(d[i] < inf) {
            for(auto &e: G[i]) {
                if (d[e.first] > d[i] + e.second) {
                    d[e.first] = d[i] + e.second;
                    if (_ > n) inNeg[e.first] = true;
                }
            }
        }
    }

    rep(i,n) d[i] = inf;
    d[0] = 0;
    rep(_, n) {
        rep(i,n) if(d[i] < inf) {
            for(auto &e: rG[i]) {
                if (d[e.first] > d[i] + e.second) {
                    d[e.first] = d[i] + e.second;
                }
            }
        }
    }    

    vector<bool> reachable(n, false);
    rep(i, n) if(d[i] < inf) reachable[i] = true;
    
    rep(i, n) if (reachable[i] && inNeg[i]) return true;
    return false;
    
}

void input() {
    cin >> n >> m;
    rep(i,n) G[i].clear();
    rep(i,n) rG[i].clear();
    int a, b, c;
    rep(i,m) {
        cin >> a >> b >> c;
        G[a].pb(mp(b,c));
        rG[b].pb(mp(a,c));
    }
}

int main() {
    cout << fixed << setprecision(12);
    int t; cin >> t;
    rep(i,t) {
        cout << "Case #" << i+1 << ": ";
        input();
        if(solve()) cout << "possible";
        else cout << "not possible";
        cout << endl;
    }
    return 0;
}
