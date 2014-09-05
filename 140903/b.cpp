#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define repd(i,a,b) for(int i=(int)(a);i>=(int)(b);--i)
#define repit(it,u) for(__typeof((u).begin()) it=(u).begin();it!=(u).end();++it)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair

typedef long long ll;

int n, m, s, t;
vector<vector<int> > G;

void input()
{
    cin >> n >> m >> s >> t, --s, --t;
    G.assign(n, vector<int>());
    rep(i, m) {
        int x, y;
        cin >> x >> y, --x, --y;
        G[x].pb(y);
        G[y].pb(x);
    }
}

const int inf = 1e9;

vector<int> u, v;
int dist;

void bfs(int s, vector<int>& a)
{
    a.assign(n, 0);

    vector<int> d(n, inf);
    d[s] = 0, ++a[0];

    queue<int> q;
    q.push(s);
    while (not q.empty()) {
        int v = q.front();
        q.pop();

        rep(i, int(G[v].size())) {
            int nv = G[v][i];
            if (d[nv] > d[v] + 1) {
                d[nv] = d[v] + 1, ++a[d[nv]];
                if (nv == t) dist = d[nv];
                q.push(nv);
            }
        }
    }
}

void solve()
{
    bfs(t, v);
    bfs(s, u);

    // rep(i, n) cerr << u[i] << ' '; cerr << endl;
    // rep(i, n) cerr << v[i] << ' '; cerr << endl;

    ll ans = 0;
    rep(i, dist - 1) {
        // cerr << i << ' ' << dist - i - 2 << endl;
        ans += (ll) u[i] * v[dist - i - 2];
    }
    cout << ans << endl;
}

int main()
{
    input();
    solve();

    return 0;
}
