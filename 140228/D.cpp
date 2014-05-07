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

struct edge
{
    int to, w;
    edge(int to, int w) : to(to), w(w) {}
};

int n, m, k;
vector<vector<edge> > G;
vector<int> pass, at, t, ft;

void input()
{
    cin >> n >> m >> k;
    G.assign(n, vector<edge>());
    rep(i, m) {
        int a, b, d;
        cin >> a >> b >> d;
        --a, --b;
        G[a].pb(edge(b, d));
        G[b].pb(edge(a, d));
    }
    pass.assign(n, 0);
    at.assign(n, 0);
    t.resize(k);
    ft.resize(k);
    rep(i, k) {
        int p, k;
        cin >> p >> t[i] >> ft[i] >> k;
        at[p - 1] |= 1 << i;
        rep(j, k) {
            int f;
            cin >> f;
            pass[f - 1] |= 1 << i;
        }
    }
}

struct state
{
    int v, ved, pass, cost;
    state(int v, int ved, int pass, int cost)
        : v(v), ved(ved), pass(pass), cost(cost) {}
    bool operator <(const state &t) const {
        return cost > t.cost;
    }
};

char ved[1 << 22];

void solve()
{
    memset(ved, 0, sizeof(ved));

    priority_queue<state> q;
    q.push(state(0, 0, 0, 0));
    while (!q.empty()) {
        state cur = q.top();
        q.pop();
        
        if (cur.v == 0 and cur.ved == (1 << k) - 1) {
            cout << cur.cost << endl;
            return;
        }
        if (ved[cur.v << 16 | cur.ved << 8 | cur.pass])
            continue;
        ved[cur.v << 16 | cur.ved << 8 | cur.pass] = 1;

        {
            int npass = (cur.pass | pass[cur.v]) & ~cur.ved;
            q.push(state(cur.v, cur.ved, npass, cur.cost));
        }
        {
            int nved = cur.ved | at[cur.v];
            int npass = cur.pass;
            int ncost = cur.cost;
            rep(i, k) if (~cur.ved >> i & 1 and at[cur.v] >> i & 1) {
                if (npass >> i & 1)
                    ncost += ft[i];
                else
                    ncost += t[i];
            }
            npass &= ~nved;
            q.push(state(cur.v, nved, npass, ncost));
        }
        {
            rep(i, G[cur.v].size()) {
                edge &e = G[cur.v][i];
                q.push(state(e.to, cur.ved, cur.pass, cur.cost + e.w));
            }
        }
    }
}

int main()
{
    int T;
    cin >> T;
    for(int _ = 0; _ < T; _++){
        cout << "Case #" << _+1 << ": ";
        input();
        solve();
    }
    return 0;
}
