#include <algorithm>
#include <bitset>
#include <cassert>
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

const int N = 400;
const int base = 200;

typedef vector<int> die;

int n, h[N][N], top[N][N];

die rotate(die d, int pos[4])
{
    rep(i, 3) swap(d[pos[i]], d[pos[i + 1]]);
    return d;
}

int poss[][4] = {
    {0, 4, 5, 2},
    {0, 1, 5, 3},
    {0, 2, 5, 4},
    {0, 3, 5, 1}
};

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

void drop(int i, int j, die d)
{
    int dir = -1, mx = -1;
    if (h[i][j] > h[i + 1][j] and d[2] > mx) dir = 0, mx = d[2];
    if (h[i][j] > h[i][j + 1] and d[3] > mx) dir = 1, mx = d[3];
    if (h[i][j] > h[i - 1][j] and d[4] > mx) dir = 2, mx = d[4];
    if (h[i][j] > h[i][j - 1] and d[1] > mx) dir = 3, mx = d[1];

    if (dir < 0 or mx <= 3) {
        ++h[i][j], top[i][j] = d[0];
    } else {
        drop(i + dx[dir], j + dy[dir], rotate(d, poss[dir]));
    }
}

void solve()
{
    memset(h, 0, sizeof(h));
    memset(top, 0, sizeof(top));

    rep(i, n) {
        int t, f;
        cin >> t >> f;

        die d;
        d.pb(1);
        d.pb(4);
        d.pb(5);
        d.pb(3);
        d.pb(2);
        d.pb(6);

        rep(i, 4) {
            rep(j, 4) {
                rep(k, 4) {
                    if (d[0] == t and d[3] == f) goto label;
                    d = rotate(d, poss[0]);
                }
                d = rotate(d, poss[1]);
            }
            d = rotate(d, poss[2]);
        }
        assert(d[0] == t and d[3] == f);
    label:
        drop(base, base, d);
    }

    int ans[6] = {};
    rep(i, N) rep(j, N) if (top[i][j]) {
        ++ans[top[i][j] - 1];
    }
    rep(i, 6) cout << ans[i] << (i < 5 ? ' ' : '\n');
}

int main()
{
    while (cin >> n and n) {
        solve();
    }

    return 0;
}
