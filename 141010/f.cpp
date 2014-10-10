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

struct edge
{
    int to, w;
    edge(int to, int w) : to(to), w(w) {}
};

const int N = 50010;

int n;
vector<vector<edge> > G;
int u[N];

void input()
{
    scanf("%d", &n);
    G.assign(n, vector<edge>());
    rep(i, n - 1) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        G[a - 1].pb(edge(b - 1, w));
        G[b - 1].pb(edge(a - 1, w));
    }
    memset(u, 0, n * sizeof(u[0]));
    int m;
    scanf("%d", &m);
    rep(i, m) {
        int a, f;
        scanf("%d%d", &a, &f);
        u[a - 1] = f;
    }
}

ll sum[N], mem[N];

void recur(int v, int p)
{
    sum[v] = u[v];
    mem[v] = 0;
    rep(i, G[v].size()) {
        const int nv = G[v][i].to;
        if (nv == p) continue;
        recur(nv, v);
        sum[v] += sum[nv];
        mem[v] += mem[nv] + sum[nv] * 2 * G[v][i].w;
    }
}

ll ans[N];

void dfs(int v, ll s, ll t, int p)
{
    // cerr << v << ' ' << s << ' ' << t << endl;

    ans[v] = mem[v] + t;
    rep(i, G[v].size()) {
        const int nv = G[v][i].to;
        if (nv == p) continue;
        ll tmp = mem[v] - mem[nv] - sum[nv] * 2 * G[v][i].w;
        dfs(nv, s + sum[v] - sum[nv], t + (s + sum[v] - sum[nv]) * 2 * G[v][i].w + tmp, v);
    }
}

void solve()
{
    recur(0, -1);
    dfs(0, 0, 0, -1);

    ll cost = *min_element(ans, ans + n);
    printf("%lld\n", cost);
    bool flag = false;
    rep(i, n) {
        if (ans[i] == cost) {
            if (flag) putchar(' ');
            flag = true;
            printf("%d", i + 1);
        }
    }
    puts("");
}

int main()
{
    int t;
    scanf("%d", &t);
    rep(i, t) {
        input();
        solve();
    }

    return 0;
}
