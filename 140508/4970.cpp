#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>ago
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define repi(i,a,b) for(ll i=(a);i<(b);i++)
#define rep(i,a) repi(i,0,a)
#define repd(i,a,b) for(ll i=(a);i>=(b);i--)
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

#define int long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const ll inf = 1000000000000LL;
int n;

const int MAX_V = 100;
struct edge{ int to, cap, cost, rev;};

int V;
vector<edge> G[MAX_V];
int h[MAX_V];
int dist[MAX_V];
int prevv[MAX_V], preve[MAX_V];

void add_edge(int from, int to, int cap, int cost){
    G[from].push_back((edge){to, cap, cost, (int)(G[to].size())});
    G[to].push_back((edge){from, 0, -cost, (int)(G[from].size() - 1)});
}

int min_cost_flow(int s, int t, int f){
    int res = 0;
    fill(h, h + V, 0);
    while(f > 0LL){
        priority_queue<pii, vector<pii>, greater<pii> > que;
        fill(dist, dist + V, inf);
        dist[s] = 0;
        que.push(pii(0, s));
        while(!que.empty()){
            pii p = que.top(); que.pop();
            int v = p.second;
            if(dist[v] < p.first) continue;
            rep(i,G[v].size()){
                edge &e = G[v][i];
                if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to]){
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    que.push(pii(dist[e.to], e.to));
                }
            }
        }
        if(dist[t] == inf) return -1LL;
        rep(v,V) h[v] += dist[v];
        int d = f;
        for(int v = t; v != s; v = prevv[v])
            d = min(d, G[prevv[v]][preve[v]].cap);
        f -= d;
        res += d * h[t];
        for(int v = t; v != s; v = prevv[v]){
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
    return res;
}

const int MAX_SIZE = 500;
ll memo[MAX_SIZE][MAX_SIZE];

bool inrange(int x, int y) {
    return x >= 0 && x < MAX_SIZE && y >= 0 && y < MAX_SIZE;
}

void gen() {
    memset(memo, -1, sizeof(memo));
    queue<pair<int, pair<int, int> > > q;
    q.push(mp(0, mp(0, 0)));
    const int dx[] = {1, 2, 1, 2,-1,-2,-1,-2};
    const int dy[] = {2, 1,-2,-1, 2, 1,-2,-1};
    while(q.size()) {
        int step = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second; q.pop();
        if(memo[x][y] != -1) continue;
        memo[x][y] = step;
        rep(i, 8) {
            if(inrange(abs(x+dx[i]), abs(y+dy[i])))
                q.push(mp(step+1, mp(abs(x+dx[i]), abs(y+dy[i]))));
        }
    }
}

const ll RANGE = 100;
ll dst(ll dx, ll dy) {
    if(inrange(dx, dy)) return memo[dx][dy];
    
    if(dx < dy) swap(dx, dy);
    ll a, b;
    ll ret = 10000000000LL;

    a = (2*dx - dy)/3;
    b = (2*dy - dx)/3;
    repi(ta, max(0LL, a-RANGE), a+RANGE) repi(tb, max(0LL, b-RANGE), b+RANGE) {
        ll tx = abs(dx - (ta*2+tb)), ty = abs(dy - (ta+tb*2));
        if(inrange(tx, ty)) ret = min(ret, ta+tb+memo[tx][ty]);
    }

    a = (dx + 2*dy)/4;
    b = (dx - 2*dy)/4;
    repi(ta, max(0LL, a-RANGE), a+RANGE) repi(tb, max(0LL, b-RANGE), b+RANGE) {
        ll tx = abs(dx - (ta*2+tb*2)), ty = abs(dy - (ta-tb));
        if(inrange(tx, ty)) ret = min(ret, ta+tb+memo[tx][ty]);
    }
    
    return ret;
}

typedef long long weight;
typedef vector<vector<weight> > matrix;
typedef vector<weight> array;
    
weight hungarian(const matrix &a) {
    int n = a.size(), p, q;
    array fx(n, inf), fy(n, 0);
    vector<int> x(n, -1), y(n, -1);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            fx[i] = max(fx[i], a[i][j]);
    for (int i = 0; i < n; ) {
        vector<int> t(n, -1), s(n+1, i);
        for (p = q = 0; p <= q && x[i] < 0; ++p)
            for (int k = s[p], j = 0; j < n && x[i] < 0; ++j)
                if (fx[k] + fy[j] == a[k][j] && t[j] < 0) {
                    s[++q] = y[j], t[j] = k;
                    if (s[q] < 0)
                        for (p = j; p >= 0; j = p)
                            y[j] = k = t[j], p = x[k], x[k] = j;
                }
        if (x[i] < 0) {
            weight d = inf;
            for (int k = 0; k <= q; ++k)
                for (int j = 0; j < n; ++j)
                    if (t[j] < 0) d = min(d, fx[s[k]] + fy[j] - a[s[k]][j]);
            for (int j = 0; j < n; ++j) fy[j] += (t[j] < 0 ? 0 : d);
            for (int k = 0; k <= q; ++k) fx[s[k]] -= d;
        } else ++i;
    }
    weight ret = 0;
    for (int i = 0; i < n; ++i) ret += a[i][x[i]];
    return ret;
}


int solve() {
    vector<ll> ax(n), ay(n), bx(n), by(n);
    rep(i, n) cin >> ax[i] >> ay[i];
    rep(i, n) cin >> bx[i] >> by[i];

    int s = 2*n, t = s+1; V = t+1;
    rep(i, n) {
        add_edge(s, i, 1, 0);
        add_edge(i+n, t, 1, 0);
    }

    matrix a(n, vector<weight>(n));
    
    rep(i, n) rep(j, n) {
//        add_edge(i, j+n, 1, dst(abs(ax[i]-bx[j]), abs(ay[i]-by[j])));
        a[i][j] = -dst(abs(ax[i] - bx[j]), abs(ay[i] - by[j]));
//        cout << i << " to " << j << " " << dst(abs(ax[i]-bx[j]), abs(ay[i]-by[j])) << endl;
    }
/*    rep(i, n) {
        rep(j, n) cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;*/
    return -hungarian(a);
//    return min_cost_flow(s, t, n);
}

signed main()
{
    gen();
    int cnt = 1;
    while(cin >> n, n) {
        int ans = solve();
        cout << cnt++ << ". ";
        cout << ans << endl;
    }
    return 0;
}
