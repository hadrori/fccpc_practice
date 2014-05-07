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
    int to, cap, rev;
    edge(int to, int cap, int rev)
        : to(to), cap(cap), rev(rev) {}
};

int n, m, s;
vector<vector<edge> > G;

void add_edge(int x, int y, int cap)
{
    G[x].pb(edge(y, cap, G[y].size()));
    G[y].pb(edge(x, cap, G[x].size() - 1));
}

void input()
{
    G.assign(n, vector<edge>());

    rep(i, m) {
        int x, y, k;
        cin >> x >> y >> k, --x, --y;
        add_edge(x, y, k);
    }
}

int inf = (int) 1e9;

vector<int> level, iter;

vector<vector<edge> > G1;

void prepare(int s)
{
    level.assign(n, inf);
    level[s] = 0;
    iter.assign(n, 0);

    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();

        rep(i, G1[v].size()) {
            int nv = G1[v][i].to;
            if (G1[v][i].cap and level[nv] > level[v] + 1) {
                level[nv] = level[v] + 1;
                q.push(nv);
            }
        }
    }
}

int augment(int v, int t, int f)
{
    if (v == t) return f;

    for (; iter[v] < G1[v].size(); ++iter[v]) {
        edge &e = G1[v][iter[v]];
        if (e.cap and level[v] < level[e.to]) {
            int tmp = augment(e.to, t, min(f, e.cap));
            if (tmp > 0) {
                e.cap -= tmp;
                G1[e.to][e.rev].cap += tmp;
                return tmp;
            }
        }
    }

    return 0;
}

int block_flow(int s, int t)
{
    prepare(s);

    int tmp, ret = 0;
    while ((tmp = augment(s, t, inf)) > 0)
        ret += tmp;
    return ret;
}

int max_flow(int s, int t)
{
    int tmp, ret = 0;
    while ((tmp = block_flow(s, t)) > 0)
        ret += tmp;
    return ret;
}

int attempt(int t)
{
    G1 = G;
    return max_flow(s, t);
}

void solve()
{
    int ret = inf;
    rep(i, n) {
        if (i == s)
            continue;
        int tmp = attempt(i);
        ret = min(ret, tmp);
    }
    cout << ret << endl;
}

int main()
{
    while (cin >> n >> m >> s && n) {
        --s, input();
        solve();
    }

    return 0;
}
