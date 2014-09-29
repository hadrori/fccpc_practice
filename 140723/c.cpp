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

const int N = 100010;

int n, m, a[N];
vector<ll> adj[N], acc[N];

ll pre = 0;

void prepare()
{
    m = unique(a, a + m) - a;

    rep(i, m) {
        if (i - 1 >= 0) adj[a[i]].pb(a[i - 1]);
        if (i + 1 < m) adj[a[i]].pb(a[i + 1]);
    }
    rep(i, n) sort(all(adj[i]));

    rep(i, n) {
        acc[i].pb(0);
        rep(j, int(adj[i].size())) {
            acc[i].pb(acc[i].back() + adj[i][j]);
        }
    }
}

ll func(int i, ll x)
{
    int pos = lower_bound(all(adj[i]), x) - adj[i].begin();
    ll l = x * pos - acc[i][pos];
    ll r = acc[i].back() - acc[i][pos] - x * (int(acc[i].size()) - pos - 1);
    ll ret = l + r;
    return ret;
}

void solve()
{
    prepare();

    ll pre = 0;
    rep(i, n) rep(j, int(adj[i].size())) {
        pre += abs(i - adj[i][j]);
    }
    pre /= 2;

    ll reduce = 0;
    rep(i, n) rep(j, int(adj[i].size())) {
        ll tmp = func(i, i) - func(i, adj[i][j]);
        reduce = max(reduce, tmp);
    }
    cout << pre - reduce << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    rep(i, m) cin >> a[i], --a[i];

    solve();

    return 0;
}
