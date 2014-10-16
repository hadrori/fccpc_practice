#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(u) begin(u),end(u)
#define uniq(u) (u).erase(unique(all(u)),end(u))

#define ll long
#define long int64_t
#define mp make_pair
#define pb push_back
#define eb emplace_back

const int N = 2014;

int n, x[N], y[N], d[N];

bool affect(int i, int j)
{
    return 2 * abs(x[j] - x[i]) <= d[i] and 2 * abs(y[j] - y[i]) <= d[i];
}

void input()
{
    cin >> n;
    rep(i, n) {
        cin >> x[i] >> y[i] >> d[i];
    }
}

typedef vector<vector<int> > graph;

graph G;

int cnt;
vector<int> num, low, comp_id, ans;
vector<vector<int> > comp;
stack<int> stk;
vector<int> in;

void dfs(int v)
{
    num[v] = low[v] = ++cnt;
    stk.push(v), in[v] = 1;
    for (const int nv : G[v]) {
        if (num[nv] == 0) {
            dfs(nv);
            low[v] = min(low[v], low[nv]);
        } else if (in[nv]) {
            low[v] = min(low[v], low[nv]);
        }
    }
    if (low[v] == num[v]) {
        comp.eb();
        int w;
        do {
            w = stk.top();
            stk.pop(), in[w] = 0;
            comp.back().pb(w);
        } while (w != v);
    }
}

void solve()
{
    G.assign(n, vector<int>());
    rep(i, n) rep(j, n) {
        if (i != j and affect(i, j)) {
            G[i].pb(j);
        }
    }

    cnt = 0;
    num.assign(n, 0);
    low.resize(n);
    comp_id.resize(n);
    comp.clear();
    stk = stack<int>();
    in.assign(n, 0);
    rep(i, n) if (num[i] == 0) {
        dfs(i);
    }

    const int k = comp.size();
    ans.assign(k, 1);
    rep(i, k) for (const int v : comp[i]) {
        comp_id[v] = i;
    }
    rep(i, n) for (const int v : G[i]) {
        if (comp_id[i] != comp_id[v]) {
            ans[comp_id[v]] = 0;
        }
    }
    cout << accumulate(all(ans), 0) << endl;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        input();
        solve();
    }

    return 0;
}
