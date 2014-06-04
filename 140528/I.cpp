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

const int MAX = 1000006;
int par[MAX], rnk[MAX];
void init(int num) {
    rep(i, num) par[i] = i;
    memset(rnk, 0, sizeof(rnk));
}

int find(int x) {
    if(x == par[x]) return x;
    return par[x] = find(par[x]);
}

bool same(int x, int y) {
    return find(x) == find(y);
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(rnk[x] < rnk[y]) {
        par[x] = par[y];
    } else {
        if(rnk[x] == rnk[y]) rnk[x]++;
        par[y] = par[x];
    }
}

int n, m;

bool inrange(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

int a[1005][1005];
void solve() {
    cin >> n >> m;
    init(n*m);
    rep(i, n) rep(j, m) cin >> a[i][j];
    int T;
    cin >> T;
    vector<int> t(T+1);
    rep(i, T) cin >> t[i+1];
    t.pb(1000000000);
    vector<vector<pair<int, int> > >v(T+1);
    rep(i, n) rep(j, m) {
        int ft = lower_bound(all(t), a[i][j]) - t.begin() - 1;
        v[ft].pb(mp(i, j));
    }
    int cnt = 0;
    const int di[] = {-1, 0, 1, 0};
    const int dj[] = { 0,-1, 0, 1};
    vector<int> ans(T);
    vector<bool> done(n*m);
    repd(i, T, 1) {
        rep(j, v[i].size()) {
            cnt++;
            int p = v[i][j].first * m + v[i][j].second;
            done[p] = true;
            rep(k, 4) if(inrange(v[i][j].first + di[k], v[i][j].second + dj[k])) {
                int np = (v[i][j].first + di[k]) * m + (v[i][j].second + dj[k]);
                if(done[np] && !same(p, np)) {
/*                    cout << i << " (" << v[i][j].first << " " << v[i][j].second << ") ";
                    cout << " (" << v[i][j].first + di[k] << " " << v[i][j].second+dj[k] << ") ";
                    cout << k << endl;*/
                    unite(p, np);
                    cnt--;
                }
            }
        }
        ans[i-1] = cnt;
    }
    rep(i, ans.size()) cout << ans[i] << " ";
    cout << endl;
}

int main()
{
    int z;
    cin >> z;
    rep(i, z) {
        solve();
    }
    return 0;
}
