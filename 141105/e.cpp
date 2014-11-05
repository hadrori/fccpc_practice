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

int N, K;
struct edge {
    int to, type;
};
vector<vector<edge> > E;
void input()
{
    cin >> N >> K;
    E.clear();
    E.resize(N);
    rep(i, K) {
        char ch;
        int a, b, c;
        cin >> ch >> a >> b >> c; a--; b--; c--;
        if(ch == 'F') {
            E[a].pb((edge){b, +1});
            E[a].pb((edge){c, -1});
        } else {
            E[a].pb((edge){c, -2});
            E[b].pb((edge){c, +2});
        }
    }
}

vector<int> ord;
vector<bool> done;
void topo(int now) {
    if(done[now]) return;
    done[now] = true;
    rep(i, E[now].size()) topo(E[now][i].to);
    ord.pb(now);
}

void solve()
{
    // topo sort
    ord.clear();
    done = vector<bool>(N, false);
    rep(i, N) if(!done[i]) {
        topo(i);
    }
    reverse(all(ord));
    
    // calc plus, minus
    vector<int> plus(N, N), minus(N, N+1);
    rep(i, N) {
        int now = ord[i];
        rep(j, E[now].size()) {
            int to = E[now][j].to;
            int type = E[now][j].type;
            if(type == -1) {
                minus[to] = now;
                plus[to] = plus[now];
            } else if(type == +1) {
                minus[to] = minus[now];
                plus[to] = now;
            } else if(type == -2) {
                minus[to] = minus[now];
            } else if(type == 2) {
                plus[to] = plus[now];
            }
        }
    }

    // recreate graph
    E.clear();
    E.resize(N+2);
    rep(i, N) E[plus[i]].pb((edge){minus[i], 0});

    // topo sort
    ord.clear();
    done = vector<bool>(N+2, false);
    rep(i, N+2) if(!done[i]) {
        topo(i);
    }
    reverse(all(ord));

    // calc longest path
    const int inf = 100000000;
    vector<int> dp(N+2, -inf);
    dp[ord[0]] = 0;
    rep(i, ord.size()) {
        int now = ord[i];
        rep(j, E[now].size()) dp[E[now][j].to] = max(dp[E[now][j].to], dp[now]+1);
    }
/*
    rep(i, N+2) {
        rep(j, E[i].size()) cout << i+1 << " to " << E[i][j].to+1 << endl;
    }

    rep(i, N+2) {
        cout << i+1 << " " << dp[i] << endl;
        }*/

    // calc answer
    int ans = 0;
    rep(i, N+2) ans = max(ans, dp[i]);
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
