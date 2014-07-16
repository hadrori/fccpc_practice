#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
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

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define repd(i,a,b) for(int i=int(a);i>=int(b);--i)
#define repit(it,u) for(__typeof((u).begin()) it=(u).begin();it!=(u).end();++it)

#define all(u) (u).begin(),(u).end()
#define rall(u) (u).rbegin(),(u).rend()
#define uniq(u) (u).erase(unique(all(u)),(u).end())

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

const int N = 810;

int n, p[N], d[N];

void input()
{
    rep(i, n - 1) cin >> p[i], --p[i];
    rep(i, n - 1) cin >> d[i];
}

struct edge
{
    int to, cost;
    edge(int to, int cost) : to(to), cost(cost) {}
};

vector<int> deg;
vector<vector<edge> > G;

void prepare()
{
    G.assign(n, vector<edge>());
    deg.assign(n, 0);
    rep(i, n - 1) {
        G[i + 1].pb(edge(p[i], d[i]));
        G[p[i]].pb(edge(i + 1, d[i]));
        ++deg[i + 1], ++deg[p[i]];
    }
}

int mem[N][N][2];

int way(int v, int p);

int one_way(int v, int p)
{
    int& ret = mem[v + 1][p + 1][0];
    if (ret >= 0) return ret;

    ret = 0;
    rep(i, G[v].size()) {
        edge& e = G[v][i];
        if (e.to == p) continue;
        if (deg[e.to] == 1) continue;
        ret += way(e.to, v) + 2 * e.cost;
    }
    int reduce = 0;
    rep(i, G[v].size()) {
        edge& e = G[v][i];
        if (e.to == p) continue;
        if (deg[e.to] == 1) continue;
        reduce = max(reduce, way(e.to, v) - one_way(e.to, v) + e.cost);
    }
    ret -= reduce;
    return ret;
}

int way(int v, int p)
{
    int& ret = mem[v + 1][p + 1][1];
    if (ret >= 0) return ret;

    ret = 0;
    rep(i, G[v].size()) {
        edge& e = G[v][i];
        if (e.to == p) continue;
        if (deg[e.to] == 1) continue;
        ret += way(e.to, v) + 2 * e.cost;
    }
    return ret;
}

void solve()
{
    prepare();

    int ans = 1e9;
    rep(i, n) if (deg[i] >= 2) {
        memset(mem, -1, sizeof(mem));
        ans = min(ans, one_way(i, -1));
    }
    rep(i, n - 1) ans += d[i];
    cout << ans << endl;
}

int main()
{
    while (cin >> n and n) {
        input();
        solve();
    }

    return 0;
}
