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
typedef vector<vector<int> > graph;

const int N = 510;

int n, m, deg[N];
graph G;

void input()
{
    memset(deg, 0, sizeof(deg));

    cin >> n >> m;
    G.assign(n, vector<int>());
    rep(i, m) {
        int a, b;
        cin >> a >> b, --a, --b;
        ++deg[a], ++deg[b];
        G[a].pb(b), G[b].pb(a);
    }
}

int max_deg, hist[N];
vector<vector<int> > A;

vector<int> bfs(int s)
{
    vector<int> dist(n, 1000000);
    queue<int> q;
    dist[s] = 0, q.push(s);
    while (not q.empty()) {
        const int v = q.front();
        q.pop();

        rep(i, G[v].size()) {
            const int nv = G[v][i];
            if (dist[nv] > dist[v] + 1) {
                dist[nv] = dist[v] + 1;
                q.push(nv);
            }
        }
    }
    return dist;
}

void prepare()
{
    memset(hist, 0, sizeof(hist));
    A.clear();

    max_deg = *max_element(deg, deg + n);
    rep(i, n) ++hist[deg[i]];
    rep(i, n) A.pb(bfs(i));
}

vector<pair<int, int> > ans;

void path()
{
    if (hist[1] != 2) return;
    if (hist[2] != n - 2) return;

    if (n >= 3 and n % 2 == 1) {
        ans.pb(mp(1, (n - 3) / 2));
    }
    if (n >= 6 and n % 5 == 1) {
        ans.pb(mp(2, (n - 6) / 5));
        ans.pb(mp(5, (n - 6) / 5));
    }
    if (n >= 4 and n % 3 == 1) {
        ans.pb(mp(7, (n - 4) / 3));
    }
}

void three()
{
    if (not (n >= 6 and n % 5 == 1)) return;
    const int k = (n - 6) / 5;
    const int root = max_element(deg, deg + n) - deg;
    vector<int> hd(n);
    rep(i, n) ++hd[A[root][i]];

    bool can = hd[0] == 1;
    repi(i, 1, k + 2) {
        can &= hd[i] == 3;
    }
    repi(i, k + 2, 2 * k + 3) {
        can &= hd[i] == 2;
    }
    repi(i, 2 * k + 3, n) {
        can &= hd[i] == 0;
    }
    if (can) {
        ans.pb(mp(3, k));
    }
}

void four()
{
    if (not (n >= 5 and n % 4 == 1)) return;
    const int k = (n - 5) / 4;
    const int root = max_element(deg, deg + n) - deg;
    
    vector<int> hd(n);
    rep(i, n) ++hd[A[root][i]];

    bool can = hd[0] == 1;
    repi(i, 1, k + 2) {
        can &= hd[i] == 3;
    }
    repi(i, k + 2, 2 * k + 3) {
        can &= hd[i] == 1;
    }
    repi(i, 2 * k + 3, n) {
        can &= hd[i] == 0;
    }
    if (can) {
        ans.pb(mp(4, k));
    }
}

void three_four()
{
    if (hist[1] != 3) return;
    if (hist[2] != n - 4) return;
    if (hist[3] != 1) return;
 
    three(), four();
}

void zero()
{
    if (hist[2] != n) return;

    if (n >= 6 and n % 6 == 0) {
        ans.pb(mp(0, (n - 6) / 6));
    }
}

void six_nine()
{
    if (hist[1] != 1) return;
    if (hist[2] != n - 2) return;
    if (hist[3] != 1) return;

    if (not (n >= 6 and n % 6 == 0)) return;
    const int k = (n - 6) / 6;
    const int root = min_element(deg, deg + n) - deg;
    vector<int> hd(n);
    rep(i, n) ++hd[A[root][i]];

    bool can = hd[0] == 1;
    repi(i, 1, 2 * k + 3) {
        can &= hd[i] == 1;
    }
    repi(i, 2 * k + 3, 4 * k + 4) {
        can &= hd[i] == 2;
    }
    can &= hd[4 * k + 4] == 1;
    if (can) {
        ans.pb(mp(6, k));
        ans.pb(mp(9, k));
    }
}

void eight()
{
    if (hist[1] != 0) return;
    if (hist[2] != n - 2) return;
    if (hist[3] != 2) return;

    if (not (n >= 6 and n % 7 == 6)) return;
    const int k = (n - 6) / 7;
    const int root = max_element(deg, deg + n) - deg;
    vector<int> hd(n);
    rep(i, n) ++hd[A[root][i]];

    bool can = hd[0] == 1;
    repi(i, 1, k + 2) {
        can &= hd[i] == 3;
    }
    repi(i, k + 2, 2 * k + 2) {
        can &= hd[i] == 4;
    }
    can &= hd[2 * k + 2] == 2;
    if (can) {
        ans.pb(mp(8, k));
    }
}

void solve()
{
    if (max_deg >= 4) return;
    if (hist[0] != 0) return;
    if (hist[3] >= 3) return;

    const int cycle = m - n + 1;
    if (cycle == 0) {
        if (max_deg == 2) {
            path();
        } else if (max_deg == 3) {
            three_four();
        }
    } else if (cycle == 1) {
        if (max_deg == 2) {
            zero();
        } else if (max_deg == 3) {
            six_nine();
        }
    } else if (cycle == 2) {
        eight();
    }
}

int main()
{
    int t;
    cin >> t;
    rep(i, t) {
        if (i) cout << endl;
        cout << "Case " << i + 1 << ": ";

        ans.clear();

        input();
        prepare();
        solve();

        sort(all(ans));
        cout << ans.size() << endl;
        rep(i, ans.size()) {
            cout << ans[i].first << ' ' << ans[i].second << endl;
        }
    }

    return 0;
}
